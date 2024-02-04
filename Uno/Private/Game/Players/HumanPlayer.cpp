#include "Public/Game/Players/HumanPlayer.h"

#include <iostream>

#include "Public/Game/IMatchHandler.h"

HumanPlayer::HumanPlayer(std::string&& InName, bool bInIsLocalPlayer)
    : Player(std::move(InName), bInIsLocalPlayer)
{ }

void HumanPlayer::PlayTurn(IMatchHandler& MatchHandler)
{
    bool bHasFinishedTurn = false;

    do
    {
        Input.Process();

        if(Input.HasYelledUno())
        {
            MatchHandler.TryYellUno(*this);
        }
        else if(Input.HasSelectedACard())
        {
            bHasFinishedTurn = MatchHandler.TryUsingCard(*this, Input.GetSelectedCardIndex());
        }
    }
    while (!bHasFinishedTurn);
}

void HumanPlayer::ChooseColor(IMatchHandler& MathHandler, const std::vector<EColor>& AvailableColors)
{
    bool bHasChosenValidColor = false;

    do
    {
        Input.Process();

        if(Input.HasSelectedAColor())
        {
            bHasChosenValidColor = MathHandler.TrySetCurrentColor(Input.GetSelectedColorId());
        }
    }
    while (!bHasChosenValidColor);
}
