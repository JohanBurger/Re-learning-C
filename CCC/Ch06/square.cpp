// clang++ -std=c++17 -Wall -Wextra -pedantic -fconcepts square.cpp -o square

#include <cstdio>
// #include <type_traits>

template <typename T>
T square(T value)
{
    return value * value;
}

int main(void)
{
    char my_char{'Q'};
    auto char_squared = square(&my_char);
    std::printf("Square of char '%c' is: %d\n", my_char, char_squared);

    return 0;
}