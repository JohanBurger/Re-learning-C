#include <cstdint>
#include <iostream>

template <typename Fn>
void transform(Fn fn, const int *in, int *out, std::size_t length) 
{
    for (std::size_t i{}; i < length; i++)
    {
        out[i] = fn(in[i]);
    }
}

int main(void) 
{
    const std::size_t len{3};
    int base[]{1, 2, 3}, a[len], b[len], c[len];
    transform([](int x) {return 1;}, base, a, len);
    transform([](int x) {return x;}, base, b, len);
    transform([](int x) {return x * x; }, base, c, len);

    for (std::size_t i{}; i < len; i++)
    {
        std::cout << a[i] << "\t" << b[i] << "\t" << c[i] << std::endl;
    }

    auto increment = [](auto x, int y = 1) { return x + y; };
    std::cout << increment(10) << std::endl;
    std::cout << increment(10, 5) << std::endl;
}
