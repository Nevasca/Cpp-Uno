#pragma once
#include <cstdint>
#include <memory>
#include <vector>

#include "ETurnFlow.h"

class Player;

class TurnController
{
public:

    TurnController(const std::vector<std::shared_ptr<Player>>& InPlayers);
    void PlayTurn();
    void PrepareNextTurn();
    uint32_t GetCurrentTurnIndex() const;
    const std::shared_ptr<Player>& PeekCurrentPlayer() const;

private:

    ETurnFlow CurrentFlow{ETurnFlow::Clockwise};
    uint32_t CurrentTurnIndex{0};
    uint32_t CurrentPlayerIndex{0};
    std::vector<std::shared_ptr<Player>> Players{};

    void SetNextPlayerIndex();
};
