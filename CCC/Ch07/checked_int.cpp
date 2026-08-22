// clang++ -std=c++17 -Wall -Wextra -pedantic checked_int.cpp -o checked_int
#include <limits>
#include <cstdio>
#include <stdexcept>

struct CheckedInteger
{
    CheckedInteger(unsigned int value)
        : value(value)
    {
    }

    CheckedInteger operator+(unsigned int other) const
    {
        CheckedInteger result{this->value + other};
        if (result.value < this->value || result.value < other)
        {
            throw std::overflow_error("Integer overflow");
        }
        return result;
    }

    const unsigned int value;
};

int main(void)
{
    CheckedInteger a{100};
    auto b = a + 200;
    printf("a + 200 = %u\n", b.value);

    try
    {
        auto c = a + std::numeric_limits<unsigned int>::max();
        printf("a + max = %u\n", c.value);
    }
    catch (const std::overflow_error &e)
    {
        printf("Overflow error: %s\n", e.what());
    }
}
