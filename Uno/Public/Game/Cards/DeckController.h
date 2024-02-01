#pragma once
#include <memory>
#include <vector>

class IHasCard;
class Card;

class DeckController
{
public:

    DeckController(IHasCard& InSpareDeck);
    void Initialize();
    void ShuffleCards();
    std::shared_ptr<Card> BuyCard();

private:

    std::vector<std::shared_ptr<Card>> Cards{};
    IHasCard& SpareDeck;

    void CreateDeck();
    void RestockDeck();
};
