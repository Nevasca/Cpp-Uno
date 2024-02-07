#pragma once
#include "Public/Core/Core.h"

#include <memory>
#include <vector>

class Player;
class Card;

class IMatchHandler
{
public:

    virtual bool CanUseCard(const Card& DesiredCard) const = 0;
    virtual bool CanUseAnyCard(const std::vector<std::shared_ptr<Card>>& Cards) const = 0;
    virtual void SetMustUseCard(int16_t CardId) = 0;
    virtual bool TryUsingCard(Player& Player, int CardIndex, bool bNotifyFailedAttempt = true) = 0;
    virtual bool TryApplyPenalties(Player& Player) = 0;
    virtual void UseCard(std::shared_ptr<Card>&& Card) = 0;
    virtual const std::shared_ptr<Card> PeekCurrentCard() const = 0;
    virtual bool TryYellUno(Player& Player, bool bNotifyFailedAttempt = true) = 0;
    virtual void BuyCardsFor(Player& Player, uint16_t TotalCards) = 0;
    virtual void DecideCurrentColor(Player& Player) = 0;
    virtual bool TrySetCurrentColor(uint8_t ColorId, bool bNotifyFailedFailedAttempt = true) = 0;
    virtual ~IMatchHandler() = default;

    NO_COPY_MOVE(IMatchHandler)

protected:

    IMatchHandler() = default;
};
