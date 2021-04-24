# LiteEngine.Common

This library contains a set of commonly used across LiteEngine project classes and functions: 
logging, bit utils, timer utils, image i/o, custom asserts etc.

- Asserts `ENGINE_ASSERT(condition, msg)`, `ENSURE_THAT(condition)`, `ENSURE_THAT_EQ(expr, val)`, 
  `ENSURE_THAT_BETWEEN(expr, lo, hi)`
- Timer utils `Timer` and `FpsMeter` classes
- Logging `Logger` class, with `LogInfo(msg, ...args)`, `LogWarning(msg, ...args)` and `LogError(msg, ...args)` methods

```cpp
using namespace LiteEngine::Common;

// Asserts
ENSURE_THAT(2 + 2 == 4);

// Logging
Logger::LogInfo("2 + 2 = %d", 2 + 2);

// Time utils
Timer timer; // timer started
// some operations
timer.Step();
// more operations
timer.GetElapsedSinceStep(); // in seconds
timer.GetElapsedSinceStart(); // in seconds
```