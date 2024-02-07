#pragma once
#include "ETurnResult.h"
#include "Public/Core/Core.h"

class Player;
class ITurnHandler;
class IMatchHandler;

class TurnAction
{
public:

    virtual ETurnResult Execute(IMatchHandler& MatchHandler, ITurnHandler& TurnHandler, Player& Player) = 0;
    virtual bool CanAccumulate(const TurnAction& OtherAction) const;
    virtual void Accumulate(const TurnAction& OtherAction);
    virtual ~TurnAction() = default;
    
    NO_COPY_MOVE(TurnAction)

protected:

    TurnAction() = default;
};
