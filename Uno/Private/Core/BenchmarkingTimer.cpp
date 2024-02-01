#include "Public/Core/BenchmarkingTimer.h"

#include <iostream>

BenchmarkingTimer::BenchmarkingTimer()
{
    StartTimePoint = std::chrono::high_resolution_clock::now();
}

BenchmarkingTimer::~BenchmarkingTimer()
{
    auto EndPoint = std::chrono::high_resolution_clock::now();

    auto Duration = std::chrono::duration_cast<std::chrono::microseconds>(EndPoint - StartTimePoint).count();
    auto DurationInMs = Duration * 0.001;

    std::cout << Duration << "us (" << DurationInMs << "ms)\n";
}
