#pragma once
#include <memory>
#include <vector>

class Card;

class Board
{
public:

    void Stack(std::shared_ptr<Card>&& Card);
    std::shared_ptr<Card> PeekCurrentCard() const;
    
private:
    std::vector<std::shared_ptr<Card>> TossedCards{};
};
