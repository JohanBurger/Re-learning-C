// clang++ -std=c++17 -Wall -Wextra -pedantic comma_operator.cpp -o comma_operator

#include <cstdio>

int confusing(int &x)
{
    return x = 9, x++, x / 2;
}

int main(void)
{
    int x{};
    auto y = confusing(x);
    std::printf("x = %d, y = %d\n", x, y);
}
