// clang++ -std=c++17 -Wall -Wextra -pedantic simple_string_owner.cpp simple_string.cpp  -o sso
#include <cstdio>
#include <stdexcept>
#include "simple_string.h"

struct SimpleStringOwner
{
    SimpleStringOwner(const char *x)
        : s{10}
    {
        if (!s.append_line(x))
        {
            throw std::runtime_error("Not enough space.");
        }
        s.print("Constructed");
    }

    ~SimpleStringOwner()
    {
        s.print("About to destroy");
        // Doesn't need to delete s, because it is a member variable and will be destroyed automatically.
        // We would have to delete s if it were a pointer, but it is not.
    }

private:
    SimpleString s;
};

void fn_c()
{
    SimpleStringOwner c{"cccccccccc"};
}

void fn_b()
{
    SimpleStringOwner b{"b"};
    fn_c();
}

int main()
{
    // SimpleStringOwner sso{"x"};
    // std::printf("x is alive!\n");

    try
    {
        SimpleStringOwner a{"a"};
        fn_b();
        SimpleStringOwner d{"d"};
    }
    catch (const std::exception &e)
    {
        printf("Exception: %s\n", e.what());
    }
}