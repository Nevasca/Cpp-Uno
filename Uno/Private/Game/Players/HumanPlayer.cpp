#include "Public/Game/Players/HumanPlayer.h"

#include <iostream>

#include "Public/Game/IMatchHandler.h"

HumanPlayer::HumanPlayer(std::string&& InName)
    : Player(std::move(InName))
{ }

void HumanPlayer::PlayTurn(IMatchHandler& MatchHandler)
{
    bool bHasMadeValidInput = false;

    do
    {
        Input.Process();

        if(Input.HasSelectedACard() && MatchHandler.TryUsingCard(*this, Input.GetSelectedCardIndex()))
        {
            bHasMadeValidInput = true;
        }
    }
    while (!bHasMadeValidInput);
}
