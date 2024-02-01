#include "Public/Game/Cards/CardFactory.h"

#include <memory>

#include "Public/Game/Cards/NumberCard.h"
#include "Public/Game/Cards/ReverseCard.h"

std::shared_ptr<Card> CardFactory::CreateNumberCard(const EColor InColor, const uint16_t InNumber)
{
    return std::make_shared<NumberCard>(NUMBER_CARD_ID, InColor, InNumber);
}

std::shared_ptr<Card> CardFactory::CreateReverseCard(const EColor InColor, ITurnActionHandler& TurnActionHandler)
{
    return std::make_shared<ReverseCard>(REVERSE_CARD_ID, InColor, TurnActionHandler);
}
