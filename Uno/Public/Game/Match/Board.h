#pragma once
#include <memory>
#include <vector>

class Card;

class Board
{
public:

    void Stack(std::shared_ptr<Card>&& Card);
    const Card& PeekCurrentCard() const;
    
private:
    std::vector<std::shared_ptr<Card>> TossedCards{};
};
