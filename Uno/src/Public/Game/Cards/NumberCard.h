#pragma once
#include "Public/Game/Card.h"

class NumberCard : public Card
{
public:

    NumberCard(uint16_t InId, EColor InColor, uint16_t InNumber);
    void Use() override;
    bool CanStackOn(const Card& OtherCard) const override;
    std::string ToShortString() const override;
    ~NumberCard() = default;

private:

    uint16_t Number{0};
};
