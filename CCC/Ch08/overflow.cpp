// clang++ -std=c++17 -Wall -Wextra -pedantic overflow.cpp -o overflow

#include <cstdio>
#include <cstdint>

bool double_overflow(uint8_t &x)
{
    const auto original{x};
    x *= 2;
    return original > x;
}

int main(void)
{
    uint8_t x{1};
    while (!double_overflow(x))
    printf("%hhu ", x); // hhu: unsigned char
}
