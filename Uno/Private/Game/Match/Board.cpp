﻿#include "Public/Game/Match/Board.h"

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
        return TossedCards;
    }

    std::shared_ptr<Card> CurrentCard = TossedCards.back();
    TossedCards.pop_back();

    std::vector<std::shared_ptr<Card>> AllAvailableCards = TossedCards;
    TossedCards.clear();
    TossedCards.emplace_back(std::move(CurrentCard));

    return AllAvailableCards;
}
