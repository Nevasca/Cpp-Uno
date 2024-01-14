﻿#include "Public/Core/StateMachine.h"

#include "Public/Core/IState.h"

StateMachine::StateMachine(std::vector<std::shared_ptr<IState>>&& InStates)
    : States(std::move(InStates))
{ }

void StateMachine::Update()
{
    if(CurrentState)
    {
        CurrentState->Update(*this);
    }
}

bool StateMachine::IsRunning() const
{
    return CurrentState != nullptr;
}

void StateMachine::Stop()
{
    if(CurrentState)
    {
        CurrentState->Exit();
    }

    CurrentState = nullptr;
}

void StateMachine::SetState(std::shared_ptr<IState>&& State)
{
    if(CurrentState)
    {
        CurrentState->Exit();
    }

    CurrentState = std::move(State);
    CurrentState->Enter();
}
