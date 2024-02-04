#include "Public/Game/Cards/DeckController.h"

#include <cassert>

#include "Public/Core/Random.h"
#include "Public/Game/Cards/CardFactory.h"
#include "Public/Game/IHasCard.h"
#include "Public/Game/Cards/DeckData.h"

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
    Cards.reserve(DeckData::GetTotalCards());

    const std::vector<EColor> AvailableNormalColors = GetAvailableNormalColors();

    CreateNumberCards(AvailableNormalColors);
    CreateSpecialCards(AvailableNormalColors, TurnActionHandler);
}

void DeckController::CreateNumberCards(const std::vector<EColor>& Colors)
{
    for(const EColor Color : Colors)
    {
        for(uint32_t i = 0; i < DeckData::NUMBER_CARDS_PER_COLOR; i++)
        {
            for(uint16_t CardNumber = DeckData::MIN_NUMBER_CARD_NUMBER; CardNumber <= DeckData::MAX_NUMBER_CARD_NUMBER; CardNumber++)
            {
                Cards.emplace_back(CardFactory::CreateNumberCard(Color, CardNumber));
            }
        }
    }
}

void DeckController::CreateSpecialCards(const std::vector<EColor>& Colors, ITurnActionHandler& TurnActionHandler)
{
    for(const EColor Color : Colors)
    {
        for(uint32_t i = 0; i < DeckData::PLUS_TWO_CARDS_PER_COLOR; i++)
        {
            Cards.emplace_back(CardFactory::CreatePlusTwoCard(Color, TurnActionHandler));
        }

        for(uint32_t i = 0; i < DeckData::REVERSE_CARDS_PER_COLOR; i++)
        {
            Cards.emplace_back(CardFactory::CreateReverseCard(Color, TurnActionHandler));
        }

        for(uint32_t i = 0; i < DeckData::JUMP_CARDS_PER_COLOR; i++)
        {
            Cards.emplace_back(CardFactory::CreateJumpCard(Color, TurnActionHandler));
        }
    }

    for(uint32_t i = 0; i < DeckData::WILD_PLUS_FOUR_CARDS; i++)
    {
        Cards.emplace_back(CardFactory::CreateWildPlusFourCard(TurnActionHandler));
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

std::vector<EColor> DeckController::GetAvailableNormalColors() const
{
    return DeckData::GetAvailableNormalColors();
}
