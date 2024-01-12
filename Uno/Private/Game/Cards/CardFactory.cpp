#include "Public/Game/Cards/CardFactory.h"

#include <memory>

#include "Public/Game/Cards/NumberCard.h"

std::shared_ptr<Card> CardFactory::CreateNumberCard(EColor InColor, uint16_t InNumber)
{
    return std::make_shared<NumberCard>(NUMBER_CARD_ID, InColor, InNumber);
}
