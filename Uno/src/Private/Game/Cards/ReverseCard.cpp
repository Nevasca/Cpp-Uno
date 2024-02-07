#include "Public/Game/Cards/ReverseCard.h"

#include "Public/Game/ITurnActionHandler.h"
#include "Public/Game/Cards/Actions/ReverseTurnAction.h"

ReverseCard::ReverseCard(const uint16_t InId, const EColor InColor, ITurnActionHandler& InTurnActionHandler)
    : Card(InId, InColor), TurnActionHandler(InTurnActionHandler)
{ }

void ReverseCard::Use()
{
    TurnActionHandler.AddPostTurnAction(std::make_unique<ReverseTurnAction>());
}

bool ReverseCard::CanStackOn(const Card& OtherCard) const
{
    if(Card::CanStackOn(OtherCard))
    {
        return true;
    }

    return Id == OtherCard.GetId();
}

std::string ReverseCard::ToShortString() const
{
    return ConvertColorToString(Color).substr(0, 1) + "RE";
}
