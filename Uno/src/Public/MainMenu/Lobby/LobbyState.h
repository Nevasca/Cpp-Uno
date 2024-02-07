#pragma once
#include "LobbyController.h"
#include "Public/Core/IState.h"

class LobbyState : public IState
{
public:

    void Enter() override;
    void Update(StateMachine& StateMachine) override;
    void Exit() override;

private:

    LobbyController LobbyController;
};
