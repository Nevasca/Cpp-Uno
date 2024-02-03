#pragma once
#include <xstring>

class LobbyConsoleInput
{
public:

    static const std::string START_NAME;

    void Process();
    std::string& GetJoiningPlayerName();
    bool IsStartedPressed() const;

private:

    std::string JoiningPlayerName{};
    bool bIsStartPressed{false};

    void ClearInput();
};
