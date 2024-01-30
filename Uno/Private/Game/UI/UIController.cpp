#include "Public/Game/UI/UIController.h"

#include <iostream>

#include "Public/Game/IMatchHandler.h"
#include "Public/Game/Player.h"

void UIController::ShowCurrentTurn(const IMatchHandler& MatchHandler, const ITurnHandler& TurnHandler)
{
    TurnPresenter.Show(MatchHandler, TurnHandler);
}

void UIController::ShowPlayerHand(const IMatchHandler& MatchHandler, const Player& Player)
{
    std::cout << Player.GetName() << "'s hand:\n";

    const std::vector<std::shared_ptr<Card>>& Cards = Player.GetCards();

    std::vector<CardRenderData> CardsData{};
    CardsData.reserve(Cards.size());
    
    for(const std::shared_ptr<Card>& Card : Cards)
    {
        CardsData.emplace_back(*Card, MatchHandler.CanUseCard(*Card));
    }
    
    CardPresenter.Show(CardsData);

    std::cout << "\n\n";
}
