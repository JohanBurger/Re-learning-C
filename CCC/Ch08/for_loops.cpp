// clang++ -std=c++17 -Wall -Wextra -pedantic for_loops.cpp -o for_loops
#include <cstdio>

int main(void)
{
    const int x[]{1, 1, 2, 3, 5, 8};

    int array_length = static_cast<int>(sizeof(x) / sizeof(x[0]));
    for (int i{}; i < array_length; i++)
    {
        std::printf("%d: %d\n", i, x[i]);
    }

    for (const auto element : x)
    {
        std::printf("%d\n", element);
    }
}
