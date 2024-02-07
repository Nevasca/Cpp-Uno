#include "Public/Game/Turn/TurnController.h"

#include <algorithm>
#include <cassert>

#include "Public/Core/Random.h"
#include "Public/Game/IMatchHandler.h"
#include "Public/Game/ITurnEventListener.h"
#include "Public/Game/Player.h"

TurnController::TurnController(ITurnEventListener& InEventListener)
    : EventLister(InEventListener)
{ }

void TurnController::Initialize(const std::vector<std::shared_ptr<Player>>& InPlayers)
{
    assert(!InPlayers.empty());

    Players = InPlayers;
}

void TurnController::ShufflePlayers()
{
    std::shuffle(Players.begin(), Players.end(), Random::GetRandomEngine());
}

void TurnController::PlayTurn(IMatchHandler& MatchHandler)
{
    std::shared_ptr<Player>& CurrentPlayer = Players[CurrentPlayerIndex];

    const ETurnResult PreTurnResult = ExecutePreTurnAction(MatchHandler, *CurrentPlayer);

    if(PreTurnResult == ETurnResult::Ended)
    {
        return;
    }
    
    const bool bHasPenalties = MatchHandler.TryApplyPenalties(*CurrentPlayer);
    
    if(!bHasPenalties)
    {
        CurrentPlayer->PlayTurn(MatchHandler);    
    }
}

ETurnResult TurnController::ExecutePreTurnAction(IMatchHandler& MatchHandler, Player& CurrentPlayer)
{
    if(!PreTurnAction)
    {
        return ETurnResult::Running;
    }

    const ETurnResult TurnResult = PreTurnAction->Execute(MatchHandler, *this, CurrentPlayer);

    if(TurnResult == ETurnResult::Ended)
    {
        PreTurnAction.reset();
    }

    return TurnResult;
}

void TurnController::PrepareNextTurn(IMatchHandler& MatchHandler)
{
    ExecutePostTurnAction(MatchHandler, *Players[CurrentPlayerIndex]);
    
    CurrentTurnIndex++;
    SetNextPlayerIndex();
}

ETurnResult TurnController::ExecutePostTurnAction(IMatchHandler& MatchHandler, Player& Player)
{
    if(!PostTurnAction)
    {
        return ETurnResult::Running;
    }

    const ETurnResult TurnResult = PostTurnAction->Execute(MatchHandler, *this, Player);

    if(TurnResult == ETurnResult::Ended)
    {
        PostTurnAction.reset();
    }

    return TurnResult;
}

void TurnController::SetNextPlayerIndex()
{
    const int TotalPlayers = static_cast<int>(Players.size());
    
    if(CurrentFlow == ETurnFlow::Clockwise)
    {
        CurrentPlayerIndex = (CurrentPlayerIndex + 1) % TotalPlayers;
    }
    else
    {
        CurrentPlayerIndex = (CurrentPlayerIndex - 1 + TotalPlayers) % TotalPlayers;
    }
}

uint32_t TurnController::GetCurrentTurnIndex() const
{
    return CurrentTurnIndex;
}

const std::shared_ptr<Player>& TurnController::PeekCurrentPlayer() const
{
    return Players[CurrentPlayerIndex];
}

const std::vector<std::shared_ptr<Player>>& TurnController::GetOrderedPlayers() const
{
    return Players;
}

ETurnFlow TurnController::GetCurrentFlow() const
{
    return CurrentFlow;
}

void TurnController::ReverseFlow()
{
    CurrentFlow = CurrentFlow == ETurnFlow::Clockwise ? ETurnFlow::Counterclockwise : ETurnFlow::Clockwise;

    EventLister.HandleTurnFlowReversed();
}

void TurnController::JumpTurn()
{
    EventLister.HandleTurnJumped(*Players[CurrentPlayerIndex]);
}

void TurnController::AddPreTurnAction(std::unique_ptr<TurnAction>&& InAction)
{
    if(PreTurnAction && PreTurnAction->CanAccumulate(*InAction))
    {
        PreTurnAction->Accumulate(*InAction);
    }
    else
    {
        PreTurnAction = std::move(InAction);
    }
}

void TurnController::AddPostTurnAction(std::unique_ptr<TurnAction>&& InAction)
{
    if(PostTurnAction && PostTurnAction->CanAccumulate(*InAction))
    {
        PostTurnAction->Accumulate(*InAction);
    }
    else
    {
        PostTurnAction = std::move(InAction);
    }
}
