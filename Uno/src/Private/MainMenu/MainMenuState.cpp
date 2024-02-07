#include "Public/MainMenu/MainMenuState.h"

#include "Public/Core/StateMachine.h"
#include "Public/MainMenu/Lobby/LobbyState.h"

void MainMenuState::Enter()
{
    MainMenuController.Start();
}

void MainMenuState::Update(StateMachine& StateMachine)
{
    if(MainMenuController.IsPlayRequested())
    {
        StateMachine.SetState<LobbyState>();
        return;
    }
    
    MainMenuController.Update();
}

void MainMenuState::Exit()
{
    MainMenuController.Shutdown();
}
