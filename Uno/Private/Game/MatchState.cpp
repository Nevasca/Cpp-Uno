#include "Public/Game/MatchState.h"

#include <iostream>

#include "Public/Core/StateMachine.h"

void MatchState::Enter()
{ }

void MatchState::Update(StateMachine& StateMachine)
{
    std::cout << "\nPress something (-1 to exit)...";
    int input;
    std::cin >> input;

    if(input == -1)
    {
        StateMachine.Stop();
    }
}

void MatchState::Exit()
{ }
