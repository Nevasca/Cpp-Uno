#pragma once
#include "MatchController.h"
#include "Public/Core/IState.h"

class MatchState : public IState
{
public:

    void Enter() override;
    void Update(StateMachine& StateMachine) override;
    void Exit() override;
    ~MatchState() = default;

private:

    MatchController MatchController{};
};
