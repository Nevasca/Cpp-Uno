#pragma once

class OutcomeConsoleInput
{
public:
    void Process();
    bool HasPressedExit() const;

private:

    bool bHasPressedExit{false};
};
