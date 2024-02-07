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

inline bool TryUIntToColor(uint8_t ColorId, EColor& OutColor)
{
    OutColor = static_cast<EColor>(ColorId);
    
    switch (OutColor)
    {
        case EColor::Blue:
        case EColor::Yellow:
        case EColor::Red:
        case EColor::Green:
        case EColor::Wild:
            return true;
    }

    return false;
}