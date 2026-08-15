#include <cstdio>

int main()
{
    unsigned short a = 0b1010'1010;
    int b = 0123; // octal literal on account of the leading 0
    unsigned long c = 0xFFFF'FFFF'FFFF'FFFF;

    std::printf("%hu\n", a);
    std::printf("%d\n", b);
    std::printf("%lu\n", c);

    unsigned int d = 3'669'732'608;
    std::printf("Yabba %x!\n", d);

    unsigned int e = 69;
    std::printf("There are %u,%o leaves here.\n", e, e);

    unsigned long test = 0xFFFF'FFFF'FFFF'FFFFUL;
    unsigned long test2 = test + 1;
    std::printf("test: %lu, test2: %lu\n", test, test2);
}