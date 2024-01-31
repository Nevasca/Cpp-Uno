#include "Public/Core/ConsoleUtils.h"

#include <cstdlib>
#include <thread>
#include <windows.h>

void ConsoleUtils::Clear()
{
    system("cls");
}

void ConsoleUtils::Delay(const long long& Milliseconds)
{
    Delay(Milliseconds, false);
}

void ConsoleUtils::Delay(const long long& Milliseconds, bool bToggleCursor)
{
    if(bToggleCursor)
    {
        ToggleCursor(false);
        std::this_thread::sleep_for(std::chrono::milliseconds(Milliseconds));
        ToggleCursor(true);
    }
    else
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(Milliseconds));
    }
}

void ConsoleUtils::ToggleCursor(bool bIsVisible)
{
    HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(ConsoleHandle, &CursorInfo);

    CursorInfo.bVisible = bIsVisible;
    SetConsoleCursorInfo(ConsoleHandle, &CursorInfo);
}
