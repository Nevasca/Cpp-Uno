#pragma once
#include <cstdint>

class PlayerConsoleInput
{
public:

    void Process();
    int GetSelectedCardIndex() const;
    bool HasSelectedACard() const;
    bool HasYelledUno() const;
    bool HasSelectedAColor() const;
    uint8_t GetSelectedColorId() const;

private:

    static constexpr int YELL_UNO_INPUT = -2;
    
    bool bHasSelectedACard{false};
    int SelectedCardIndex{-1};
    bool bHasYelledUno{false};
    bool bHasSelectedAColor{false};
    uint8_t SelectedColorId{0};

    void ClearInput();
};
