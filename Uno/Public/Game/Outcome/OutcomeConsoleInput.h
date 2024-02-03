#pragma once

class OutcomeConsoleInput
{
public:

    static constexpr char RESTART_INPUT_NAME = 'Y';
    static constexpr char QUIT_INPUT_NAME = 'N';
    
    void Process();
    bool HasPressedExit() const;
    bool HasPressedRestarted() const;

private:

    bool bHasPressedExit{false};
    bool bHasPressedRestart{false};

    void Clear();
};
