#include <cstdio>
#include <utility>

void ref_type(int &x)
{
    printf("lvalue reference %d\n", x);
}

void ref_type(int &&x)
{
    printf("rvalue reference %d\n", x);
}

int main(void)
{
    auto x = 5;
    ref_type(x);            // lvalue reference
    ref_type(5);            // rvalue reference
    ref_type(x + 5);        // rvalue reference
    ref_type(std::move(x)); // rvalue reference
}
