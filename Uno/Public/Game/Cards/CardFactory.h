#pragma once
#include <memory>

#include "Public/Game/EColor.h"

class ITurnActionHandler;
class Card;

class CardFactory
{
public:

    static constexpr uint16_t NUMBER_CARD_ID = 0;
    static constexpr uint16_t REVERSE_CARD_ID = 1;
    static constexpr uint16_t JUMP_CARD_ID = 2;
    static constexpr uint16_t PLUS_TWO_CARD_ID = 3;
    static constexpr uint16_t WILD_PLUS_FOUR_CARD_ID = 4;
    
    static std::shared_ptr<Card> CreateNumberCard(const EColor InColor, const uint16_t InNumber);
    static std::shared_ptr<Card> CreateReverseCard(const EColor InColor, ITurnActionHandler& InActionHandler);
    static std::shared_ptr<Card> CreateJumpCard(const EColor InColor, ITurnActionHandler& InActionHandler);
    static std::shared_ptr<Card> CreatePlusTwoCard(const EColor InColor, ITurnActionHandler& InActionHandler);
    static std::shared_ptr<Card> CreateWildPlusFourCard(ITurnActionHandler& InActionHandler);
};
