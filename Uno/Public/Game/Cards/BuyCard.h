#pragma once
#include "Public/Game/Card.h"

class ITurnActionHandler;

class BuyCard : public Card
{
public:

    BuyCard(const uint16_t InId, const EColor InColor, ITurnActionHandler& InTurnActionHandler, uint16_t InTotalCardsToBuy);
    void Use() override;
    bool CanStackOn(const Card& OtherCard) const override;
    std::string ToShortString() const override;

private:

    ITurnActionHandler& TurnActionHandler;
    uint16_t TotalCardsToBuy{2};
};
