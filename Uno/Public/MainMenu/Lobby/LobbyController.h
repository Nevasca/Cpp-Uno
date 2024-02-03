#pragma once
#include <string>
#include <vector>

#include "LobbyConsoleInput.h"
#include "UI/UILobbyController.h"

class LobbyController
{
public:

    LobbyController();
    void Start();
    void Update();
    void Shutdown();
    bool IsEveryPlayerReady() const;
    const std::vector<std::string>& GetPlayers() const;

private:

    static constexpr uint16_t MIN_PLAYERS = 2;
    static constexpr uint16_t MAX_PLAYERS = 10;
    
    std::vector<std::string> JoinedPlayerNames{};
    bool bIsEveryPlayerReady{false};
    UILobbyController UIController;
    LobbyConsoleInput Input{};

    bool IsPlayerAlreadyJoined(const std::string& Name) const;
    bool HasRequiredPlayers() const;
    bool IsFull() const;
    void TryJoinPlayer(std::string&& PlayerName);
};
