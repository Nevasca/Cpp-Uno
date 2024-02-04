#include "Public/Game/Cards/CardFactory.h"

#include <memory>

#include "Public/Game/Cards/BuyCard.h"
#include "Public/Game/Cards/JumpCard.h"
#include "Public/Game/Cards/NumberCard.h"
#include "Public/Game/Cards/ReverseCard.h"
#include "Public/Game/Cards/WildBuyCard.h"

std::shared_ptr<Card> CardFactory::CreateNumberCard(const EColor InColor, const uint16_t InNumber)
{
    return std::make_shared<NumberCard>(NUMBER_CARD_ID, InColor, InNumber);
}

std::shared_ptr<Card> CardFactory::CreateReverseCard(const EColor InColor, ITurnActionHandler& InActionHandler)
{
    return std::make_shared<ReverseCard>(REVERSE_CARD_ID, InColor, InActionHandler);
}

std::shared_ptr<Card> CardFactory::CreateJumpCard(const EColor InColor, ITurnActionHandler& InActionHandler)
{
    return std::make_shared<JumpCard>(JUMP_CARD_ID, InColor, InActionHandler);
}

std::shared_ptr<Card> CardFactory::CreatePlusTwoCard(const EColor InColor, ITurnActionHandler& InActionHandler)
{
    return std::make_shared<BuyCard>(PLUS_TWO_CARD_ID, InColor, InActionHandler, 2);
}

std::shared_ptr<Card> CardFactory::CreateWildPlusFourCard(ITurnActionHandler& InActionHandler)
{
    return std::make_shared<WildBuyCard>(WILD_PLUS_FOUR_CARD_ID, InActionHandler, 4);
}
