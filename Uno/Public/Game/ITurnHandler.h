#pragma once
#include <cstdint>
#include <memory>
#include <vector>

#include "Public/Core/Core.h"
#include "ETurnFlow.h"

class Player;

class ITurnHandler
{
public:

    virtual uint32_t GetCurrentTurnIndex() const = 0;
    virtual const std::vector<std::shared_ptr<Player>>& GetOrderedPlayers() const = 0;
    virtual ETurnFlow GetCurrentFlow() const = 0;
    virtual const std::shared_ptr<Player>& PeekCurrentPlayer() const = 0;
    virtual void ReverseFlow() = 0;
    virtual ~ITurnHandler() = default;
    
    NO_COPY_MOVE(ITurnHandler)

protected:

    ITurnHandler() = default;
};
