#include "Public/Game/UI/TurnConsolePresenter.h"

#include <iostream>
#include <string>

#include "Public/Game/IMatchHandler.h"
#include "Public/Game/ITurnHandler.h"
#include "Public/Game/Player.h"

void TurnConsolePresenter::Show( const IMatchHandler& MatchHandler, const ITurnHandler& TurnHandler)
{
    ShowTile(TurnHandler);
    ShowPlayers(TurnHandler);
    ShowCurrentCard(MatchHandler);
}

void TurnConsolePresenter::ShowTile(const ITurnHandler& TurnHandler)
{
    std::string Output{};
    
    const uint32_t ReadableTurnNumber = TurnHandler.GetCurrentTurnIndex() + 1;
    Output += "Turn #" + std::to_string(ReadableTurnNumber) + "\n";
    Output += "------------------------\n\n";

    std::cout << Output;
}

void TurnConsolePresenter::ShowPlayers(const ITurnHandler& TurnHandler)
{
    std::string Output{};

    std::string FlowSymbol = TurnHandler.GetCurrentFlow() == ETurnFlow::Clockwise ? ">>" : "<<";
    
    for(const std::shared_ptr<Player>& Player : TurnHandler.GetOrderedPlayers())
    {
        if(Player == TurnHandler.PeekCurrentPlayer())
        {
            Output += FlowSymbol + "  |" + Player->GetName() + "[" + std::to_string(Player->GetTotalCards()) + "]|" + "  ";
        }
        else
        {
            Output += FlowSymbol + "  " + Player->GetName() + "[" + std::to_string(Player->GetTotalCards()) + "]" + "  ";
        }
    }
    
    Output += FlowSymbol;
    Output += "\n\n";

    std::cout << Output;
}

void TurnConsolePresenter::ShowCurrentCard(const IMatchHandler& MatchHandler)
{
    const std::shared_ptr<Card> CurrentCard = MatchHandler.PeekCurrentCard();

    if(CurrentCard)
    {
        std::cout << "Current card:\n";
        CardPresenter.Show(*CurrentCard);
    }
    else
    {
        std::cout << "No card on the table yet.\n";
    }
    
    std::cout << "\n\n";
}
