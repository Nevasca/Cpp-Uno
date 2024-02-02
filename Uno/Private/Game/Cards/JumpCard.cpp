#include "Public/Game/Cards/JumpCard.h"

#include "Public/Game/ITurnActionHandler.h"
#include "Public/Game/Cards/Actions/JumpTurnAction.h"

JumpCard::JumpCard(const uint16_t InId, const EColor InColor, ITurnActionHandler& InTurnActionHandler)
    : Card(InId, InColor), TurnActionHandler(InTurnActionHandler)
{ }

void JumpCard::Use()
{
    TurnActionHandler.AddPreTurnAction(std::make_unique<JumpTurnAction>());
}

bool JumpCard::CanStackOn(const Card& OtherCard) const
{
    if(Card::CanStackOn(OtherCard))
    {
        return true;
    }

    return Id == OtherCard.GetId();
}

std::string JumpCard::ToShortString() const
{
    return ConvertColorToString(Color).substr(0, 1) + "JP";
}
