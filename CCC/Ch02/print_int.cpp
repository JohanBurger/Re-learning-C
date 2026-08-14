#include <cstdio>

int main()
{
    unsigned short a = 0b1010'1010;
    int b = 0123; // octal literal on account of the leading 0
    unsigned long c = 0xFFFF'FFFF'FFFF'FFFF;

    printf("%hu\n", a);
    printf("%d\n", b);
    printf("%lu\n", c);

    unsigned int d = 3'669'732'608;
    printf("Yabba %x!\n", d);

    unsigned int e = 69;
    printf("There are %u,%o leaves here.\n", e, e);

    unsigned long test = 0xFFFF'FFFF'FFFF'FFFFUL;
    unsigned long test2 = test + 1;
    printf("test: %lu, test2: %lu\n", test, test2);
}