#pragma once
#include "Public/Game/TurnAction.h"

class ReverseTurnAction : public TurnAction
{
public:

    ETurnResult Execute(IMatchHandler& MatchHandler, ITurnHandler& TurnHandler, Player& Player) override;
};
