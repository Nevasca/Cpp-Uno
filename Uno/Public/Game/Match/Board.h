#pragma once
#include <memory>
#include <vector>

#include "Public/Game/IHasCard.h"

class Card;

class Board : public IHasCard
{
public:

    void Stack(std::shared_ptr<Card>&& Card);
    std::shared_ptr<Card> PeekCurrentCard() const;
    std::vector<std::shared_ptr<Card>> TakeAllCards() override;

private:
    std::vector<std::shared_ptr<Card>> TossedCards{};
};
