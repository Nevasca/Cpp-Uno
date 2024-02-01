#include "Public/Game/MatchState.h"

#include <memory>

#include "Public/Core/StateMachine.h"
#include "Public/Game/MatchFinishedState.h"

void MatchState::Enter()
{
    MatchController.Initialize();
    MatchController.Start();
}

void MatchState::Update(StateMachine& StateMachine)
{
    if(MatchController.IsMatchFinished())
    {
        std::shared_ptr<MatchFinishedState> FinishedState = std::make_shared<MatchFinishedState>(MatchController.GetWinner());
        StateMachine.AddState(std::move(FinishedState), true);
        
        return;
    }
    
    MatchController.Update();
}

void MatchState::Exit()
{
    MatchController.Shutdown();
}
