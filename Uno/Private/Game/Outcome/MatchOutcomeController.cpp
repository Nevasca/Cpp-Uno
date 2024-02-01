#include "Public/Game/Outcome/MatchOutcomeController.h"

MatchOutcomeController::MatchOutcomeController(const std::shared_ptr<Player>& InWinner)
    : Winner(InWinner)
{ }

void MatchOutcomeController::Start()
{
    UIController.ShowWinner(*Winner);
}

void MatchOutcomeController::Update()
{
    UIController.ShowExitMessage();
    Input.Process();

    bIsExitRequested = Input.HasPressedExit();
}

void MatchOutcomeController::Shutdown()
{
    Winner.reset();
}

bool MatchOutcomeController::IsExitRequested() const
{
    return bIsExitRequested;
}
