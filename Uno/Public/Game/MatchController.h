﻿#pragma once
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

    MatchController();
    void Initialize();
    bool IsInitialized() const;
    void Start();
    void Update();
    bool IsMatchFinished() const;
    bool CanUseCard(const Card& Card) const override;
    bool TryUsingCard(Player& Player, int CardIndex) override;
    bool TryApplyPenalties(Player& Player) override;
    void UseCard(std::shared_ptr<Card>&& Card) override;
    bool TryYellUno(Player& Player) override;
    const std::shared_ptr<Card> PeekCurrentCard() const override;
    void Shutdown();

private:

    static constexpr uint16_t TOTAL_BUY_CARDS_PENALTY = 1;
    static constexpr uint8_t MIN_CARDS_TO_YELL_UNO = 2;
    static constexpr uint8_t REQUIRED_CARDS_UNO_PENALTY = 1;
    static constexpr uint16_t TOTAL_BUY_CARDS_UNO_PENALTY = 2;
    
    std::vector<std::shared_ptr<Player>> Players{};
    bool bIsInitialized{false};
    bool bIsMatchFinished{false};
    DeckController DeckController;
    TurnController TurnController{};
    Board Board{};
    UIController UIController{};

    void CreateDebugPlayers();
    void GiveInitialCardsToPlayers();
    bool CanUseAnyCard(const std::vector<std::shared_ptr<Card>>& Cards) const;
    void ApplyNoUsableCardPenalty(Player& Player);
    bool CanApplyUnoPenalty(const Player& Player) const;
    void ApplyUnoNotYelledPenalty(Player& Player);
};
