#include <cstdio>

int main(void)
{
    int gettysburg{};
    int *gettysburg_address = &gettysburg;
    std::printf("Value at address %p is %d\n",
                (void *)gettysburg_address, *gettysburg_address);
    *gettysburg_address = 17325;
    std::printf("Value at address %p is now %d\n",
                (void *)gettysburg_address, *gettysburg_address);
}
