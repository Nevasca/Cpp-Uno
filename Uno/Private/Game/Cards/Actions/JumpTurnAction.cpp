#include "Public/Game/Cards/Actions/JumpTurnAction.h"

#include "Public/Game/ITurnHandler.h"

ETurnResult JumpTurnAction::Execute(IMatchHandler& MatchHandler, ITurnHandler& TurnHandler, Player& Player)
{
    TurnHandler.JumpTurn();

    return ETurnResult::Ended;
}
