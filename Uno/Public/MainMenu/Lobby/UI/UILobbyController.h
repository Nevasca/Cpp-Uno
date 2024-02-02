#pragma once
#include <string>
#include <vector>

class UILobbyController
{
public:

    UILobbyController(uint16_t InMinPlayers, uint16_t InMaxPlayers);
    void ShowCurrentLobby(const std::vector<std::string>& JoinedPlayerNames, const std::string& StartInputName, bool bHasRequiredPlayers);
    void ShowAlreadyJoinedWarning(const std::string& Name);

private:
    
    static constexpr int SHORT_MESSAGE_MILLISECONDS_DELAY = 800;

    uint16_t MinPlayers{0};
    uint16_t MaxPlayers{0};

    void ShowJoinPlayerMessage(const std::string& StartInputName, bool bHasRequiredPlayers);
};
