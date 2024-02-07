#include "Public/Game/Cards/WildBuyCard.h"

#include "Public/Game/ITurnActionHandler.h"
#include "Public/Game/Cards/Actions/BuyTurnAction.h"
#include "Public/Game/Cards/Actions/ChooseColorTurnAction.h"

WildBuyCard::WildBuyCard(const uint16_t InId, ITurnActionHandler& InTurnActionHandler, uint16_t InTotalCardsToBuy)
    : Card(InId, EColor::Wild), TurnActionHandler(InTurnActionHandler), TotalCardsToBuy(InTotalCardsToBuy)
{ }

void WildBuyCard::Use()
{
    TurnActionHandler.AddPreTurnAction(std::make_unique<BuyTurnAction>(TotalCardsToBuy, -1));
    TurnActionHandler.AddPostTurnAction(std::make_unique<ChooseColorTurnAction>());
}

std::string WildBuyCard::ToShortString() const
{
    return "W+" + std::to_string(TotalCardsToBuy);
}
