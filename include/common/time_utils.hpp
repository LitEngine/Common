#pragma once

#include <chrono>
#include <queue>

namespace LiteEngine::Common {

    class Timer {
    public:
        Timer();

        void Step();

        double GetElapsedSinceStep();

        double GetElapsedSinceStart();

    private:
        std::chrono::time_point<std::chrono::system_clock, std::chrono::nanoseconds> prev_time;
        std::chrono::time_point<std::chrono::system_clock, std::chrono::nanoseconds> start_time;
    };

    class FpsMeter {
    public:
        FpsMeter() = default;

        void StartFrame();

        void EndFrame();

        double GetAverageFps() const;

        double GetAverageMsPerFrame() const;

    private:
        const int MAX_FRAMES_COUNT = 120;

        std::queue<double> times;

        Timer timer;

        bool frame_started = false;
    };

} // namespace LiteEngine::Common
