#pragma once
#include "MatchController.h"
#include "Public/Core/IState.h"

class MatchState : public IState
{
public:

    MatchState(const std::vector<PlayerData>& InPlayers);
    void Enter() override;
    void Update(StateMachine& StateMachine) override;
    void Exit() override;
    ~MatchState() = default;

private:

    std::shared_ptr<MatchController> MatchController{};
    std::vector<PlayerData> Players{};
};
