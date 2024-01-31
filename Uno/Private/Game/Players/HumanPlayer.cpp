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

        if(Input.HasSelectedCard() && IsCardChoiceValid(MatchHandler, Input.GetSelectedCardIndex()))
        {
            UseCard(MatchHandler, Input.GetSelectedCardIndex());
            bHasMadeValidInput = true;
        }
    }
    while (!bHasMadeValidInput);
}

bool HumanPlayer::IsCardChoiceValid(const IMatchHandler& MatchHandler, int CardIndex) const
{
    if(CardIndex >= static_cast<int>(Cards.size()))
    {
        return false;
    }

    return MatchHandler.CanUseCard(*Cards[CardIndex]);
}

std::shared_ptr<Card> HumanPlayer::TakeCard(int CardIndex)
{
    std::shared_ptr<Card> Card = Cards[CardIndex];
    Cards.erase(Cards.begin() + CardIndex);

    return Card;
}

void HumanPlayer::UseCard(IMatchHandler& MatchHandler, int CardIndex)
{
    std::shared_ptr<Card> Card = TakeCard(CardIndex);
    MatchHandler.UseCard(std::move(Card));
}
