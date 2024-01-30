#pragma once
#include "CardConsolePresenter.h"

class IMatchHandler;
class ITurnHandler;

class TurnConsolePresenter
{
public:
    void Show(const IMatchHandler& MatchHandler, const ITurnHandler& TurnHandler);

private:

    CardConsolePresenter CardPresenter{};

    void ShowTile(const ITurnHandler& TurnHandler);
    void ShowPlayers(const ITurnHandler& TurnHandler);
    void ShowCurrentCard(const IMatchHandler& MatchHandler);
};
