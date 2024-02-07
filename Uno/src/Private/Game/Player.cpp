#include "Public/Game/Player.h"

Player::Player(std::string&& InName, bool bInIsLocalPlayer)
    : Name(std::move(InName)), bIsLocalPlayer(bInIsLocalPlayer)
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

void Player::GiveCards(std::vector<std::shared_ptr<Card>>& InCards)
{
    Cards.reserve(Cards.size() + InCards.size());

    for(std::shared_ptr<Card>& Card : InCards)
    {
        GiveCard(std::move(Card));
    }
}

size_t Player::GetTotalCards() const
{
    return Cards.size();
}

const std::vector<std::shared_ptr<Card>>& Player::GetCards() const
{
    return Cards;
}

const Card& Player::PeekCard(int CardIndex) const
{
    return *Cards[CardIndex];
}

std::shared_ptr<Card> Player::TakeCard(int CardIndex)
{
    std::shared_ptr<Card> Card = Cards[CardIndex];
    Cards.erase(Cards.begin() + CardIndex);

    return Card;
}

bool Player::HasYelledUno() const
{
    return bHasYelledUno;
}

void Player::SetHasYelledUno(bool bInHasYelledUno)
{
    bHasYelledUno = bInHasYelledUno;
}

bool Player::IsLocalPlayer() const
{
    return bIsLocalPlayer;
}
