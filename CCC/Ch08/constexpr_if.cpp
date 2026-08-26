// clang++ -std=c++17 -Wall -Wextra -pedantic constexpr_if.cpp -o constexpr_if

#include <cstdio>
#include <stdexcept>
#include <type_traits>

template <typename T>
auto value_of(T x)
{
    if constexpr (std::is_pointer<T>::value)
    {
        if (!x) 
        {
            throw std::runtime_error{"NULL pointer dereference!"};
        }
        return *x;
    }
    else 
    {
        return x;
    }
}

int main(void)
{
    unsigned long level{8998};
    auto level_ptr = &level;
    auto &level_ref = level;
    printf("Power level = %lu\n", value_of(level_ptr));
    ++*level_ptr;
    printf("Power level = %lu\n", value_of(level_ref));
    ++level_ref;
    printf("Power level = %lu\n", value_of(level++));

    try
    {
        level_ptr = nullptr;
        value_of(level_ptr);
    }
    catch(const std::exception &e)
    {
        printf("Exception: %s\n", e.what());
    }
}
