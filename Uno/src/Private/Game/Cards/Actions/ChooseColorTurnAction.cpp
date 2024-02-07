#include "Public/Game/Cards/Actions/ChooseColorTurnAction.h"

#include "Public/Game/IMatchHandler.h"

ETurnResult ChooseColorTurnAction::Execute(IMatchHandler& MatchHandler, ITurnHandler& TurnHandler, Player& Player)
{
    MatchHandler.DecideCurrentColor(Player);

    return ETurnResult::Ended;
}
