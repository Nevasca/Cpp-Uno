#include "Public/Game/MatchState.h"

#include <memory>

#include "Public/Core/StateMachine.h"
#include "Public/Game/MatchFinishedState.h"

MatchState::MatchState(const std::vector<std::string>& InPlayerNames)
    : PlayerNames(InPlayerNames)
{ }

void MatchState::Enter()
{
    MatchController = std::make_shared<class MatchController>();
    MatchController->Initialize(PlayerNames);
    MatchController->Start();
}

void MatchState::Update(StateMachine& StateMachine)
{
    if(MatchController->IsMatchFinished())
    {
        std::shared_ptr<MatchFinishedState> FinishedState = std::make_shared<MatchFinishedState>(MatchController->GetWinner());
        StateMachine.AddState(std::move(FinishedState), true);
        
        return;
    }
    
    MatchController->Update();
}

void MatchState::Exit()
{
    MatchController->Shutdown();
    MatchController.reset();
}
