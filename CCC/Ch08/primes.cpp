// clang++ -std=c++17 -Wall -Wextra -pedantic primes.cpp prime_range.cpp prime_iterator.cpp -o primes

#include <cstdio>

#include "prime_range.h"

int main(void)
{
    for (const auto i : PrimeRange(100))
    {
        std::printf("%d, ", i);
    }
}
