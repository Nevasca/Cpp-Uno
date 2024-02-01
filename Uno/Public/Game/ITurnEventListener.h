#pragma once
#include "Public/Core/Core.h"

class ITurnEventListener
{
public:

    virtual void HandleTurnFlowReversed() = 0;
    virtual ~ITurnEventListener() = default;

    NO_COPY_MOVE(ITurnEventListener)

protected:

    ITurnEventListener() = default;
};
