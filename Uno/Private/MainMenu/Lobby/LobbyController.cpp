#include "Public/MainMenu/Lobby/LobbyController.h"

LobbyController::LobbyController()
    : UIController(MIN_PLAYERS, MAX_PLAYERS)
{ }

void LobbyController::Start()
{ }

void LobbyController::Update()
{
    UIController.ShowCurrentLobby(JoinedPlayerNames, LobbyConsoleInput::START_NAME, HasRequiredPlayers());

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

bool LobbyController::IsEveryPlayerReady() const
{
    return bIsEveryPlayerReady;
}

const std::vector<std::string>& LobbyController::GetPlayers() const
{
    return JoinedPlayerNames;
}

void LobbyController::TryJoinPlayer(std::string&& PlayerName)
{
    if(!IsPlayerAlreadyJoined(PlayerName))
    {
        UIController.ShowAlreadyJoinedWarning(PlayerName);
        return;
    }
    
    JoinedPlayerNames.emplace_back(std::move(PlayerName));
}

bool LobbyController::IsPlayerAlreadyJoined(const std::string& Name) const
{
    for(const std::string& ExistingName : JoinedPlayerNames)
    {
        if(ExistingName == Name)
        {
            return false;
        }
    }

    return true;
}

bool LobbyController::HasRequiredPlayers() const
{
    return JoinedPlayerNames.size() >= MIN_PLAYERS;
}

bool LobbyController::IsFull() const
{
    return JoinedPlayerNames.size() == MAX_PLAYERS;
}
