#pragma once
#include <assert.h>
#include <memory>
#include <vector>

class IState;

class StateMachine
{
public:

    StateMachine() = default;
    StateMachine(std::vector<std::shared_ptr<IState>>&& InStates);
    void Update();
    bool IsRunning() const;
    void Stop();
    void SetState(std::shared_ptr<IState>&& State);

    template <typename TState, typename = std::enable_if_t<std::is_base_of_v<IState, TState>>>
    void SetState()
    {
        std::shared_ptr<TState> DesiredState = GetState<TState>();

        assert(DesiredState);
        SetState(std::move(DesiredState));
    }

private:

    std::vector<std::shared_ptr<IState>> States{};
    std::shared_ptr<IState> CurrentState{};

    template <typename TState, typename = std::enable_if_t<std::is_base_of_v<IState, TState>>>
    std::shared_ptr<TState> GetState()
    {
        for(std::shared_ptr<IState>& State : States)
        {
            std::shared_ptr<TState> CastedState = std::dynamic_pointer_cast<TState>(State);

            if(CastedState)
            {
                return CastedState;
            }
        }
        
        return nullptr;
    }
};
