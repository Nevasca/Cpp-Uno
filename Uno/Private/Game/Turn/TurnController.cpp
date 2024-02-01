#include "Public/Game/Turn/TurnController.h"

#include <algorithm>
#include <cassert>

#include "Public/Core/Random.h"
#include "Public/Game/IMatchHandler.h"
#include "Public/Game/Player.h"

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

    const bool bHasPenalties = MatchHandler.TryApplyPenalties(*CurrentPlayer);
    
    if(!bHasPenalties)
    {
        CurrentPlayer->PlayTurn(MatchHandler);    
    }
}

void TurnController::PrepareNextTurn()
{
    CurrentTurnIndex++;
    SetNextPlayerIndex();
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
