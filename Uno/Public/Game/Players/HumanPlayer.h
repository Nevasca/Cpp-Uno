#pragma once
#include "PlayerConsoleInput.h"
#include "Public/Game/Player.h"

class HumanPlayer : public Player
{
public:

    HumanPlayer(std::string&& InName);
    void PlayTurn(IMatchHandler& MatchHandler) override;
    ~HumanPlayer() = default;

private:

    PlayerConsoleInput Input{};

    bool IsCardChoiceValid(const IMatchHandler& MatchHandler, int CardIndex) const;
    std::shared_ptr<Card> TakeCard(int CardIndex);
    void UseCard(IMatchHandler& MatchHandler, int CardIndex);
};
