#include "Public/Game/Player.h"

Player::Player(std::string&& InName)
    : Name(std::move(InName))
{ }

const std::string& Player::GetName() const
{
    return Name;
}

void Player::SetCards(std::vector<std::shared_ptr<Card>>&& InCards)
{
    Cards.clear();
    Cards = std::move(InCards);
}

void Player::GiveCard(std::shared_ptr<Card>&& Card)
{
    Cards.emplace_back(std::move(Card));
}

size_t Player::GetTotalCards() const
{
    return Cards.size();
}

const std::vector<std::shared_ptr<Card>>& Player::GetCards() const
{
    return Cards;
}
