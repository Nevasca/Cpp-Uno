#include "Public/Game/UI/CardConsolePresenter.h"

#include <iostream>

#include "Public/Game/Card.h"

CardConsolePresenter::CardConsolePresenter()
{
    ColorMapping[EColor::Blue] = ConsoleColor::Blue;
    ColorMapping[EColor::Green] = ConsoleColor::Green;
    ColorMapping[EColor::Red] = ConsoleColor::Red;
    ColorMapping[EColor::Yellow] = ConsoleColor::Yellow;
    ColorMapping[EColor::Wild] = ConsoleColor::White;
}

void CardConsolePresenter::Show(const Card& Card)
{
    std::cout << ColorMapping[Card.GetColor()] << Card.ToShortString() << ConsoleColor::White;
}

void CardConsolePresenter::Show(const std::vector<std::shared_ptr<Card>>& Cards)
{
    for(const std::shared_ptr<Card>& Card : Cards)
    {
        std::string Output = Card->ToShortString() + "   ";
        std::cout << ColorMapping[Card->GetColor()] << Output;
    }

    std::cout << ConsoleColor::White << "\n";
}

void CardConsolePresenter::Show(const std::vector<CardRenderData>& CardsData)
{
    for (const CardRenderData& CardData : CardsData)
    {
        std::string Output = CardData.CardToRender.ToShortString() + "   ";
        std::cout << ColorMapping[CardData.CardToRender.GetColor()] << Output;
    }

    std::cout << ConsoleColor::White;

    constexpr int TotalCharsPerCard = 6;
    constexpr int TotalLineBreaks = 2;

    std::string Output{};
    Output.reserve(CardsData.size() * TotalCharsPerCard + TotalLineBreaks);

    Output += "\n";

    for(size_t i = 0; i < CardsData.size(); i++)
    {
        Output += " " + (CardsData[i].bCanBeUsed ? std::to_string(i) : " ") + "    ";
    }

    Output += "\n";

    std::cout << Output;
}
