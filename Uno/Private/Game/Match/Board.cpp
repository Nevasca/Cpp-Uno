#include "Public/Game/Match/Board.h"

void Board::Stack(std::shared_ptr<Card>&& Card)
{
    TossedCards.emplace_back(std::move(Card));
}

std::shared_ptr<Card> Board::PeekCurrentCard() const
{
    if(TossedCards.empty())
    {
        return nullptr;
    }

    return TossedCards.back();
}

std::vector<std::shared_ptr<Card>> Board::TakeAllCards()
{
    if(TossedCards.empty())
    {
        return {};
    }

    std::vector<std::shared_ptr<Card>> AllAvailableCards{};
    AllAvailableCards.reserve(TossedCards.size());

    std::swap(AllAvailableCards, TossedCards);

    TossedCards.emplace_back(std::move(AllAvailableCards.back()));
    AllAvailableCards.pop_back();
    
    return AllAvailableCards;
}
