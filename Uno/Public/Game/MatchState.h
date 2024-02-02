#pragma once
#include "MatchController.h"
#include "Public/Core/IState.h"

class MatchState : public IState
{
public:

    MatchState(const std::vector<std::string>& InPlayerNames);
    void Enter() override;
    void Update(StateMachine& StateMachine) override;
    void Exit() override;
    ~MatchState() = default;

private:

    MatchController MatchController{};
    std::vector<std::string> PlayerNames{};
};
