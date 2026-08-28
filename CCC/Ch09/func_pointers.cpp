#include <iostream>

float add(float a, int b)
{
    return a + b;
}

float subtract(float a, int b)
{
    return a - b;
}

int main(void)
{
    const float first{100};
    const int second{20};

    float(*operation)(float, int){};

    operation = &add;
    float sum = operation(first, second);
    std::cout << "Sum is " << sum << std::endl;

    operation = &subtract;
    float difference = operation(first, second);
    std::cout << "Difference is " << difference << std::endl;
}
