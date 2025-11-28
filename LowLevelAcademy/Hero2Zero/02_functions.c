#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) {
    return a + b;
}

int main(void) {
    int sum = add(3, 5);
    printf("Sum: %d\n", sum);

    return EXIT_SUCCESS;
}
