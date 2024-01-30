#include "Public/Game/Players/HumanPlayer.h"

#include <iostream>

HumanPlayer::HumanPlayer(std::string&& InName)
    : Player(std::move(InName))
{ }

void HumanPlayer::PlayTurn()
{
    Input.Process();

    if(Input.HasSelectedCard())
    {
        std::cout << Name << " has chosen card index " + std::to_string(Input.GetSelectedCardIndex()) + "\n";
    }
}
