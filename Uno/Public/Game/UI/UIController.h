#pragma once
#include "CardConsolePresenter.h"

class Player;
class IMatchHandler;

class UIController
{
public:

    void ShowPlayerHand(const IMatchHandler& Match, const Player& Player);

private:

    CardConsolePresenter CardPresenter{};
};
