#include "Public/Core/Random.h"

#include <ctime>

unsigned int Random::CurrentSeed = 0;

void Random::SetCustomSeed(unsigned int Seed)
{
    CurrentSeed = Seed;
}

void Random::SetRandomSeed()
{
    CurrentSeed = static_cast<unsigned int>(time(nullptr));
}

unsigned int Random::GetSeed()
{
    return CurrentSeed;
}

std::default_random_engine Random::GetRandomEngine()
{
    return std::default_random_engine{Random::CurrentSeed};
}
