#pragma once
#include "PlayerConsoleInput.h"
#include "Public/Game/Player.h"

class HumanPlayer : public Player
{
public:

    HumanPlayer(std::string&& InName, bool bInIsLocalPlayer = true);
    void PlayTurn(IMatchHandler& MatchHandler) override;
    void ChooseColor(IMatchHandler& MathHandler, const std::vector<EColor>& AvailableColors) override;
    ~HumanPlayer() = default;

private:

    PlayerConsoleInput Input{};
};
