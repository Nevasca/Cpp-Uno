#pragma once
#include <memory>
#include <vector>

#include "Cards/DeckController.h"
#include "Turn/TurnController.h"

class Player;

class MatchController
{
public:

    void Initialize();
    bool IsInitialized() const;
    void Start();
    void Update();
    bool IsMatchFinished() const;
    void Shutdown();

private:

    std::vector<std::shared_ptr<Player>> Players{};
    bool bIsInitialized{false};
    bool bIsMatchFinished{false};
    DeckController DeckController{};
    TurnController TurnController{};

    void CreateDebugPlayers();
    void GiveInitialCardsToPlayers();
};
