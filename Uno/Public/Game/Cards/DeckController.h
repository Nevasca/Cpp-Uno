#pragma once
#include <memory>
#include <vector>

#include "Public/Game/EColor.h"

class ITurnActionHandler;
class IHasCard;
class Card;

class DeckController
{
public:

    DeckController(IHasCard& InSpareDeck);
    void Initialize(ITurnActionHandler& TurnActionHandler);
    void ShuffleCards();
    std::shared_ptr<Card> BuyCard();
    std::vector<std::shared_ptr<Card>> BuyCards(uint16_t TotalCards);

private:

    std::vector<std::shared_ptr<Card>> Cards{};
    IHasCard& SpareDeck;

    void CreateDeck(ITurnActionHandler& TurnActionHandler);
    void CreateNumberCards(const std::vector<EColor>& Colors);
    void CreateSpecialCards(const std::vector<EColor>& Colors, ITurnActionHandler& TurnActionHandler);
    void RestockDeck();
};
