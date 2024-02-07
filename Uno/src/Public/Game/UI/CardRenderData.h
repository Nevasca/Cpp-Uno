#pragma once

class Card;

struct CardRenderData
{
    const Card& CardToRender;
    bool bCanBeUsed;

    CardRenderData(const Card& InCard, bool bInCanBeUsed);
};
