#pragma once
#include "CardConsolePresenter.h"
#include "TurnConsolePresenter.h"

class ITurnHandler;
class Player;
class IMatchHandler;

class UIController
{
public:

    void Clear();
    void ShowCurrentTurn(const IMatchHandler& MatchHandler, const ITurnHandler& TurnHandler);
    void ShowPlayerHand(const IMatchHandler& MatchHandler, const Player& Player);
    void ShowAvailableCommands();
    void ShowUsedCard(const Card& Card, const Player& Player);
    void ShowNoCardsPenalty(const Player& Player, const std::vector<std::shared_ptr<Card>>& PenaltyCards);
    void ShowInvalidCardWarning();
    void ShowCantUseCardWarning();

private:

    static constexpr int SHOW_USED_CARD_MILLISECONDS_DELAY = 1000;
    static constexpr int SHOW_NO_CARDS_PENALTY_MILLISECONDS_DELAY = 2000;
    
    CardConsolePresenter CardPresenter{};
    TurnConsolePresenter TurnPresenter{};
};
