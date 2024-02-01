#pragma once
class PlayerConsoleInput
{
public:

    void Process();
    int GetSelectedCardIndex() const;
    bool HasSelectedACard() const;
    bool HasYelledUno() const;

private:

    static constexpr int YELL_UNO_INPUT = -2;
    
    bool bHasSelectedACard{false};
    int SelectedCardIndex{-1};
    bool bHasYelledUno{false};

    void ClearInput();
};
