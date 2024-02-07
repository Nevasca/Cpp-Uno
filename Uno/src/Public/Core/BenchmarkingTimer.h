#pragma once
#include <chrono>

class BenchmarkingTimer
{
public:

    BenchmarkingTimer();
    ~BenchmarkingTimer();

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> StartTimePoint;
};
