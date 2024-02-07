#include "Public/Game/Cards/BuyCard.h"

#include "Public/Game/ITurnActionHandler.h"
#include "Public/Game/Cards/Actions/BuyTurnAction.h"

BuyCard::BuyCard(const uint16_t InId, const EColor InColor, ITurnActionHandler& InTurnActionHandler, uint16_t InTotalCardsToBuy)
    : Card(InId, InColor), TurnActionHandler(InTurnActionHandler), TotalCardsToBuy(InTotalCardsToBuy)
{ }

void BuyCard::Use()
{
    TurnActionHandler.AddPreTurnAction(std::make_unique<BuyTurnAction>(TotalCardsToBuy, Id));
}

bool BuyCard::CanStackOn(const Card& OtherCard) const
{
    if(Card::CanStackOn(OtherCard))
    {
        return true;
    }

    return Id == OtherCard.GetId();
}

std::string BuyCard::ToShortString() const
{
    return ConvertColorToString(Color).substr(0, 1) + "+" + std::to_string(TotalCardsToBuy);
}
