#include "Public/Game/Players/AIPlayer.h"

#include <cassert>

#include "Public/Game/Card.h"
#include "Public/Game/IMatchHandler.h"

AIPlayer::AIPlayer(std::string&& InName, bool bInIsLocalPlayer)
    : Player(std::move(InName), bInIsLocalPlayer)
{ }

void AIPlayer::PlayTurn(IMatchHandler& MatchHandler)
{
    MatchHandler.TryYellUno(*this, false);

    ChooseCard(MatchHandler);
}

void AIPlayer::ChooseCard(IMatchHandler& MatchHandler)
{
    bool bAIHasChosenACard = false;

    for(int i = 0; i < static_cast<int>(Cards.size()); i++)
    {
        if(MatchHandler.TryUsingCard(*this, i, false))
        {
            bAIHasChosenACard = true;
            break;
        }
    }

    assert(bAIHasChosenACard);
}

void AIPlayer::ChooseColor(IMatchHandler& MatchHandler, const std::vector<EColor>& AvailableColors)
{
    bool bAIHasChosenAColor = false;
    
    for(const std::shared_ptr<Card>& Card : Cards)
    {
        const uint8_t CardColorId = static_cast<uint8_t>(Card->GetColor());

        if(MatchHandler.TrySetCurrentColor(CardColorId, false))
        {
            bAIHasChosenAColor = true;
            break;
        }
    }

    assert(bAIHasChosenAColor);
}