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
    void ShowBoughtCards(const Player& Player, const std::vector<std::shared_ptr<Card>>& BoughtCards);
    void HandleTurnFlowReversed() override;
    void HandleTurnJumped(const Player& Player) override;

private:

    static constexpr int SHOW_USED_CARD_MILLISECONDS_DELAY = 1000;
    static constexpr int SHOW_NO_CARDS_PENALTY_MILLISECONDS_DELAY = 2000;
    static constexpr int SHOW_UNO_NOT_YELLED_PENALTY_MILLISECONDS_DELAY = 2000;
    static constexpr int SHORT_MESSAGE_MILLISECONDS_DELAY = 800;
    static constexpr int MEDIUM_MESSAGE_MILLISECONDS_DELAY = 1500;
    static constexpr int LONG_MESSAGE_MILLISECONDS_DELAY = 2200;
    
    CardConsolePresenter CardPresenter{};
    TurnConsolePresenter TurnPresenter{};
};
