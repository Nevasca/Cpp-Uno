﻿#pragma once
#include <memory>

#include "OutcomeConsoleInput.h"
#include "UI/UIMatchOutcomeController.h"

class Player;

class MatchOutcomeController
{
public:

    MatchOutcomeController(const std::shared_ptr<Player>& InWinner);
    void Start();
    void Update();
    void Shutdown();
    bool IsExitRequested() const;

private:

    std::shared_ptr<Player> Winner{};
    bool bIsExitRequested{false};
    UIMatchOutcomeController UIController{};
    OutcomeConsoleInput Input{};
};
