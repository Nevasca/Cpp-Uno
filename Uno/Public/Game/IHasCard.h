#pragma once
#include <memory>
#include <vector>

#include "Public/Core/Core.h"

class Card;

class IHasCard
{
public:

    virtual std::vector<std::shared_ptr<Card>> TakeAllCards() = 0;
    virtual ~IHasCard() = default;
    
    NO_COPY_MOVE(IHasCard)

protected:

    IHasCard() = default;
};
