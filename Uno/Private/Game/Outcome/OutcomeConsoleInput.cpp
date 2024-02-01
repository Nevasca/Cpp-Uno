#include "Public/Game/Outcome/OutcomeConsoleInput.h"

#include "conio.h"

void OutcomeConsoleInput::Process()
{
    _getch();

    bHasPressedExit = true;
}

bool OutcomeConsoleInput::HasPressedExit() const
{
    return bHasPressedExit;
}
