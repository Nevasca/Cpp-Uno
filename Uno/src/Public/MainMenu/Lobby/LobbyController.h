#pragma once
#include <string>
#include <vector>

#include "LobbyConsoleInput.h"
#include "Public/PlayerData.h"
#include "UI/UILobbyController.h"

class LobbyController
{
public:

    LobbyController();
    void Start();
    void Update();
    void Shutdown();
    bool IsEveryPlayerReady() const;
    const std::vector<PlayerData>& GetPlayers() const;

private:

    static constexpr uint16_t MIN_PLAYERS = 2;
    static constexpr uint16_t MAX_PLAYERS = 10;
    static constexpr char BOT_SYMBOL = '!';
    
    std::vector<PlayerData> JoinedPlayers{};
    bool bIsEveryPlayerReady{false};
    UILobbyController UIController;
    LobbyConsoleInput Input{};

    bool IsPlayerAlreadyJoined(const std::string& Name) const;
    bool HasRequiredPlayers() const;
    bool IsFull() const;
    void TryJoinPlayer(std::string&& PlayerName);
};
