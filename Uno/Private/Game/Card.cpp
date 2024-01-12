#include "Public/Game/Card.h"


Card::Card(const uint16_t InId, const EColor InColor)
    : Id(InId), Color(InColor)
{ }

EColor Card::GetColor() const
{
    return Color;
}

void Card::SetColor(const EColor InColor)
{
    Color = InColor;
}

uint16_t Card::GetId() const
{
    return Id;
}

bool Card::CanStackOn(const Card& OtherCard) const
{
    return Color == OtherCard.GetColor() || Color == EColor::Wild;
}
