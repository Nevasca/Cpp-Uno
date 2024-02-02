#include "Public/Game/Cards/Actions/BuyTurnAction.h"

#include <cassert>

#include "Public/Game/Card.h"
#include "Public/Game/IMatchHandler.h"
#include "Public/Game/Player.h"

BuyTurnAction::BuyTurnAction(uint16_t InTotalCardsToBuy, int16_t InCounterCardId)
    : TurnAction(), TotalCardsToBuy(InTotalCardsToBuy), CounterCardId(InCounterCardId)
{ }

ETurnResult BuyTurnAction::Execute(IMatchHandler& MatchHandler, ITurnHandler& TurnHandler, Player& Player)
{
    if(CounterCardId >= 0)
    {
        MatchHandler.SetMustUseCard(CounterCardId);

        if(MatchHandler.CanUseAnyCard(Player.GetCards()))
        {
            return ETurnResult::Running;
        }
    }

    MatchHandler.BuyCardsFor(Player, TotalCardsToBuy);    

    return ETurnResult::Ended;
}

bool BuyTurnAction::CanAccumulate(const TurnAction& OtherAction) const
{
    return CounterCardId && dynamic_cast<const BuyTurnAction*>(&OtherAction);
}

void BuyTurnAction::Accumulate(const TurnAction& OtherAction)
{
    const BuyTurnAction* OtherBuyTurnAction = dynamic_cast<const BuyTurnAction*>(&OtherAction);

    assert(OtherBuyTurnAction);

    TotalCardsToBuy += OtherBuyTurnAction->TotalCardsToBuy;
}
