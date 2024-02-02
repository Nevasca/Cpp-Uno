#include "Public/MainMenu/Lobby/LobbyState.h"

#include <memory>

#include "Public/Core/StateMachine.h"
#include "Public/Game/MatchState.h"

void LobbyState::Enter()
{
    LobbyController.Start();
}

void LobbyState::Update(StateMachine& StateMachine)
{
    if(LobbyController.IsEveryPlayerReady())
    {
        StateMachine.AddState<MatchState>(std::make_shared<MatchState>(LobbyController.GetPlayers()), true);
        return;
    }
    
    LobbyController.Update();
}

void LobbyState::Exit()
{ }
