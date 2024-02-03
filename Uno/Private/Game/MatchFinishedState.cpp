#include "Public/Game/MatchFinishedState.h"

#include "Public/Core/StateMachine.h"
#include "Public/MainMenu/MainMenuState.h"
#include "Public/MainMenu/Lobby/LobbyState.h"

MatchFinishedState::MatchFinishedState(const std::shared_ptr<Player>& Winner)
    : MatchOutcomeController(Winner)
{ }

void MatchFinishedState::Enter()
{
    MatchOutcomeController.Start();
}

void MatchFinishedState::Update(StateMachine& StateMachine)
{
    if(MatchOutcomeController.IsExitRequested())
    {
        StateMachine.SetState<MainMenuState>();
        return;
    }

    if(MatchOutcomeController.IsRestartRequested())
    {
        StateMachine.SetState<LobbyState>();
        return;
    }

    MatchOutcomeController.Update();
}

void MatchFinishedState::Exit()
{
    MatchOutcomeController.Shutdown();
}
