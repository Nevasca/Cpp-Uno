#pragma once
#include <memory>
#include <vector>

class Card;

class DeckController
{
public:

    void Initialize();
    void ShuffleCards();
    std::shared_ptr<Card> BuyCard();

private:

    std::vector<std::shared_ptr<Card>> Cards{};

    void CreateDeck();
    void RestockDeck();
};
