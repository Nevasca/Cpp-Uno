#pragma once
#include <cstdint>
#include <vector>

#include "Public/Game/EColor.h"

class DeckData
{
public:

    static constexpr uint16_t MIN_NUMBER_CARD_NUMBER = 0;
    static constexpr uint16_t MAX_NUMBER_CARD_NUMBER = 9;
    static constexpr uint32_t NUMBER_CARDS_PER_COLOR = 2;
    static constexpr uint32_t PLUS_TWO_CARDS_PER_COLOR = 2;
    static constexpr uint32_t REVERSE_CARDS_PER_COLOR = 2;
    static constexpr uint32_t JUMP_CARDS_PER_COLOR = 2;
    static constexpr uint32_t WILD_PLUS_FOUR_CARDS = 4;

    static std::vector<EColor> GetAvailableNormalColors();
    static uint32_t GetTotalCards();
};
