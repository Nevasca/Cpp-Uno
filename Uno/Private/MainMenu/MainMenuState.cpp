#include "Public/MainMenu/MainMenuState.h"

#include "Public/Core/StateMachine.h"
#include "Public/Game/MatchState.h"

void MainMenuState::Enter()
{
    MainMenuController.Start();
}

void MainMenuState::Update(StateMachine& StateMachine)
{
    if(MainMenuController.IsPlayRequested())
    {
        StateMachine.SetState<MatchState>();
        return;
    }
    
    MainMenuController.Update();
}

void MainMenuState::Exit()
{ }
