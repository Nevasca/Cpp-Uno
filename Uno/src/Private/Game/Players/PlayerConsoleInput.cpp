#include "Public/Game/Players/PlayerConsoleInput.h"

#include "Public/Core/ConsoleUtils.h"

void PlayerConsoleInput::Process()
{
    ClearInput();
    
    const int RawInput = ConsoleUtils::GetInput<int>();

    if(RawInput == YELL_UNO_INPUT)
    {
        bHasYelledUno = true;
        return;
    }
    
    if(RawInput < 0)
    {
        return;
    }

    bHasSelectedACard = true;
    SelectedCardIndex = RawInput;

    bHasSelectedAColor = true;
    SelectedColorId = static_cast<uint8_t>(RawInput);
}

bool PlayerConsoleInput::HasSelectedACard() const
{
    return bHasSelectedACard;
}

int PlayerConsoleInput::GetSelectedCardIndex() const
{
    return SelectedCardIndex;
}

bool PlayerConsoleInput::HasYelledUno() const
{
    return bHasYelledUno;
}

bool PlayerConsoleInput::HasSelectedAColor() const
{
    return bHasSelectedAColor;
}

uint8_t PlayerConsoleInput::GetSelectedColorId() const
{
    return SelectedColorId;
}

void PlayerConsoleInput::ClearInput()
{
    bHasSelectedACard = false;
    SelectedCardIndex = -1;
    bHasYelledUno = false;
    bHasSelectedAColor = false;
    SelectedColorId = 0;
}
