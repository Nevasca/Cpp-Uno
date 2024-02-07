#pragma once
#include "Public/Game/Player.h"

class AIPlayer : public Player
{
public:

    AIPlayer(std::string&& InName, bool bInIsLocalPlayer = false);
    void PlayTurn(IMatchHandler& MatchHandler) override;
    void ChooseColor(IMatchHandler& MatchHandler, const std::vector<EColor>& AvailableColors) override;

private:

    void ChooseCard(IMatchHandler& MatchHandler);
};
