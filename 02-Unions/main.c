#include <stdio.h>
#include <sec_api/string_s.h>

union info {
    char firstName[20];
    int age;
};

int main(void) {
    union info myInfo;
    myInfo.age = 20;

    printf("Age: %d\n", myInfo.age);

    strcpy_s(myInfo.firstName, sizeof(myInfo.firstName), "Johan");
    // myInfo.firstName = "Johan";
    printf("First Name: %s\n", myInfo.firstName);
    printf("Age: %d\n", myInfo.age);

    printf("Location of myInfo: %p\n", &myInfo);
    printf("Location of myInfo.age: %p\n", &myInfo.age);
    printf("Location of myInfo.firstName: %p\n", &myInfo.firstName);
    return 0;
}
