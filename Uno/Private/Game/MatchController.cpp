#include "Public/Game/MatchController.h"

#include <iostream>

#include "Public/Game/Card.h"
#include "Public/Game/Players/HumanPlayer.h"

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
    UIController.Clear();
    UIController.ShowCurrentTurn(*this, TurnController);
    UIController.ShowPlayerHand(*this, *TurnController.PeekCurrentPlayer());
    UIController.ShowAvailableCommands();

    TurnController.PlayTurn(*this);
    TurnController.PrepareNextTurn();
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

void MatchController::UseCard(std::shared_ptr<Card>&& Card)
{
    UIController.ShowUsedCard(*Card, *TurnController.PeekCurrentPlayer());
    
    Board.Stack(std::move(Card));
}

const std::shared_ptr<Card> MatchController::PeekCurrentCard() const
{
    return Board.PeekCurrentCard();
}

void MatchController::Shutdown()
{
    if(!bIsInitialized)
    {
        return;
    }
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
