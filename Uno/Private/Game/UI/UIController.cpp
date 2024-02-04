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
    if(!Player.IsLocalPlayer() && !bIsSpecMode)
    {
        return;
    }
    
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

void UIController::ShowAvailableCommands(const Player& Player)
{
    if(!Player.IsLocalPlayer())
    {
        return;
    }
    
    std::string Output{};

    Output += "Available Commands:\n";
    Output += "* Type a card number to use it;\n";
    Output += "* Type -2 to yell Uno!\n";

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

void UIController::ShowNoCardsPenalty(const Player& Player, const std::vector<std::shared_ptr<Card>>& PenaltyCards)
{
    std::string Output{};

    Output += Player.GetName() + " has no valid card to use on this turn.\n";
    Output += "Received a penalty of buying " + std::to_string(PenaltyCards.size()) + " new card(s):\n";
    std::cout << Output;

    CardPresenter.Show(PenaltyCards);

    std::cout << "\n\n";

    ConsoleUtils::Delay(SHOW_NO_CARDS_PENALTY_MILLISECONDS_DELAY, true);
}

void UIController::ShowInvalidCardWarning()
{
    std::cout << "Please enter a valid card\n";
}

void UIController::ShowCantUseCardWarning()
{
    std::cout << "This card can't be used right now, please enter another one\n";
}

void UIController::ShowMinCardsForUnoWarning(uint8_t MinCardsRequired)
{
    std::string Output = "You need " + std::to_string(MinCardsRequired) + " cards to yell Uno!\n";
    
    std::cout << Output;
}

void UIController::ShowAlreadyYelledUnoWarning()
{
    std::cout << "You've already yelled Uno!\n\n";
}

void UIController::ShowUnoYell()
{
    std::cout << "\n\nUNO!!\n\n";
}

void UIController::ShowUnoNotYelledPenalty(const Player& Player, const std::vector<std::shared_ptr<Card>>& PenaltyCards)
{
    std::string Output{};

    Output += Player.GetName() + " has not yelled UNO.\n";
    Output += "Received a penalty of buying " + std::to_string(PenaltyCards.size()) + " new card(s):\n";
    std::cout << Output;

    CardPresenter.Show(PenaltyCards);

    std::cout << "\n\n";

    ConsoleUtils::Delay(SHOW_UNO_NOT_YELLED_PENALTY_MILLISECONDS_DELAY, true);
}

void UIController::ShowBoughtCards(const Player& Player, const std::vector<std::shared_ptr<Card>>& BoughtCards)
{
    std::string Output{};

    Output += Player.GetName() + " has bought " + std::to_string(BoughtCards.size()) + " card(s):\n";
    std::cout << Output;

    CardPresenter.Show(BoughtCards);

    std::cout << "\n\n";

    ConsoleUtils::Delay(LONG_MESSAGE_MILLISECONDS_DELAY, true);
}

void UIController::ShowChooseColor(const std::vector<EColor>& AvailableColors)
{
    std::map<EColor, ConsoleColor> ColorMapping = CardPresenter.GetColorMapping();

    std::cout << "Choose a color for the used card:\n";

    for(EColor Color : AvailableColors)
    {
        std::cout << ConsoleColor::White << std::to_string(static_cast<uint8_t>(Color)) << ": ";
        std::cout << ColorMapping[Color] << ConvertColorToString(Color) << "\n";
    }

    std::cout << ConsoleColor::White << "\n\n";
}

void UIController::ShowInvalidColorWarning()
{
    std::cout << "Please select a valid color\n";
}

void UIController::ShowCardColorChanged(EColor Color)
{
    std::map<EColor, ConsoleColor> ColorMapping = CardPresenter.GetColorMapping();
    
    std::cout << "\n\nCurrent table card is now " << ColorMapping[Color] << ConvertColorToString(Color) << ConsoleColor::White << "\n\n";

    ConsoleUtils::Delay(MEDIUM_MESSAGE_MILLISECONDS_DELAY, true);
}

void UIController::HandleTurnFlowReversed()
{
    std::cout << "\n\nTurn flow reversed!\n\n";

    ConsoleUtils::Delay(SHORT_MESSAGE_MILLISECONDS_DELAY, true);
}

void UIController::HandleTurnJumped(const Player& Player)
{
    std::string Output = "\n\nTurn Skipped! Too bad for " + Player.GetName() + "...";

    std::cout << Output;

    ConsoleUtils::Delay(MEDIUM_MESSAGE_MILLISECONDS_DELAY, true);
}

void UIController::EnableSpecMode()
{
    bIsSpecMode = true;
}
