#include "Public/MainMenu/Lobby/LobbyConsoleInput.h"

#include "Public/Core/ConsoleUtils.h"

const std::string LobbyConsoleInput::START_NAME = "Start";

void LobbyConsoleInput::Process()
{
    ClearInput();

    const std::string RawInput = ConsoleUtils::GetInput<std::string>();

    if(RawInput == START_NAME)
    {
        bIsStartPressed = true;
    }
    else
    {
        JoiningPlayerName = RawInput;
    }
}

std::string& LobbyConsoleInput::GetJoiningPlayerName()
{
    return JoiningPlayerName;
}

bool LobbyConsoleInput::IsStartedPressed() const
{
    return bIsStartPressed;
}

void LobbyConsoleInput::ClearInput()
{
    bIsStartPressed = false;
}
