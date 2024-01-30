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

private:

    CardConsolePresenter CardPresenter{};
    TurnConsolePresenter TurnPresenter{};
};
