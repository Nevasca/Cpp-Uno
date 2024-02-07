#pragma once
#include <memory>

#include "Outcome/MatchOutcomeController.h"
#include "Public/Core/IState.h"

class Player;

class MatchFinishedState : public IState
{
public:

    MatchFinishedState(const std::shared_ptr<Player>& Winner);
    
    void Enter() override;
    void Update(StateMachine& StateMachine) override;
    void Exit() override;

private:

    MatchOutcomeController MatchOutcomeController;
};
