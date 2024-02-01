#include "Public/Game/Players/HumanPlayer.h"

#include <iostream>

#include "Public/Game/IMatchHandler.h"

HumanPlayer::HumanPlayer(std::string&& InName)
    : Player(std::move(InName))
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
