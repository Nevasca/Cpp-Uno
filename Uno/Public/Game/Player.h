#pragma once
#include <memory>
#include <string>
#include <vector>

#include "Public/Core/Core.h"

class IMatchHandler;
class Card;

class Player
{
public:

    virtual void PlayTurn(IMatchHandler& MatchHandler) = 0;
    const std::string& GetName() const;
    void SetCards(std::vector<std::shared_ptr<Card>>&& InCards);
    void GiveCard(std::shared_ptr<Card>&& Card);
    size_t GetTotalCards() const;
    const std::vector<std::shared_ptr<Card>>& GetCards() const;
    virtual ~Player() = default;
    
    NO_COPY_MOVE(Player)

protected:

    std::string Name{};
    std::vector<std::shared_ptr<Card>> Cards{};

    Player() = default;
    explicit Player(std::string&& InName);
};
