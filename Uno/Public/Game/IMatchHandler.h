#pragma once
#include "Public/Core/Core.h"

class Card;

class IMatchHandler
{
public:

    virtual bool CanUseCard(const Card& DesiredCard) const = 0;
    virtual const std::shared_ptr<Card> PeekCurrentCard() const = 0;
    virtual ~IMatchHandler() = default;

    NO_COPY_MOVE(IMatchHandler)

protected:

    IMatchHandler() = default;
};
