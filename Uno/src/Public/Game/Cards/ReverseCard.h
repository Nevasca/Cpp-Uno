#pragma once
#include "Public/Game/Card.h"

class ITurnActionHandler;

class ReverseCard : public Card
{
public:

    ReverseCard(const uint16_t InId, const EColor InColor, ITurnActionHandler& InTurnActionHandler);
    void Use() override;
    bool CanStackOn(const Card& OtherCard) const override;
    std::string ToShortString() const override;

private:

    ITurnActionHandler& TurnActionHandler;
};
