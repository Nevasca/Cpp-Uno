#include "Public/Game/UI/CardConsolePresenter.h"

#include <iostream>

#include "Public/Game/Card.h"

void CardConsolePresenter::Show(const Card& Card)
{
    std::cout << Card.ToShortString();
}

void CardConsolePresenter::Show(const std::vector<std::shared_ptr<Card>>& Cards)
{
    constexpr int TotalCharsPerCard = 6;

    std::string Result{};
    Result.reserve(Cards.size() * TotalCharsPerCard);

    for(const std::shared_ptr<Card>& Card : Cards)
    {
        Result += Card->ToShortString() + "   ";
    }

    std::cout << Result << "\n";
}
