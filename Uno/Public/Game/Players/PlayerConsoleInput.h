#pragma once
class PlayerConsoleInput
{
public:

    void Process();
    int GetSelectedCardIndex() const;
    bool HasSelectedCard() const;

private:

    bool bHasSelectedCard{false};
    int SelectedCardIndex{-1};

    void ClearInput();
};
