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

void MainMenuController::Shutdown()
{
    bIsPlayRequested = false;
}

bool MainMenuController::IsPlayRequested() const
{
    return bIsPlayRequested;
}
