#include "Public/Core/ConsoleColor.h"

#include "Windows.h"

const ConsoleColor ConsoleColor::White = {7};
const ConsoleColor ConsoleColor::Blue = {FOREGROUND_BLUE};
const ConsoleColor ConsoleColor::Green = {FOREGROUND_GREEN};
const ConsoleColor ConsoleColor::Red = {FOREGROUND_RED};
const ConsoleColor ConsoleColor::Yellow = {FOREGROUND_RED | FOREGROUND_GREEN};

ConsoleColor::ConsoleColor(uint16_t InColorFlag)
    : Color(InColorFlag)
{ }

void ConsoleColor::SetFontColor(uint16_t ColorFlag)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorFlag);
}

void ConsoleColor::SetFontColor(ConsoleColor Color)
{
    SetFontColor(Color.Color);
}

std::ostream& operator<<(std::ostream& Os, const ConsoleColor& ConsoleColor)
{
    ConsoleColor::SetFontColor(ConsoleColor.Color);
    
    return Os;
}
