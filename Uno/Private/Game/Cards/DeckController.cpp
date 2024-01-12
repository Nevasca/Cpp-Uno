#include "Public/Game/Cards/DeckController.h"

#include "Public/Core/Random.h"
#include "Public/Game/Cards/CardFactory.h"

void DeckController::Initialize()
{
    CreateDeck();
    ShuffleCards();
}

void DeckController::ShuffleCards()
{
    std::shuffle(Cards.begin(), Cards.end(), Random::GetRandomEngine());
}

void DeckController::CreateDeck()
{
    for (uint16_t i = 0; i < 10; i++)
    {
        Cards.push_back(CardFactory::CreateNumberCard(EColor::Blue, i));
        Cards.push_back(CardFactory::CreateNumberCard(EColor::Red, i));
        Cards.push_back(CardFactory::CreateNumberCard(EColor::Green, i));
        Cards.push_back(CardFactory::CreateNumberCard(EColor::Yellow, i));
    }
}
