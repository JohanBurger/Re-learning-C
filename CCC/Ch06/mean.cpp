// clang++ -std=c++17 -Wall -Wextra -pedantic mean.cpp -o mean

#include <concepts>
#include <cstddef>
#include <cstdio>
#include <type_traits>

// This requires C++20 concepts.
// template <typename T>
// concept Averageable = requires(T a, T b) {
//     { a + b } -> std::same_as<T>;
//     { a / std::size_t{1} } -> std::same_as<T>;
// };

// template <Averageable T>
// T mean(const T *values, std::size_t length)
// {
//     T sum = 0;
//     for (std::size_t i = 0; i < length; ++i)
//     {
//         sum += values[i];
//     }
//     return sum / length;
// }

template <typename T>
T mean(const T *values, std::size_t length)
{
    static_assert(std::is_default_constructible<T>(), "Type T must be default constructible");
    static_assert(std::is_copy_constructible<T>(), "Type T must be copy constructible");
    static_assert(std::is_arithmetic<T>(), "Type T must be an arithmetic type");
    static_assert(std::is_constructible<T, std::size_t>(), "Type T must be constructible from std::size_t");

    T sum{0};
    for (std::size_t i = 0; i < length; ++i)
    {
        sum += values[i];
    }
    return sum / length;
}

int main(void)
{
    const double nums_d[] = {1.0, 2.0, 3.0, 4.0};
    const auto result1 = mean(nums_d, sizeof(nums_d) / sizeof(nums_d[0]));
    std::printf("Mean of doubles: %f\n", result1);

    const float nums_f[] = {1.0f, 2.0f, 3.0f, 4.0f};
    const auto result2 = mean(nums_f, sizeof(nums_f) / sizeof(nums_f[0]));
    std::printf("Mean of floats: %f\n", result2);

    const std::size_t nums_s[] = {1, 2, 3, 4};
    const auto result3 = mean(nums_s, sizeof(nums_s) / sizeof(nums_s[0]));
    std::printf("Mean of size_t: %zu\n", result3);
}