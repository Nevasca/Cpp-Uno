#pragma once
#include <ostream>

class ConsoleColor
{
public:

    static const ConsoleColor White;
    static const ConsoleColor Blue;
    static const ConsoleColor Green;
    static const ConsoleColor Red;
    static const ConsoleColor Yellow;
    static const ConsoleColor Pink;
    
    static void SetFontColor(uint16_t ColorFlag);
    static void SetFontColor(ConsoleColor Color);

    ConsoleColor() = default;
    ConsoleColor(uint16_t InColorFlag);

    friend std::ostream& operator <<(std::ostream& Os, const ConsoleColor& ConsoleColor);

private:

    uint16_t Color{7};
};
