#pragma once
#include <memory>
#include <string>
#include <vector>

#include "EColor.h"
#include "Public/Core/Core.h"

class IMatchHandler;
class Card;

class Player
{
public:

    virtual void PlayTurn(IMatchHandler& MatchHandler) = 0;
    virtual void ChooseColor(IMatchHandler& MathHandler, const std::vector<EColor>& AvailableColors) = 0;
    const std::string& GetName() const;
    void SetCards(std::vector<std::shared_ptr<Card>>&& InCards);
    void GiveCard(std::shared_ptr<Card>&& Card);
    void GiveCards(std::vector<std::shared_ptr<Card>>& InCards);
    size_t GetTotalCards() const;
    const std::vector<std::shared_ptr<Card>>& GetCards() const;
    const Card& PeekCard(int CardIndex) const;
    std::shared_ptr<Card> TakeCard(int CardIndex);
    bool HasYelledUno() const;
    void SetHasYelledUno(bool bInHasYelledUno);
    bool IsLocalPlayer() const;
    virtual ~Player() = default;
    
    NO_COPY_MOVE(Player)

protected:

    std::string Name{};
    std::vector<std::shared_ptr<Card>> Cards{};
    bool bHasYelledUno{false};

    Player() = default;
    explicit Player(std::string&& InName, bool bInIsLocalPlayer);

private:

    bool bIsLocalPlayer{true};
};
