#pragma once
#include <memory>
#include <vector>

class Card;

class CardConsolePresenter
{
public:

    void Show(const Card& Card);
    void Show(const std::vector<std::shared_ptr<Card>>& Cards);
};
