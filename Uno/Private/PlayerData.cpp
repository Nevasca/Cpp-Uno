#include "Public/PlayerData.h"

PlayerData::PlayerData(std::string&& InName, bool bInIsBot)
    : Name(std::move(InName)), bIsBot(bInIsBot)
{ }
