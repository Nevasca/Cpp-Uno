#include "Public/MainMenu/MainMenuConsoleInput.h"

#include "conio.h"

void MainMenuConsoleInput::Process()
{
    _getch();

    bHasPressedPlay = true;
}

bool MainMenuConsoleInput::HasPressedPlay() const
{
    return bHasPressedPlay;
}
