#include "Public/Game/Cards/DeckController.h"

#include <cassert>

#include "Public/Core/Random.h"
#include "Public/Game/Cards/CardFactory.h"
#include "Public/Game/IHasCard.h"

DeckController::DeckController(IHasCard& InSpareDeck)
    : SpareDeck(InSpareDeck)
{ }

void DeckController::Initialize(ITurnActionHandler& TurnActionHandler)
{
    CreateDeck(TurnActionHandler);
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

    assert(!Cards.empty());
    
    std::shared_ptr<Card> Card = Cards.back();
    Cards.pop_back();

    return Card;
}

std::vector<std::shared_ptr<Card>> DeckController::BuyCards(uint16_t TotalCards)
{
    std::vector<std::shared_ptr<Card>> BoughtCards{};
    BoughtCards.reserve(TotalCards);

    for(int i = 0; i < TotalCards; i++)
    {
        BoughtCards.emplace_back(BuyCard());    
    }

    return BoughtCards;
}

void DeckController::CreateDeck(ITurnActionHandler& TurnActionHandler)
{
    constexpr int TotalCards = 48;  
    Cards.reserve(TotalCards);

    for (uint16_t i = 0; i < 8; i++)
    {
        Cards.emplace_back(CardFactory::CreateNumberCard(EColor::Blue, i));
        Cards.emplace_back(CardFactory::CreateNumberCard(EColor::Red, i));
        Cards.emplace_back(CardFactory::CreateNumberCard(EColor::Green, i));
        Cards.emplace_back(CardFactory::CreateNumberCard(EColor::Yellow, i));
    }

    for (int i = 0;  i < 2; i++)
    {
        Cards.emplace_back(CardFactory::CreateReverseCard(EColor::Blue, TurnActionHandler));
        Cards.emplace_back(CardFactory::CreateReverseCard(EColor::Red, TurnActionHandler));
        Cards.emplace_back(CardFactory::CreateReverseCard(EColor::Green, TurnActionHandler));
        Cards.emplace_back(CardFactory::CreateReverseCard(EColor::Yellow, TurnActionHandler));
    }

    for (int i = 0;  i < 2; i++)
    {
        Cards.emplace_back(CardFactory::CreateJumpCard(EColor::Blue, TurnActionHandler));
        Cards.emplace_back(CardFactory::CreateJumpCard(EColor::Red, TurnActionHandler));
        Cards.emplace_back(CardFactory::CreateJumpCard(EColor::Green, TurnActionHandler));
        Cards.emplace_back(CardFactory::CreateJumpCard(EColor::Yellow, TurnActionHandler));
    }

    for (int i = 0;  i < 2; i++)
    {
        Cards.emplace_back(CardFactory::CreatePlusTwoCard(EColor::Blue, TurnActionHandler));
        Cards.emplace_back(CardFactory::CreatePlusTwoCard(EColor::Red, TurnActionHandler));
        Cards.emplace_back(CardFactory::CreatePlusTwoCard(EColor::Green, TurnActionHandler));
        Cards.emplace_back(CardFactory::CreatePlusTwoCard(EColor::Yellow, TurnActionHandler));
    }
}

void DeckController::RestockDeck()
{
    std::vector<std::shared_ptr<Card>> SpareCards = SpareDeck.TakeAllCards();

    size_t PreviousDeckSize = Cards.size();
    Cards.reserve(Cards.size() + SpareCards.size());

    if(PreviousDeckSize < SpareCards.size())
    {
        std::swap(Cards, SpareCards);
    }

    for(std::shared_ptr<Card>& RemainingCard : SpareCards)
    {
        Cards.emplace_back(std::move(RemainingCard));
    }
    
    ShuffleCards();
}
