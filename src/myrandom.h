#ifndef MYRANDOM_H
#define MYRANDOM_H

#include <random>

namespace random {
    static std::mt19937 gen{ std::random_device{}() };
    inline namespace templates {
        template<typename T>
        inline T number(T min, T max) noexcept {
            return std::uniform_int_distribution<T>{min, max}(gen);
        }

        template<typename T>
        inline T duration(T min, T max) noexcept {
            return number<T>(min, max);
        }
    }
}
#endif // MYRANDOM_H
