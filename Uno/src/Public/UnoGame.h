#pragma once
#include "Core/StateMachine.h"

class UnoGame
{
public:

    void Start();
    bool IsRunning() const;
    void Update();

private:

    StateMachine StateMachine{};

    void CreateGameStates();
};
