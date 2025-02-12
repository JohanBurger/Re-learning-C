#include <stdio.h>
#include <string.h>

#include "pointer_operations.h"

int main(int argc, char** argv) {
    int a = 5;
    int b = 7;
    printf("Before swap: a = %d at %p, b = %d at %p\n", a, &a, b, &b);
    swap(&a, &b, sizeof(int));
    printf("After swap:  a = %d at %p, b = %d at %p\n", a, &a, b, &b);

    // Pointer arithmetic: incrementing a pointer by 1 moves it to the next memory location of the same data type
    int grades[] = {80, 75, 85};
    int* gradesPtr = &grades[0];
    int* zeroth_address = gradesPtr;
    int* next_address = ++gradesPtr;
    printf("%p %p, %llu \n", zeroth_address, next_address, sizeof(int));

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

    // Multiple indirection
    int* z = &a; // z is a pointer, we have assigned the address of a to it.
    int **y = &z; // y is a pointer to a pointer, we have assigned the address of z to it.

    // a = 10;
    // void* void_ptr = &a;
    // // To use universal pointers (void*), you need to cast them to the appropriate type before using them.
    // printf("%d", *(int*)void_ptr); // 10
    printf("There are %d arguments", argc);
    // argv is a pointer to an array of strings, but a string is just a pointer to an array of chars
    // so argv is a 2-dimensional array
    for (int counter = 0; counter < argc; counter++) {
        char* arg = argv[counter];
        size_t len = strlen(argv[counter]);
        printf("Argument %d at %p %s, %zu chars\n", counter, &arg[counter], argv[counter], len);
    }

    int array_sum = sum(grades, 3);
    printf("Sum of grades: %d\n", array_sum);
    return 0;
}
