#include "Public/MainMenu/Lobby/LobbyController.h"

LobbyController::LobbyController()
    : UIController(MIN_PLAYERS, MAX_PLAYERS, BOT_SYMBOL)
{ }

void LobbyController::Start()
{ }

void LobbyController::Update()
{
    UIController.ShowCurrentLobby(JoinedPlayers, LobbyConsoleInput::START_NAME, HasRequiredPlayers());

    Input.Process();

    if(Input.IsStartedPressed())
    {
        if(HasRequiredPlayers())
        {
            bIsEveryPlayerReady = true;
        }

        return;
    }

    std::string NewPlayerName = Input.GetJoiningPlayerName();
    TryJoinPlayer(std::move(NewPlayerName));

    if(IsFull())
    {
        bIsEveryPlayerReady = true;
    }
}

void LobbyController::Shutdown()
{
    JoinedPlayers.clear();
    bIsEveryPlayerReady = false;
}

bool LobbyController::IsEveryPlayerReady() const
{
    return bIsEveryPlayerReady;
}

const std::vector<PlayerData>& LobbyController::GetPlayers() const
{
    return JoinedPlayers;
}

void LobbyController::TryJoinPlayer(std::string&& PlayerName)
{
    if(!IsPlayerAlreadyJoined(PlayerName))
    {
        UIController.ShowAlreadyJoinedWarning(PlayerName);
        return;
    }

    bool bIsBot = PlayerName.back() == BOT_SYMBOL;

    if(bIsBot && PlayerName.size() > 1)
    {
        PlayerName.pop_back();
    }

    JoinedPlayers.emplace_back(std::move(PlayerName), bIsBot);
}

bool LobbyController::IsPlayerAlreadyJoined(const std::string& Name) const
{
    for(const PlayerData& ExistingPlayer : JoinedPlayers)
    {
        if(ExistingPlayer.Name == Name)
        {
            return false;
        }
    }

    return true;
}

bool LobbyController::HasRequiredPlayers() const
{
    return JoinedPlayers.size() >= MIN_PLAYERS;
}

bool LobbyController::IsFull() const
{
    return JoinedPlayers.size() == MAX_PLAYERS;
}
