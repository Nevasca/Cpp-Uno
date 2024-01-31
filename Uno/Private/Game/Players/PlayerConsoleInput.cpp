#include "Public/Game/Players/PlayerConsoleInput.h"

#include "Public/Core/ConsoleUtils.h"

void PlayerConsoleInput::Process()
{
    ClearInput();
    
    const int RawInput = ConsoleUtils::GetInput<int>();

    if(RawInput >= 0)
    {
        bHasSelectedCard = true;
        SelectedCardIndex = RawInput;
    }
}

bool PlayerConsoleInput::HasSelectedCard() const
{
    return bHasSelectedCard;
}

int PlayerConsoleInput::GetSelectedCardIndex() const
{
    return SelectedCardIndex;
}

void PlayerConsoleInput::ClearInput()
{
    bHasSelectedCard = false;
    SelectedCardIndex = -1;
}
