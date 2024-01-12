#pragma once
#include <memory>
#include <vector>

class Card;

class DeckController
{
public:

    void Initialize();
    void ShuffleCards();

private:

    std::vector<std::shared_ptr<Card>> Cards{};

    void CreateDeck();
};
