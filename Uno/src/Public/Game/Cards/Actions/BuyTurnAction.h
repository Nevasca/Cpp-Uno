#pragma once
#include "Public/Game/TurnAction.h"

class BuyTurnAction : public TurnAction
{
public:

    BuyTurnAction(uint16_t InTotalCardsToBuy, int16_t InCounterCardId = -1);
    ETurnResult Execute(IMatchHandler& MatchHandler, ITurnHandler& TurnHandler, Player& Player) override;
    bool CanAccumulate(const TurnAction& OtherAction) const override;
    void Accumulate(const TurnAction& OtherAction) override;

private:

    uint16_t TotalCardsToBuy{2};
    int16_t CounterCardId{-1};
};
