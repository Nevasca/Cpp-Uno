#pragma once
#include "Public/Game/Card.h"

class ITurnActionHandler;

class WildBuyCard : public Card
{
public:

    WildBuyCard(const uint16_t InId, ITurnActionHandler& InTurnActionHandler, uint16_t InTotalCardsToBuy);
    void Use() override;
    std::string ToShortString() const override;

private:

    ITurnActionHandler& TurnActionHandler;
    uint16_t TotalCardsToBuy{4};
};
