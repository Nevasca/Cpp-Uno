#pragma once

class MainMenuConsoleInput
{
public:
    void Process();
    bool HasPressedPlay() const;

private:

    bool bHasPressedPlay{false};
};
