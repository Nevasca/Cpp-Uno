#include "Public/Game/UI/CardRenderData.h"

CardRenderData::CardRenderData(const Card& InCard, bool bInCanBeUsed)
    : CardToRender(InCard), bCanBeUsed(bInCanBeUsed)
{ }
