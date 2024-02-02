#include "Public/MainMenu/MainMenuController.h"

void MainMenuController::Start()
{
    UIController.ShowMainMenu();
}

void MainMenuController::Update()
{
    Input.Process();

    bIsPlayRequested = Input.HasPressedPlay();
}

bool MainMenuController::IsPlayRequested() const
{
    return bIsPlayRequested;
}
