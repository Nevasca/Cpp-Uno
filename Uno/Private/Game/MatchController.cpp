#include "Public/Game/MatchController.h"

#include <iostream>

#include "Public/Game/Card.h"
#include "Public/Game/Players/HumanPlayer.h"

MatchController::MatchController()
    : DeckController(Board), TurnController(UIController)
{ }

void MatchController::Initialize(std::vector<std::string>& PlayerNames)
{
    if(bIsInitialized)
    {
        return;
    }

    CreatePlayers(PlayerNames);
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

void MatchController::DecideCurrentColor(Player& Player)
{
    UIController.ShowChooseColor(DeckController.GetAvailableNormalColors());

    Player.ChooseColor(*this);
}

bool MatchController::TrySetCurrentColor(uint8_t ColorId)
{
    std::vector<EColor> AvailableColors = DeckController.GetAvailableNormalColors();

    EColor ChosenColor;
    
    if(!TryUIntToColor(ColorId, ChosenColor) ||
        !CanChooseColor(ChosenColor, AvailableColors))
    {
        UIController.ShowInvalidColorWarning();
        return false;
    }

    Board.SetCurrentCardColor(ChosenColor);
    UIController.ShowCardColorChanged(ChosenColor);
    
    return true;
}

bool MatchController::CanChooseColor(EColor Color, const std::vector<EColor>& AvailableColors) const
{
    for(const EColor AvailableColor : AvailableColors)
    {
       if(Color == AvailableColor)
       {
           return true;
       }
    }

    return false;
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
    bIsInitialized = false;
}

void MatchController::CreatePlayers(std::vector<std::string>& Names)
{
    Players.clear();
    Players.reserve(Names.size());

    for(std::string& Name : Names)
    {
        Players.emplace_back(std::make_shared<HumanPlayer>(std::move(Name)));
    }
}

void MatchController::GiveInitialCardsToPlayers()
{
    for(std::shared_ptr<Player>& Player : Players)
    {
        std::vector<std::shared_ptr<Card>> InitialCards{};
        InitialCards.reserve(INITIAL_CARDS_PER_PLAYER);

        for(int i = 0; i < INITIAL_CARDS_PER_PLAYER; i++)
        {
            InitialCards.emplace_back(DeckController.BuyCard());
        }

        Player->SetCards(std::move(InitialCards));
    }
}
