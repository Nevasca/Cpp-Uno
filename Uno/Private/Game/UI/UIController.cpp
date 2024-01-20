#include "Public/Game/UI/UIController.h"

#include <iostream>

#include "Public/Game/IMatchHandler.h"
#include "Public/Game/Player.h"

void UIController::ShowPlayerHand(const IMatchHandler& Match, const Player& Player)
{
    std::cout << Player.GetName() << "'s hand:\n";

    const std::vector<std::shared_ptr<Card>>& Cards = Player.GetCards();

    std::vector<CardRenderData> CardsData{};
    CardsData.reserve(Cards.size());
    
    for(const std::shared_ptr<Card>& Card : Cards)
    {
        CardsData.emplace_back(*Card, Match.CanUseCard(*Card));
    }
    
    CardPresenter.Show(CardsData);
}
