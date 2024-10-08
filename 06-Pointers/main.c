#include <stdio.h>

#include "pointer_operations.h"

int main(void) {
    int a = 5;
    int b = 7;
    printf("Before swap: a = %d at %p, b = %d at %p\n", a, &a, b, &b);
    swap(&a, &b);
    printf("After swap:  a = %d at %p, b = %d at %p\n", a, &a, b, &b);
    return 0;
}
