#pragma once
#include <cstdint>

#include "EColor.h"
#include "Public/Core/Core.h"

class Card
{

public:

    EColor GetColor() const;
    void SetColor(EColor InColor);
    uint16_t GetId() const;
    virtual bool CanStackOn(const Card& OtherCard) const;
    virtual void Use() = 0;
    virtual ~Card() = default;

    NO_COPY_MOVE(Card)

protected:

    uint16_t Id{0};
    EColor Color{EColor::Blue};
    
    Card() = default;
    Card(uint16_t InId, EColor InColor);
};
