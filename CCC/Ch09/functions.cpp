#include <functional>
#include <iostream>

void void_func(void)
{
    std::function<void()> func;
    try
    {
        func();
    }
    catch (const std::bad_function_call &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void static_func() 
{
    std::cout << "A static function." << std::endl;
}

int main(void)
{
    void_func();

    std::function<void()> func{[]{std::cout << "A lambda!" << std::endl;}};
    func();

    func = static_func;
    func();
}
