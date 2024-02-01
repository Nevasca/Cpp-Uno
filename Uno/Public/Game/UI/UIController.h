#pragma once
#include "CardConsolePresenter.h"
#include "TurnConsolePresenter.h"
#include "Public/Game/ITurnEventListener.h"

class ITurnHandler;
class Player;
class IMatchHandler;

class UIController : public ITurnEventListener
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
    void ShowMinCardsForUnoWarning(uint8_t MinCardsRequired);
    void ShowAlreadyYelledUnoWarning();
    void ShowUnoYell();
    void ShowUnoNotYelledPenalty(const Player& Player, const std::vector<std::shared_ptr<Card>>& PenaltyCards);
    void HandleTurnFlowReversed() override;

private:

    static constexpr int SHOW_USED_CARD_MILLISECONDS_DELAY = 1000;
    static constexpr int SHOW_NO_CARDS_PENALTY_MILLISECONDS_DELAY = 2000;
    static constexpr int SHOW_UNO_NOT_YELLED_PENALTY_MILLISECONDS_DELAY = 2000;
    static constexpr int SHOW_TURN_REVERSED_MILLISECONDS_DELAY = 800;
    
    CardConsolePresenter CardPresenter{};
    TurnConsolePresenter TurnPresenter{};
};
