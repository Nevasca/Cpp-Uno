#pragma once
#include "MainMenuConsoleInput.h"
#include "UI/UIMainMenuController.h"

class MainMenuController
{
public:

    void Start();
    void Update();
    bool IsPlayRequested() const;

private:

    bool bIsPlayRequested{false};
    UIMainMenuController UIController;
    MainMenuConsoleInput Input;
};
