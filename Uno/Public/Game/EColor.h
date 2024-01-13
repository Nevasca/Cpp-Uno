#pragma once

#include <cstdint>
#include <string>

enum class EColor : uint8_t
{
    Blue,
    Yellow,
    Red,
    Green,
    Wild
};

inline std::string ConvertColorToString(const EColor Color)
{
    switch (Color)
    {
        case EColor::Blue:
            return "Blue";
        case EColor::Yellow:
            return "Yellow";
        case EColor::Red:
            return "Red";
        case EColor::Green:
            return "Green";
        case EColor::Wild:
            return "Wild";
    }

    return "Unknown";
}