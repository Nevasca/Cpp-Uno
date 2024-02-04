#pragma once

#include "IMatchHandler.h"
#include "Cards/DeckController.h"
#include "Match/Board.h"
#include "Public/PlayerData.h"
#include "Turn/TurnController.h"
#include "UI/UIController.h"

class Player;

class MatchController : public IMatchHandler
{
public:

    MatchController();
    void Initialize(std::vector<PlayerData>& JoinedPlayers);
    bool IsInitialized() const;
    void Start();
    void Update();
    bool IsMatchFinished() const;
    bool CanUseCard(const Card& Card) const override;
    bool CanUseAnyCard(const std::vector<std::shared_ptr<Card>>& Cards) const override;
    void SetMustUseCard(int16_t CardId) override;
    bool TryUsingCard(Player& Player, int CardIndex, bool bNotifyFailedAttempt = true) override;
    bool TryApplyPenalties(Player& Player) override;
    void UseCard(std::shared_ptr<Card>&& Card) override;
    bool TryYellUno(Player& Player, bool bNotifyFailedAttempt = true) override;
    void BuyCardsFor(Player& Player, uint16_t TotalCards) override;
    void DecideCurrentColor(Player& Player) override;
    bool TrySetCurrentColor(uint8_t ColorId, bool bNotifyFailedFailedAttempt = true) override;
    const std::shared_ptr<Card> PeekCurrentCard() const override;
    const std::shared_ptr<Player>& GetWinner() const;
    void Shutdown();

private:

    static constexpr int INITIAL_CARDS_PER_PLAYER = 7;
    static constexpr uint16_t TOTAL_BUY_CARDS_PENALTY = 1;
    static constexpr uint8_t MIN_CARDS_TO_YELL_UNO = 2;
    static constexpr uint8_t REQUIRED_CARDS_UNO_PENALTY = 1;
    static constexpr uint16_t TOTAL_BUY_CARDS_UNO_PENALTY = 2;
    
    std::vector<std::shared_ptr<Player>> Players{};
    bool bIsInitialized{false};
    bool bIsMatchFinished{false};
    DeckController DeckController;
    TurnController TurnController;
    Board Board{};
    UIController UIController{};
    std::shared_ptr<Player> Winner{};
    int16_t MustUseCardId{-1};

    void CreatePlayers(std::vector<PlayerData>& JoinedPlayers);
    void GiveInitialCardsToPlayers();
    void ApplyNoUsableCardPenalty(Player& Player);
    bool CanApplyUnoPenalty(const Player& Player) const;
    void ApplyUnoNotYelledPenalty(Player& Player);
    void ClearMustUseCard();
    bool CanChooseColor(EColor Color, const std::vector<EColor>& AvailableColors) const;
    bool HasPlayerWon(const Player& Player) const;
    void FinishMatchWithWinner(const std::shared_ptr<Player>& InWinner);
};
