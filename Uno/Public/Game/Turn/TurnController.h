#pragma once
#include <cstdint>
#include <memory>
#include <vector>

#include "Public/Game/ETurnFlow.h"
#include "Public/Game/ITurnHandler.h"

class IMatchHandler;
class Player;

class TurnController : public ITurnHandler
{
public:

    void Initialize(const std::vector<std::shared_ptr<Player>>& InPlayers);
    void ShufflePlayers();
    void PlayTurn(IMatchHandler& MatchHandler);
    void PrepareNextTurn();
    uint32_t GetCurrentTurnIndex() const override;
    const std::shared_ptr<Player>& PeekCurrentPlayer() const override;
    const std::vector<std::shared_ptr<Player>>& GetOrderedPlayers() const override;
    ETurnFlow GetCurrentFlow() const override;

private:

    ETurnFlow CurrentFlow{ETurnFlow::Clockwise};
    uint32_t CurrentTurnIndex{0};
    uint32_t CurrentPlayerIndex{0};
    std::vector<std::shared_ptr<Player>> Players{};

    void SetNextPlayerIndex();
    bool HasCardToUse(const IMatchHandler& MathHandler, const Player& Player);
};
