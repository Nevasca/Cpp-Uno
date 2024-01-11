#pragma once
#include <cstdint>

#include "EColor.h"

class Card
{

public:

    EColor GetColor() const;
    void SetColor(EColor InColor);
    uint16_t GetId() const;
    virtual bool CanStackOn(const Card& OtherCard) const;
    virtual void Use() = 0;
    Card(const Card& Other) = delete;
    Card& operator = (const Card& Other) = delete;
    Card(Card&& Other) = delete;
    Card& operator = (Card&& other) = delete;
    virtual ~Card() = default;

protected:

    Card() = default;

private:

    uint16_t Id{0};
    EColor Color{EColor::Blue};
};
