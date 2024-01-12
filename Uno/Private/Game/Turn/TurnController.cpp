#include "Public/Game/Turn/TurnController.h"

#include <assert.h>

#include "Public/Game/Player.h"

TurnController::TurnController(const std::vector<std::shared_ptr<Player>>& InPlayers)
    : Players(InPlayers)
{
    assert(!InPlayers.empty());
}

void TurnController::PlayTurn()
{
    Players[CurrentPlayerIndex]->PlayTurn();
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
