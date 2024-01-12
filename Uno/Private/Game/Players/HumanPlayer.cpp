#include "Public/Game/Players/HumanPlayer.h"

#include <iostream>

HumanPlayer::HumanPlayer(std::string&& InName)
    : Player(std::move(InName))
{ }

void HumanPlayer::PlayTurn()
{
    std::cout << Name << " has chosen to just watch...";
}
