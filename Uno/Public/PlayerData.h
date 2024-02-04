#pragma once
#include <string>

struct PlayerData
{
    std::string Name{};
    bool bIsBot{false};

    PlayerData(std::string&& InName, bool bInIsBot);
};
