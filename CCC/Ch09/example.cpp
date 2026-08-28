#include <functional>
#include <iostream>

std::size_t count_spaces(const char *str)
{
    std::size_t index{}, result{};
    while (str[index])
    {
        if (str[index] == ' ')
        {
            result++;
        }
        index++;
    }
    return result;
}

std::function<std::size_t(const char *str)> funcs[]  // An array of funcs
{
    count_spaces,
    [](const char *str)
    {
        std::size_t index{};
        while (str[index])
        {
            index++;
        }
        return index;
    }
};

const auto text = "Sailor went to sea to see what he could see.";

int main(void)
{
    // std::size_t func_count = sizeof(funcs) / sizeof(funcs[0]);
    for (const auto &func : funcs)
    {
        std::cout << func(text) << std::endl;
    }
}