#pragma once
#include <random>

class Random
{
public:

    static void SetCustomSeed(unsigned int Seed);
    static void SetRandomSeed();
    static unsigned int GetSeed();
    static std::default_random_engine GetRandomEngine();

private:
    
    static unsigned int CurrentSeed;
};
