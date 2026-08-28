#include <iostream>
#include <cstdarg>

template <typename T>
constexpr T sum_template(T x)
{
    return x;
}

template <typename T, typename... Args>
constexpr  T sum_template(T x, Args... args)
{
    return x + sum_template(args...);
}

template <typename... T>
constexpr auto sum_fold(T... args)
{
    return (... + args);
}

int sum(std::size_t n, ...)
{
    va_list args;
    va_start(args, n);
    int result{};
    while (n--)
    {
        auto next_element = va_arg(args, int);
        result += next_element;
    }
    va_end(args);
    return result;
}

int main(void)
{
    auto total{sum(6, 2, 4, 6, 8, 10, 12)};
    auto total_template{sum_template(2, 4, 6, 8, 10, 12)};
    auto total_fold{sum_fold(2, 4, 6, 8, 10, 12)};

    if ((total != total_template)
        || (total != total_fold))
    {
        std::cout << "WTAF?" << std::endl;
    }
    std::cout << total << " " << total_template << " " << total_fold << std::endl;
}
