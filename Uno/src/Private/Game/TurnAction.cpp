#include "Public/Game/TurnAction.h"

bool TurnAction::CanAccumulate(const TurnAction& OtherAction) const
{
    return false;
}

void TurnAction::Accumulate(const TurnAction& OtherAction)
{ }
