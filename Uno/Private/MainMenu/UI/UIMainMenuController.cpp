#include "Public/MainMenu/UI/UIMainMenuController.h"

#include <iostream>

#include "Public/Core/ConsoleUtils.h"

void UIMainMenuController::ShowMainMenu()
{
    ConsoleUtils::Clear();
    
    std::string Output{};

    Output += "UNO!\nCpp Console Version\n\n";
    Output += "Press any key to start...";
    
    std::cout << Output;
}
