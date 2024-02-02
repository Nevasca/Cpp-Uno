#include "Public/Game/MatchController.h"

#include <iostream>

#include "Public/Game/Card.h"
#include "Public/Game/Players/HumanPlayer.h"

MatchController::MatchController()
    : DeckController(Board), TurnController(UIController)
{ }

void MatchController::Initialize()
{
    if(bIsInitialized)
    {
        return;
    }

    CreateDebugPlayers();
    TurnController.Initialize(Players);
    DeckController.Initialize(TurnController);
    
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

    ClearMustUseCard();

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
        TurnController.PrepareNextTurn(*this);
    }
}

bool MatchController::IsMatchFinished() const
{
    return bIsMatchFinished;
}

bool MatchController::CanUseCard(const Card& DesiredCard) const
{
    if(MustUseCardId >= 0)
    {
        return DesiredCard.GetId() == MustUseCardId;
    }

    const std::shared_ptr<Card> CurrentCard = Board.PeekCurrentCard();

    if(!CurrentCard)
    {
        return true;
    }

    return DesiredCard.CanStackOn(*CurrentCard);
}

bool MatchController::CanUseAnyCard(const std::vector<std::shared_ptr<Card>>& Cards) const
{
    if(MustUseCardId >= 0)
    {
        for(const std::shared_ptr<Card>& Card : Cards)
        {
            if(Card->GetId() == MustUseCardId)
            {
                return true;
            }
        }

        return false;
    }

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

void MatchController::SetMustUseCard(int16_t CardId)
{
    MustUseCardId = CardId;
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

    Card->Use();
    Board.Stack(std::move(Card));
}

void MatchController::ApplyNoUsableCardPenalty(Player& Player)
{
    std::vector<std::shared_ptr<Card>> PenaltyCards = DeckController.BuyCards(TOTAL_BUY_CARDS_PENALTY);

    Player.SetHasYelledUno(false);

    UIController.ShowNoCardsPenalty(Player, PenaltyCards);

    Player.GiveCards(PenaltyCards);
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
    std::vector<std::shared_ptr<Card>> PenaltyCards = DeckController.BuyCards(TOTAL_BUY_CARDS_UNO_PENALTY);

    UIController.ShowUnoNotYelledPenalty(Player, PenaltyCards);

    Player.GiveCards(PenaltyCards);
}

void MatchController::ClearMustUseCard()
{
    MustUseCardId = -1;
}

void MatchController::BuyCardsFor(Player& Player, uint16_t TotalCards)
{
    std::vector<std::shared_ptr<Card>> BoughtCards = DeckController.BuyCards(TotalCards);

    UIController.ShowBoughtCards(Player, BoughtCards);

    Player.GiveCards(BoughtCards);
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
