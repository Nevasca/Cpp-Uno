#pragma once
#include "CardConsolePresenter.h"
#include "TurnConsolePresenter.h"

class ITurnHandler;
class Player;
class IMatchHandler;

class UIController
{
public:

    void Clear();
    void ShowCurrentTurn(const IMatchHandler& MatchHandler, const ITurnHandler& TurnHandler);
    void ShowPlayerHand(const IMatchHandler& MatchHandler, const Player& Player);
    void ShowAvailableCommands();
    void ShowUsedCard(const Card& Card, const Player& Player);

private:

    static constexpr int SHOW_USED_CARD_MILLISECONDS_DELAY = 1000;
    
    CardConsolePresenter CardPresenter{};
    TurnConsolePresenter TurnPresenter{};
};
