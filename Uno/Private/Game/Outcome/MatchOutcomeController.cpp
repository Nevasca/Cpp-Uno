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
    UIController.ShowExitMessage(OutcomeConsoleInput::RESTART_INPUT_NAME, OutcomeConsoleInput::QUIT_INPUT_NAME);
    Input.Process();

    bIsRestartRequested = Input.HasPressedRestarted();
    bIsExitRequested = Input.HasPressedExit();
}

void MatchOutcomeController::Shutdown()
{
    Winner.reset();
    bIsRestartRequested = false;
    bIsExitRequested = false;
}

bool MatchOutcomeController::IsExitRequested() const
{
    return bIsExitRequested;
}

bool MatchOutcomeController::IsRestartRequested() const
{
    return bIsRestartRequested;
}
