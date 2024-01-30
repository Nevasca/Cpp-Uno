#pragma once
#include "CardConsolePresenter.h"
#include "TurnConsolePresenter.h"

class ITurnHandler;
class Player;
class IMatchHandler;

class UIController
{
public:

    void ShowCurrentTurn(const IMatchHandler& MatchHandler, const ITurnHandler& TurnHandler);
    void ShowPlayerHand(const IMatchHandler& MatchHandler, const Player& Player);

private:

    CardConsolePresenter CardPresenter{};
    TurnConsolePresenter TurnPresenter{};
};
