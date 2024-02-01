#include "Public/Game/Cards/DeckController.h"

#include "Public/Core/Random.h"
#include "Public/Game/Cards/CardFactory.h"
#include "Public/Game/IHasCard.h"

DeckController::DeckController(IHasCard& InSpareDeck)
    : SpareDeck(InSpareDeck)
{ }

void DeckController::Initialize()
{
    CreateDeck();
}

void DeckController::ShuffleCards()
{
    std::shuffle(Cards.begin(), Cards.end(), Random::GetRandomEngine());
}

std::shared_ptr<Card> DeckController::BuyCard()
{
    if(Cards.empty())
    {
        RestockDeck();
    }

    std::shared_ptr<Card> Card = Cards.back();
    Cards.pop_back();

    return Card;
}

void DeckController::CreateDeck()
{
    constexpr int TotalCards = 40;  
    Cards.reserve(TotalCards);
    
    for (uint16_t i = 0; i < 10; i++)
    {
        Cards.push_back(CardFactory::CreateNumberCard(EColor::Blue, i));
        Cards.push_back(CardFactory::CreateNumberCard(EColor::Red, i));
        Cards.push_back(CardFactory::CreateNumberCard(EColor::Green, i));
        Cards.push_back(CardFactory::CreateNumberCard(EColor::Yellow, i));
    }
}

void DeckController::RestockDeck()
{
    std::vector<std::shared_ptr<Card>> SpareCards = SpareDeck.TakeAllCards();

    Cards.reserve(Cards.size() + SpareCards.size());
    
    for(std::shared_ptr<Card>& Card : SpareCards)
    {
        Cards.push_back(Card);
    }

    ShuffleCards();
}
