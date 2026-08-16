#include <cstdio>

int main(void)
{
    int original{100};
    int &original_ref = original;
    std::printf("Original: %d\n", original);
    std::printf("Reference: %d\n", original_ref);

    int new_value{200};
    original_ref = new_value;
    std::printf("Original: %d\n", original);
    std::printf("New Value: %d\n", new_value);
    std::printf("Reference: %d\n", original_ref);
}