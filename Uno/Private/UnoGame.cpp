#include "Public/UnoGame.h"

#include <memory>

#include "Public/Core/Random.h"
#include "Public/Game/MatchState.h"
#include "Public/MainMenu/MainMenuState.h"

void UnoGame::Start()
{
    Random::SetRandomSeed();

    CreateGameStates();
    StateMachine.SetState<MainMenuState>();
}

void UnoGame::CreateGameStates()
{
    constexpr int TotalGameStates = 2;

    std::vector<std::shared_ptr<IState>> GameStates{};
    GameStates.reserve(TotalGameStates);

    GameStates.emplace_back(std::make_shared<MainMenuState>());
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
