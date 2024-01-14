#include "Public/UnoGame.h"

#include <memory>

#include "Public/Game/MatchState.h"

void UnoGame::Start()
{
    CreateGameStates();
    StateMachine.SetState<MatchState>();
}

void UnoGame::CreateGameStates()
{
    constexpr int TotalGameStates = 1;

    std::vector<std::shared_ptr<IState>> GameStates{};
    GameStates.reserve(TotalGameStates);

    GameStates.emplace_back(std::make_shared<MatchState>());

    StateMachine = {std::move(GameStates)};
}

bool UnoGame::IsRunning() const
{
    return StateMachine.IsRunning();
}

void UnoGame::Update()
{
    StateMachine.Update();
}
