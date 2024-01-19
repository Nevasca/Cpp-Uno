#include "Public/Game/MatchState.h"
#include "Public/Core/StateMachine.h"

void MatchState::Enter()
{
    MatchController.Initialize();
    MatchController.Start();
}

void MatchState::Update(StateMachine& StateMachine)
{
    MatchController.Update();

    if(MatchController.IsMatchFinished())
    {
        StateMachine.Stop();
    }
}

void MatchState::Exit()
{
    MatchController.Shutdown();
}
