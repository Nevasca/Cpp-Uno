#pragma once
#include <memory>

#include "Public/Game/EColor.h"

class Card;

class CardFactory
{
public:

    static constexpr uint16_t NUMBER_CARD_ID = 0;
    
    static std::shared_ptr<Card> CreateNumberCard(EColor InColor, uint16_t InNumber);
};
