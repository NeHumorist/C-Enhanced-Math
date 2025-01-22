#pragma once

#include <cstdlib>
#include <ctime>
#include <cmath>

namespace Math {

    constexpr double PI_D = 3.141592653589793;
    constexpr float PI_F = 3.1415927f;

    constexpr double E_D = 2.718281828459045;
    constexpr float E_F = 2.7182817f;

    constexpr double TO_RADIAN_D = PI_D / 180.0;
    constexpr float TO_RADIAN_F = PI_F / 180.0f;

    constexpr double TO_DEGREE_D = 180.0 / PI_D;
    constexpr float TO_DEGREE_F = 180.0f / PI_F;

    inline double Random(double min, double max) {
        static bool initialized = false;
        if (!initialized) {
            std::srand(static_cast<unsigned int>(std::time(nullptr)));
            initialized = true;
        }
        return min + (max - min) * (static_cast<double>(std::rand()) / RAND_MAX);
    }

    template <typename T>
    constexpr T Clamp(T value, T min, T max) {
        return (value < min) ? min : (value > max ? max : value);
    }

    template <typename T>
    constexpr T Lerp(T a, T b, T t) {
        return a + t * (b - a);
    }

    template <typename T>
    constexpr T SmoothStep(T a, T b, T t) {
        T normT = (t - a) / (b - a);
        normT = Clamp(normT, T(0), T(1));
        return normT * normT * (T(3) - T(2) * normT);
    }

    template <typename T>
    constexpr T Wrap(T value, T min, T max) {
        T range = max - min;
        T result = std::fmod(value - min, range);
        return (result < 0) ? result + max : result + min;
    }

    constexpr double sqrt_constexpr(double x, double guess = 1.0) {
        return (std::fabs(guess * guess - x) < 0.0001) ? guess : sqrt_constexpr(x, (guess + x / guess) / 2.0);
    }

    constexpr double Hypotenuse(double a, double b) {
        return sqrt_constexpr(a * a + b * b);
    }

    inline double AngleBetweenVectors(double x1, double y1, double x2, double y2) {
        double dotProduct = x1 * x2 + y1 * y2;
        double magnitude1 = std::sqrt(x1 * x1 + y1 * y1);
        double magnitude2 = std::sqrt(x2 * x2 + y2 * y2);
        return std::acos(dotProduct / (magnitude1 * magnitude2));
    }

    template <typename T>
    constexpr T Distance(T x1, T y1, T x2, T y2) {
        T dx = x2 - x1;
        T dy = y2 - y1;
        return std::sqrt(dx * dx + dy * dy);
    }

    template <typename T>
    constexpr T Round(T value) {
        return (value >= 0) ? static_cast<T>(value + 0.5) : static_cast<T>(value - 0.5);
    }

    constexpr double DegToRad(double degrees) {
        return degrees * TO_RADIAN_D;
    }

    constexpr float DegToRad(float degrees) {
        return degrees * TO_RADIAN_F;
    }

    constexpr double RadToDeg(double radians) {
        return radians * TO_DEGREE_D;
    }

    constexpr float RadToDeg(float radians) {
        return radians * TO_DEGREE_F;
    }
}