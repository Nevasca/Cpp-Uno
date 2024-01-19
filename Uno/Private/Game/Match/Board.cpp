#include "Public/Game/Match/Board.h"

#include <assert.h>

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
    assert(!TossedCards.empty());

    return TossedCards.back();
}
