#include "Public/Game/Match/Board.h"

#include <assert.h>

void Board::Stack(std::shared_ptr<Card>&& Card)
{
    TossedCards.emplace_back(std::move(Card));
}

const Card& Board::PeekCurrentCard() const
{
    assert(!TossedCards.empty());

    return *TossedCards.back();
}
