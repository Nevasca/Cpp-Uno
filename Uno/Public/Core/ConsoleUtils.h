#pragma once
#include <iostream>

class ConsoleUtils
{
public:

    static void Clear();

    template <typename TInput>
    static TInput GetInput()
    {
        TInput Input;
        std::cin >> Input;

        while(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            
            std::cin >> Input;
        }

        return Input;
    }
};
