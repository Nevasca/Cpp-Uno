#include "Public/MainMenu/UI/UIMainMenuController.h"

#include <iostream>

void UIMainMenuController::ShowMainMenu()
{
    std::string Output{};

    Output += "UNO!\nCpp Console Version\n\n";
    Output += "Press any key to start...";
    
    std::cout << Output;
}
