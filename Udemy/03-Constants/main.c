#include <stdio.h>

int main(void) {
    const int number = 42;
    printf("The answer to life, the universe, and everything is: %d\n", number);

    // This will cause a compilation error:
    // You are not allowed to change the value of a const variable
    // number = 0;;

    // A pointer to a constant
    // The pointer can change, but the value that it points to cannot
    const int* ptrToConstant = &number;
    // This will cause a compilation error:
    // *ptrNumber = 0;

    int someOtherNumber = 0;
    // This is fine.
    ptrToConstant = &someOtherNumber;
    printf("ptrNumber is now pointing to: %d\n", *ptrToConstant);
    // This is still a problem
    // *ptrNumber = 1;

    // A constant pointer to a variable
    int someNumber = 3;
    int *const constantPtr = &someNumber;
    printf("Constant pointer is pointing to: %d\n", *constantPtr);

    // This is fine:
    *constantPtr = 4;
    printf("Constant pointer is now pointing to: %d\n", *constantPtr);

    // This will cause a compilation error:
    int someValue = 5;
    // constantPtr = &someValue;

    // Constant pointer pointing to a constant
    int cupsOfCoffeePerDay = 7;
    const int *const constPointerToConstVar = &cupsOfCoffeePerDay;

    printf("One should drink %d cups of coffee per day\n", *constPointerToConstVar);

    // This is fine (because we didn't mark cupsOfCoffeePerDay as const);
    cupsOfCoffeePerDay = 8;
    printf("One should drink %d cups of coffee per day\n", *constPointerToConstVar);

    // This will cause a compilation error:
    // *constPointerToConstVar = 9;

    int cupsOfTeaPerDay = 3;
    // This will cause a compilation error:
    // constPointerToConstVar = &cupsOfTeaPerDay;
    return 0;
}
