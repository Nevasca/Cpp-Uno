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
    constexpr int TotalLineBreaks = 1;

    std::string Output{};
    Output.reserve(Cards.size() * TotalCharsPerCard + TotalLineBreaks);

    for(const std::shared_ptr<Card>& Card : Cards)
    {
        Output += Card->ToShortString() + "   ";
    }

    Output += "\n";
    
    std::cout << Output;
}

void CardConsolePresenter::Show(const std::vector<CardRenderData>& CardsData)
{
    constexpr int TotalCharsPerCard = 12;
    constexpr int TotalLineBreaks = 2;

    std::string Output{};
    Output.reserve(CardsData.size() * TotalCharsPerCard + TotalLineBreaks);

    for (const CardRenderData& CardData : CardsData)
    {
        Output += CardData.CardToRender.ToShortString() + "   ";
    }

    Output += "\n";

    for(size_t i = 0; i < CardsData.size(); i++)
    {
        Output += " " + (CardsData[i].bCanBeUsed ? std::to_string(i) : " ") + "    ";
    }

    Output += "\n";

    std::cout << Output;
}
