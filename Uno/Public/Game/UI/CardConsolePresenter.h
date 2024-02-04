#pragma once
#include <map>
#include <memory>
#include <vector>

#include "CardRenderData.h"
#include "Public/Core/ConsoleColor.h"
#include "Public/Game/EColor.h"

class Card;

class CardConsolePresenter
{
public:

    CardConsolePresenter();
    void Show(const Card& Card);
    void Show(const std::vector<std::shared_ptr<Card>>& Cards);
    void Show(const std::vector<CardRenderData>& CardsData);
    const std::map<EColor, ConsoleColor>& GetColorMapping() const;

private:

    std::map<EColor, ConsoleColor> ColorMapping{};
};
