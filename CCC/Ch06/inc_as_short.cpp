// clang++ -std=c++17 -Wall -Wextra -pedantic inc_as_short.cpp -o inc_as_short

#include <cstdio>

short increment_as_short(void *target)
{
    auto *as_short = static_cast<short *>(target);
    (*as_short)++;
    return *as_short;
}

int main(void)
{
    short beast{665};
    auto mark_of_the_beast = increment_as_short(&beast);
    std::printf("The mark of the beast is: %d\n", mark_of_the_beast);
}