#include "Public/Game/Outcome/UI/UIMatchOutcomeController.h"

#include <iostream>
#include <string>

#include "Public/Game/Player.h"

void UIMatchOutcomeController::ShowWinner(const Player& Winner)
{
    std::string Output{};

    Output += "\n\n\n" + Winner.GetName() + " has won the game!!\n\nHope you are still friends with them.\n\n\n";
    std::cout << Output;
}

void UIMatchOutcomeController::ShowExitMessage(char RestartInputName, char QuitInputName)
{
    std::string Output = "Restart match [";
    Output += RestartInputName;
    Output += '/';
    Output += QuitInputName;
    Output += "]? ";
    
    std::cout << Output;
}
