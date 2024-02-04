#include "Public/MainMenu/Lobby/UI/UILobbyController.h"

#include <iostream>

#include "Public/Core/ConsoleUtils.h"

UILobbyController::UILobbyController(uint16_t InMinPlayers, uint16_t InMaxPlayers, char InBotSymbol)
    : MinPlayers(InMinPlayers), MaxPlayers(InMaxPlayers), BotSymbol(InBotSymbol)
{ }

void UILobbyController::ShowCurrentLobby(const std::vector<PlayerData>& JoinedPlayers, const std::string& StartInputName, bool bHasRequiredPlayers)
{
    ConsoleUtils::Clear();

    std::string Output{};

    const size_t TotalCurrentPlayers = JoinedPlayers.size();

    Output += "Uno Lobby [" + std::to_string(TotalCurrentPlayers) + "/" + std::to_string(MaxPlayers) + "]\n";
    Output += "------------------------\n\n";

    if(!bHasRequiredPlayers)
    {
        Output += "At least " + std::to_string(MinPlayers) + " player(s) required to play.\n\n";
    }
    
    Output += "Joined Players:\n";

    for(const PlayerData& Player : JoinedPlayers)
    {
        Output += "* " + Player.Name;
        Output += Player.bIsBot ? " (Bot)" : "";
        Output += "\n";
    }

    Output += "\n\n";

    Output += "To add a bot, use '";
    Output += BotSymbol;
    Output += "' at the end of the bot name, like 'Yukiko";
    Output += BotSymbol;
    Output += "'\n\n\n";

    std::cout << Output;

    ShowJoinPlayerMessage(StartInputName, bHasRequiredPlayers);
}

void UILobbyController::ShowJoinPlayerMessage(const std::string& StartInputName, bool bHasRequiredPlayers)
{
    std::string Output = "Enter a player name to join";

    if(bHasRequiredPlayers)
    {
        Output += " ('" + StartInputName + "' to start)";
    }

    Output += ": ";

    std::cout << Output;
}

void UILobbyController::ShowAlreadyJoinedWarning(const std::string& Name)
{
    std::cout << "\nPlayer " + Name + " has already joined.";

    ConsoleUtils::Delay(SHORT_MESSAGE_MILLISECONDS_DELAY, true);
}
