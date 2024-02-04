#pragma once
#include "PlayerConsoleInput.h"
#include "Public/Game/Player.h"

class HumanPlayer : public Player
{
public:

    HumanPlayer(std::string&& InName);
    void PlayTurn(IMatchHandler& MatchHandler) override;
    void ChooseColor(IMatchHandler& MathHandler) override;
    ~HumanPlayer() = default;

private:

    PlayerConsoleInput Input{};
};
