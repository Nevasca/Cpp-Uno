#include "Public/Game/UI/UIController.h"

#include <iostream>

#include "Public/Core/ConsoleUtils.h"
#include "Public/Game/IMatchHandler.h"
#include "Public/Game/Player.h"

void UIController::Clear()
{
    ConsoleUtils::Clear();
}

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

void UIController::ShowAvailableCommands()
{
    std::string Output{};

    Output += "Available Commands:\n";
    Output += "* Type a card number to use it;\n";

    Output += "\n\n";

    std::cout << Output;
}

void UIController::ShowUsedCard(const Card& Card, const Player& Player)
{
    std::string Output{};

    Output += Player.GetName() + " has used the card:\n";
    std::cout << Output;

    CardPresenter.Show(Card);

    std::cout << "\n\n";

    ConsoleUtils::Delay(SHOW_USED_CARD_MILLISECONDS_DELAY, true);
}
