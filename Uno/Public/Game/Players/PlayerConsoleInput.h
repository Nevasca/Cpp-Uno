#pragma once
class PlayerConsoleInput
{
public:

    void Process();
    int GetSelectedCardIndex() const;
    bool HasSelectedACard() const;

private:

    bool bHasSelectedACard{false};
    int SelectedCardIndex{-1};

    void ClearInput();
};
