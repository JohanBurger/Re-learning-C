#include <cstdio>

int main(void)
{
    int gettysburg{};
    int *gettysburg_address = &gettysburg;
    printf("Value at address %p is %d\n",
           gettysburg_address, *gettysburg_address);
    *gettysburg_address = 17325;
    printf("Value at address %p is now %d\n",
           gettysburg_address, *gettysburg_address);
}
