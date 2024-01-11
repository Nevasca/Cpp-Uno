#include "Public/Game/Cards/NumberCard.h"

NumberCard::NumberCard(uint16_t InId, EColor InColor, uint16_t InNumber)
    : Card(InId, InColor), Number(InNumber)
{ }

void NumberCard::Use()
{ }

bool NumberCard::CanStackOn(const Card& OtherCard) const
{
    if(Card::CanStackOn(OtherCard))
    {
        return true;
    }

    if(Id != OtherCard.GetId())
    {
        return false;
    }

    const NumberCard* OtherNumberCard = dynamic_cast<const NumberCard*>(&OtherCard);

    return OtherNumberCard != nullptr && Number == OtherNumberCard->Number;
}
