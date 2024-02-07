#include "Public/Game/Cards/DeckData.h"

std::vector<EColor> DeckData::GetAvailableNormalColors()
{
    return std::vector<EColor> { EColor::Blue, EColor::Yellow, EColor::Red, EColor::Green };
}

uint32_t DeckData::GetTotalCards()
{
    const uint32_t TotalNormalColors = static_cast<uint32_t>(GetAvailableNormalColors().size());

    uint32_t TotalCards = (MIN_NUMBER_CARD_NUMBER + MAX_NUMBER_CARD_NUMBER + 1) * TotalNormalColors * NUMBER_CARDS_PER_COLOR;
    TotalCards += PLUS_TWO_CARDS_PER_COLOR * TotalNormalColors;
    TotalCards += REVERSE_CARDS_PER_COLOR * TotalNormalColors;
    TotalCards += JUMP_CARDS_PER_COLOR * TotalNormalColors;
    TotalCards += WILD_PLUS_FOUR_CARDS;
    
    return TotalCards;
}
