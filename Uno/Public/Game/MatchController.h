#pragma once
#include <memory>
#include <vector>

#include "IMatchHandler.h"
#include "Cards/DeckController.h"
#include "Match/Board.h"
#include "Turn/TurnController.h"
#include "UI/UIController.h"

class Player;

class MatchController : public IMatchHandler
{
public:

    void Initialize();
    bool IsInitialized() const;
    void Start();
    void Update();
    bool IsMatchFinished() const;
    bool CanUseCard(const Card& Card) const override;
    void UseCard(std::shared_ptr<Card>&& Card) override;
    const std::shared_ptr<Card> PeekCurrentCard() const override;
    void Shutdown();

private:

    std::vector<std::shared_ptr<Player>> Players{};
    bool bIsInitialized{false};
    bool bIsMatchFinished{false};
    DeckController DeckController{};
    TurnController TurnController{};
    Board Board{};
    UIController UIController{};

    void CreateDebugPlayers();
    void GiveInitialCardsToPlayers();
};
