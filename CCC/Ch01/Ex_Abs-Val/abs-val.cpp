#include <iostream>

int abs_val(int x)
{
    if (x < 0)
        return -x;
    else
        return x;
}

int sum(int a, int b)
{
    return a + b;
}

int main()
{
    int my_num = -10;
    int my_abs_num = abs_val(my_num);
    int zero = sum(my_num, my_abs_num);
    std::cout << "The absolute value of " << my_num << " is " << my_abs_num << std::endl;
    std::cout << "The sum of " << my_num << " and " << my_abs_num << " is " << zero << std::endl;
    return 0;
}