#include "Public/Game/Outcome/OutcomeConsoleInput.h"

#include "Public/Core/ConsoleUtils.h"

void OutcomeConsoleInput::Process()
{
    const char RawInput = ConsoleUtils::GetInput<char>();

    bHasPressedRestart = std::toupper(RawInput) == RESTART_INPUT_NAME;
    
    bHasPressedExit = !bHasPressedRestart;
}

bool OutcomeConsoleInput::HasPressedExit() const
{
    return bHasPressedExit;
}

bool OutcomeConsoleInput::HasPressedRestarted() const
{
    return bHasPressedRestart;
}

void OutcomeConsoleInput::Clear()
{
    bHasPressedExit = false;
    bHasPressedRestart = false;
}
