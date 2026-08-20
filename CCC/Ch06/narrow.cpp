// clang++ -std=c++17 -Wall -Wextra -pedantic narrow.cpp -o narrow

#include <cstdio>
#include <stdexcept>

template <typename To, typename From>
To narrow_cast(From value)
{
    To result = static_cast<To>(value);
    if (static_cast<From>(result) != value)
    {
        throw std::runtime_error("Narrowing conversion error");
    }
    return result;
}

int main(void)
{

    int perfect{496};
    const auto short_perfect = narrow_cast<short>(perfect);
    std::printf("Narrowed value: %d\n", short_perfect);
    try
    {
        int cyclic{142857};
        const auto short_cyclic = narrow_cast<short>(cyclic);
        std::printf("Narrowed value: %d\n", short_cyclic);
    }
    catch (const std::runtime_error &e)
    {
        std::printf("Caught exception: %s\n", e.what());
    }

    return 0;
}