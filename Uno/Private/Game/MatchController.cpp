#include "Public/Game/MatchController.h"

#include <iostream>

#include "Public/Game/Card.h"
#include "Public/Game/Players/HumanPlayer.h"

MatchController::MatchController()
    : DeckController(Board)
{ }

void MatchController::Initialize()
{
    if(bIsInitialized)
    {
        return;
    }

    CreateDebugPlayers();
    DeckController.Initialize();
    TurnController.Initialize(Players);
    
    bIsInitialized = true;
}

bool MatchController::IsInitialized() const
{
    return bIsInitialized;
}

void MatchController::Start()
{
    DeckController.ShuffleCards();
    GiveInitialCardsToPlayers();
    TurnController.ShufflePlayers();
}

void MatchController::Update()
{
    const std::shared_ptr<Player> CurrentPlayer = TurnController.PeekCurrentPlayer();

    UIController.Clear();
    UIController.ShowCurrentTurn(*this, TurnController);
    UIController.ShowPlayerHand(*this, *CurrentPlayer);
    UIController.ShowAvailableCommands();

    TurnController.PlayTurn(*this);

    if(HasPlayerWon(*CurrentPlayer))
    {
        FinishMatchWithWinner(CurrentPlayer);
    }
    else
    {
        TurnController.PrepareNextTurn();
    }
}

bool MatchController::IsMatchFinished() const
{
    return bIsMatchFinished;
}

bool MatchController::CanUseCard(const Card& DesiredCard) const
{
    const std::shared_ptr<Card> CurrentCard = Board.PeekCurrentCard();

    if(!CurrentCard)
    {
        return true;
    }

    return DesiredCard.CanStackOn(*CurrentCard);
}

bool MatchController::CanUseAnyCard(const std::vector<std::shared_ptr<Card>>& Cards) const
{
    const std::shared_ptr<Card> CurrentCard = Board.PeekCurrentCard();

    if(!CurrentCard)
    {
        return true;
    }

    for(const std::shared_ptr<Card>& Card : Cards)
    {
        if(Card->CanStackOn(*CurrentCard))
        {
            return true;
        }
    }

    return false;
}

bool MatchController::TryUsingCard(Player& Player, int CardIndex)
{
    if(CardIndex < 0 || CardIndex >= static_cast<int>(Player.GetTotalCards()))
    {
        UIController.ShowInvalidCardWarning();
        return false;
    }

    if(CanUseCard(Player.PeekCard(CardIndex)))
    {
        UseCard(Player.TakeCard(CardIndex));
        return true;
    }

    UIController.ShowCantUseCardWarning();

    return false;
}

bool MatchController::TryApplyPenalties(Player& Player)
{
    if(!CanUseAnyCard(Player.GetCards()))
    {
        ApplyNoUsableCardPenalty(Player);
        return true;
    }

    if(CanApplyUnoPenalty(Player))
    {
        ApplyUnoNotYelledPenalty(Player);
        return true;
    }
    
    return false;
}

void MatchController::UseCard(std::shared_ptr<Card>&& Card)
{
    UIController.ShowUsedCard(*Card, *TurnController.PeekCurrentPlayer());
    
    Board.Stack(std::move(Card));
}

void MatchController::ApplyNoUsableCardPenalty(Player& Player)
{
    std::vector<std::shared_ptr<Card>> PenaltyCards{};
    PenaltyCards.reserve(TOTAL_BUY_CARDS_PENALTY);
    
    for(int i = 0; i < TOTAL_BUY_CARDS_PENALTY; i++)
    {
        PenaltyCards.emplace_back(DeckController.BuyCard());    
    }

    Player.SetHasYelledUno(false);

    UIController.ShowNoCardsPenalty(Player, PenaltyCards);

    for(std::shared_ptr<Card>& Card : PenaltyCards)
    {
        Player.GiveCard(std::move(Card));
    }
}

bool MatchController::TryYellUno(Player& Player)
{
    if(Player.GetTotalCards() > MIN_CARDS_TO_YELL_UNO)
    {
        UIController.ShowMinCardsForUnoWarning(MIN_CARDS_TO_YELL_UNO);
        return false;
    }

    if(Player.HasYelledUno())
    {
        UIController.ShowAlreadyYelledUnoWarning();
        return false;
    }

    Player.SetHasYelledUno(true);

    UIController.ShowUnoYell();
    return true;
}

bool MatchController::CanApplyUnoPenalty(const Player& Player) const
{
    return Player.GetTotalCards() == REQUIRED_CARDS_UNO_PENALTY && !Player.HasYelledUno();
}

void MatchController::ApplyUnoNotYelledPenalty(Player& Player)
{
    std::vector<std::shared_ptr<Card>> PenaltyCards{};
    PenaltyCards.reserve(TOTAL_BUY_CARDS_UNO_PENALTY);
    
    for(int i = 0; i < TOTAL_BUY_CARDS_UNO_PENALTY; i++)
    {
        PenaltyCards.emplace_back(DeckController.BuyCard());    
    }

    UIController.ShowUnoNotYelledPenalty(Player, PenaltyCards);

    for(std::shared_ptr<Card>& Card : PenaltyCards)
    {
        Player.GiveCard(std::move(Card));
    }
}

bool MatchController::HasPlayerWon(const Player& Player) const
{
    return Player.GetTotalCards() == 0;
}

void MatchController::FinishMatchWithWinner(const std::shared_ptr<Player>& InWinner)
{
    Winner = InWinner;
    bIsMatchFinished = true;
}

const std::shared_ptr<Card> MatchController::PeekCurrentCard() const
{
    return Board.PeekCurrentCard();
}

const std::shared_ptr<Player>& MatchController::GetWinner() const
{
    return Winner;
}

void MatchController::Shutdown()
{
    if(!bIsInitialized)
    {
        return;
    }

    UIController.Clear();
}

void MatchController::CreateDebugPlayers()
{
    Players.clear();
    Players.reserve(3);
    
    Players.emplace_back(std::make_shared<HumanPlayer>("Yosuke"));
    Players.emplace_back(std::make_shared<HumanPlayer>("Chie"));
    Players.emplace_back(std::make_shared<HumanPlayer>("Yukiko"));
}

void MatchController::GiveInitialCardsToPlayers()
{
    for(std::shared_ptr<Player>& Player : Players)
    {
        constexpr int TotalInitialCardsPerPlayer = 7;
        
        std::vector<std::shared_ptr<Card>> InitialCards{};
        InitialCards.reserve(TotalInitialCardsPerPlayer);

        for(int i = 0; i < TotalInitialCardsPerPlayer; i++)
        {
            InitialCards.emplace_back(DeckController.BuyCard());
        }

        Player->SetCards(std::move(InitialCards));
    }
}
