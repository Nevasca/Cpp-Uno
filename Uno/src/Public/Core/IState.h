#pragma once
#include "Core.h"

class StateMachine;

class IState
{
public:

    virtual void Enter() = 0;
    virtual void Update(StateMachine& StateMachine) = 0;
    virtual void Exit() = 0;
    virtual ~IState() = default;

    NO_COPY_MOVE(IState)

protected:

    IState() = default;
};
