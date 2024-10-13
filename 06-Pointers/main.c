#include <stdio.h>

#include "pointer_operations.h"

int main(void) {
    int a = 5;
    int b = 7;
    printf("Before swap: a = %d at %p, b = %d at %p\n", a, &a, b, &b);
    swap(&a, &b);
    printf("After swap:  a = %d at %p, b = %d at %p\n", a, &a, b, &b);

    // Pointer arighmetic: incrementing a pointer by 1 moves it to the next memory location of the same data type
    int grades[] = {80, 75, 85};
    int* gradesPtr = &grades;
    printf("%p %p, %llu \n", gradesPtr, gradesPtr++, sizeof(int));

    char c = 'a';
    printf("char: %llu or %llu \n", sizeof(c), sizeof(char)); // 1 byte

    /*
     * C represents character literals using the int data type rather than char.
     * So, the size of 'a' is the size of an int (4 bytes).
     * This differs from the size of a char, which is usually 1 byte.
     */
    printf("character literals: %llu \n", sizeof('a')); // 4 bytes -

    printf("string: %llu \n", sizeof("a")); // 2 - 1 for the character and 1 for the null terminator

    // sizeof & static arrays
    int arr[3] = {0, 1, 2};
    printf("Size of arr: %llu\n", sizeof(arr)); // 12 bytes 3 * sizeof(int) (4)

    // sizeof & pointers
    int* ptr;
    int number = 42;
    ptr = &number;
    printf("Size of ptr: %llu\n", sizeof(ptr)); // 8 bytes (64-bit system)
    
    return 0;
}
