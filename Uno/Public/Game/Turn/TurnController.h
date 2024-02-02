#pragma once
#include <cstdint>
#include <memory>
#include <vector>

#include "Public/Game/ETurnFlow.h"
#include "Public/Game/ITurnActionHandler.h"
#include "Public/Game/ITurnHandler.h"

class ITurnEventListener;
class IMatchHandler;
class Player;

class TurnController : public ITurnHandler, public ITurnActionHandler
{
public:

    TurnController(ITurnEventListener& InEventListener);
    void Initialize(const std::vector<std::shared_ptr<Player>>& InPlayers);
    void ShufflePlayers();
    void PlayTurn(IMatchHandler& MatchHandler);
    void PrepareNextTurn(IMatchHandler& MatchHandler);
    uint32_t GetCurrentTurnIndex() const override;
    const std::shared_ptr<Player>& PeekCurrentPlayer() const override;
    const std::vector<std::shared_ptr<Player>>& GetOrderedPlayers() const override;
    ETurnFlow GetCurrentFlow() const override;
    void ReverseFlow() override;
    void JumpTurn() override;
    void AddPreTurnAction(std::unique_ptr<TurnAction>&& InAction) override;
    void AddPostTurnAction(std::unique_ptr<TurnAction>&& InAction) override;

private:

    ETurnFlow CurrentFlow{ETurnFlow::Clockwise};
    uint32_t CurrentTurnIndex{0};
    uint32_t CurrentPlayerIndex{0};
    std::vector<std::shared_ptr<Player>> Players{};
    std::unique_ptr<TurnAction> PreTurnAction{};
    std::unique_ptr<TurnAction> PostTurnAction{};
    ITurnEventListener& EventLister;

    void SetNextPlayerIndex();
    ETurnResult ExecutePreTurnAction(IMatchHandler& MatchHandler, Player& Player);
    ETurnResult ExecutePostTurnAction(IMatchHandler& MatchHandler, Player& Player);
};
