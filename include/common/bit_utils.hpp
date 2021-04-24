#pragma once

#include <type_traits>
#include <cstdint>

namespace LiteEngine::Common {

    /// Returns (2^k) where k - the smallest power of two that is not less than n
    template<typename T, std::enable_if_t<std::is_integral<T_>::value> * = nullptr>
    inline T NextPowerOfTwo(T n) {
        --n;
        n |= (n >> 1);
        n |= (n >> 2);
        n |= (n >> 4);
        if (sizeof(T) > 1) n |= (n >> 8);
        if (sizeof(T) > 2) n |= (n >> 16);
        if (sizeof(T) > 4) n |= (n >> 32);
        return ++n;
    }

    /// Returns (k) where k - the smallest power of two that is not less than n
    template<typename T, std::enable_if_t<std::is_integral<T_>::value> * = nullptr>
    inline uint32_t NextPowerOfTwoLog2(T n) {
        uint32_t res = 0;
        n--;
        if (n >> 31) {
            n >>= 32;
            res |= 32;
        }
        if (n >> 15) {
            n >>= 16;
            res |= 16;
        }
        if (n >> 7) {
            n >>= 8;
            res |= 8;
        }
        if (n >> 3) {
            n >>= 4;
            res |= 4;
        }
        if (n >> 1) {
            n >>= 2;
            res |= 2;
        }
        if (n) res++;
        return res;
    }

} // namespace LiteEngine::Common