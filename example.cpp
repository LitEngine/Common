#include <common/time_utils.hpp>
#include <common/logging.hpp>
#include <common/assert.hpp>

using namespace LiteEngine::Common;

void ExampleTime() {
    Timer timer;

    timer.Step();
    // perform operation 1
    double op1_time = timer.GetElapsedSinceStep();

    timer.Step();
    // perform operation 2
    double op2_time = timer.GetElapsedSinceStep();

    FpsMeter fps;

    for(int i = 0; i < 9999; i++) {
        fps.StartFrame();
        // frame rendering
        fps.EndFrame();
    }

    double average_fps = fps.GetAverageFps();
    double average_ms = fps.GetAverageMsPerFrame();
}

void ExampleLogging() {
    Logger::LogInfo("Some information %d", 5);
    Logger::LogWarning("Warning!!! 2+2!=%d", 4);
    Logger::LogError("Error!");
}

void ExampleAssert() {
    ENGINE_ASSERT(2 + 2 == 4, "2 + 2 should be 4")
    int x = 5, y = 7, z = x + y;
    ENSURE_THAT(x + y == z)
    ENSURE_THAT_EQ(x, 5)
    ENSURE_THAT_BETWEEN(x, 4, 7)
}

int main() {
    ExampleTime();
    ExampleLogging();
    ExampleAssert();
}