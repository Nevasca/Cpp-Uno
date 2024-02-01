#include "Public/Game/Players/PlayerConsoleInput.h"

#include "Public/Core/ConsoleUtils.h"

void PlayerConsoleInput::Process()
{
    ClearInput();
    
    const int RawInput = ConsoleUtils::GetInput<int>();

    if(RawInput >= 0)
    {
        bHasSelectedACard = true;
        SelectedCardIndex = RawInput;
    }
}

bool PlayerConsoleInput::HasSelectedACard() const
{
    return bHasSelectedACard;
}

int PlayerConsoleInput::GetSelectedCardIndex() const
{
    return SelectedCardIndex;
}

void PlayerConsoleInput::ClearInput()
{
    bHasSelectedACard = false;
    SelectedCardIndex = -1;
}
