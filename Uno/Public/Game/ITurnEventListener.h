#pragma once
#include "Public/Core/Core.h"

class Player;

class ITurnEventListener
{
public:

    virtual void HandleTurnFlowReversed() = 0;
    virtual void HandleTurnJumped(const Player& Player) = 0;
    virtual ~ITurnEventListener() = default;

    NO_COPY_MOVE(ITurnEventListener)

protected:

    ITurnEventListener() = default;
};
