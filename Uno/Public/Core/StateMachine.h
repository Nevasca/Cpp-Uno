#pragma once
#include <assert.h>
#include <memory>
#include <vector>

#include "IState.h"

class StateMachine
{
public:

    StateMachine() = default;
    StateMachine(std::vector<std::shared_ptr<IState>>&& InStates);
    void Update();
    bool IsRunning() const;
    void Stop();
    void SetState(const std::shared_ptr<IState>& State);

    template <typename TState, typename = std::enable_if_t<std::is_base_of_v<IState, TState>>>
    void SetState()
    {
        std::shared_ptr<TState> DesiredState = GetState<TState>();

        assert(DesiredState);
        SetState(DesiredState);
    }

    template<typename TState, typename = std::enable_if<std::is_base_of_v<IState, TState>>>
    void AddState(std::shared_ptr<TState>&& InState, bool bSetAsCurrent)
    {
        RemoveState<TState>();
        States.emplace_back(InState);

        if(bSetAsCurrent)
        {
            SetState(States.back());
        }
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

    template <typename TState, typename = std::enable_if_t<std::is_base_of_v<IState, TState>>>
    void RemoveState()
    {
        int ExistingStateIndex = -1;

        for(int i = 0; i < States.size(); i++)
        {
            std::shared_ptr<TState> CastedState = std::dynamic_pointer_cast<TState>(States[i]);

            if(CastedState)
            {
                ExistingStateIndex = i;
            }
        }

        if(ExistingStateIndex <= -1)
        {
            return;
        }
        
        if(CurrentState == States[ExistingStateIndex])
        {
            CurrentState->Exit();
            CurrentState = nullptr;
        }
            
        States.erase(States.begin() + ExistingStateIndex);
    }
};
