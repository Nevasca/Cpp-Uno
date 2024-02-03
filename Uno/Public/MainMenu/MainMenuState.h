#pragma once
#include "MainMenuController.h"
#include "Public/Core/IState.h"

class MainMenuState : public IState
{
public:

    void Enter() override;
    void Update(StateMachine& StateMachine) override;
    void Exit() override;

private:

    MainMenuController MainMenuController;
};
