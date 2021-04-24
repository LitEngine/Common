#include <common/time_utils.hpp>
#include <iostream>

using namespace LiteEngine::Common;

typedef std::chrono::duration<double, std::ratio<1> > second_;

Timer::Timer() {
    start_time = prev_time = std::chrono::high_resolution_clock::now();
}

void Timer::Step() {
    prev_time = std::chrono::high_resolution_clock::now();
}

double Timer::GetElapsedSinceStep() {
    auto cur_time = std::chrono::high_resolution_clock::now();
    auto delta = std::chrono::duration_cast<second_>(cur_time - prev_time).count();
    return delta;
}

double Timer::GetElapsedSinceStart() {
    return std::chrono::duration_cast<second_>(std::chrono::high_resolution_clock::now() - start_time).count();
}

double FpsMeter::GetAverageFps() const {
    if (times.empty()) {
        return 0;
    }
    return times.size() / (times.back() - times.front());
}

double FpsMeter::GetAverageMsPerFrame() const {
    if (times.empty()) {
        return 0;
    }
    return  (times.back() - times.front()) / times.size() * 1000.0;
}

void FpsMeter::StartFrame() {
    if (frame_started) {
        EndFrame();
    }
    frame_started = true;
    timer.Step();
}

void FpsMeter::EndFrame() {
    double time = timer.GetElapsedSinceStep();
    while(times.size() > MAX_FRAMES_COUNT) {
        times.pop();
    }
    times.push((times.empty() ? 0 : times.back()) + time);
    frame_started = false;
}
