#pragma once
#include <memory>

#include "TurnAction.h"
#include "Public/Core/Core.h"

class ITurnActionHandler
{
public:

    virtual void AddPreTurnAction(std::unique_ptr<TurnAction>&& InAction) = 0;
    virtual void AddPostTurnAction(std::unique_ptr<TurnAction>&& InAction) = 0;

    virtual ~ITurnActionHandler() = default;
    
    NO_COPY_MOVE(ITurnActionHandler)
    
protected:
    ITurnActionHandler() = default;
};
