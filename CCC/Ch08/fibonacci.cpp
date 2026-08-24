// clang++ -std=c++17 -Wall -Wextra -pedantic fibonacci.cpp fibonacci_range.cpp fibonacci_iterator.cpp -o fibonacci

#include <cstdio>

#include "fibonacci_range.h"

int main(void)
{
    for (const auto i : FibonacciRange{5000})
    {
        std::printf("%d ", i);
    }
}