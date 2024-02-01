#include "Public/Game/MatchFinishedState.h"

#include "Public/Core/StateMachine.h"

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
        StateMachine.Stop();
        return;
    }

    MatchOutcomeController.Update();
}

void MatchFinishedState::Exit()
{
    MatchOutcomeController.Shutdown();
}
