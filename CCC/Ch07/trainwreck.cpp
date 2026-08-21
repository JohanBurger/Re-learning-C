// clang++ -std=c++17 -Wall -Wextra -pedantic trainwreck.cpp -o trainwreck

#include <cstdio>

void trainwreck_break(const char *read_only)
{
    auto as_unsigned = (unsigned char *)read_only;
    *as_unsigned = 'b'; // This is undefined behavior, but it will compile and run, and it will likely crash or corrupt memory.
}

void trainwreck_still_breaks(const char *read_only)
{
    auto not_const = const_cast<char *>(read_only); // This removes the const qualifier, but it does not make the object mutable. Modifying a string literal is undefined behavior.
    auto as_unsigned = reinterpret_cast<unsigned char *>(not_const);
    *as_unsigned = 'b';
}

int main(void)
{
    const char *read_only = "Hello, world!";
    printf("Before trainwreck: %s\n", read_only);
    trainwreck_still_breaks(read_only);
    std::printf("After trainwreck: %s\n", read_only);
}
