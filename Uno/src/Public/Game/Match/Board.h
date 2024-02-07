#pragma once
#include <memory>
#include <vector>

#include "Public/Game/EColor.h"
#include "Public/Game/IHasCard.h"

class Card;

class Board : public IHasCard
{
public:

    void Stack(std::shared_ptr<Card>&& Card);
    std::shared_ptr<Card> PeekCurrentCard() const;
    std::vector<std::shared_ptr<Card>> TakeAllCards() override;
    void SetCurrentCardColor(EColor Color);

private:
    std::vector<std::shared_ptr<Card>> TossedCards{};
};
