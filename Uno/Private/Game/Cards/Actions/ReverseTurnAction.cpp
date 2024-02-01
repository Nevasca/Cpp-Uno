#include "Public/Game/Cards/Actions/ReverseTurnAction.h"

#include "Public/Game/ITurnHandler.h"

ETurnResult ReverseTurnAction::Execute(IMatchHandler& MatchHandler, ITurnHandler& TurnHandler, Player& Player)
{
    TurnHandler.ReverseFlow();

    return ETurnResult::Ended;
}
