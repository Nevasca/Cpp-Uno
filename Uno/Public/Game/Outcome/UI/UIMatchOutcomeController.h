#pragma once

class Player;

class UIMatchOutcomeController
{
public:

    void ShowWinner(const Player& Winner);
    void ShowExitMessage();
};
