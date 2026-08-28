#include <cstdint>
#include <iostream>

struct LambdaFactory
{
    LambdaFactory(char in) : to_count{in}, tally{} {}

    auto make_lambda()
    {
        return [this](const char *str)
        {
            std::size_t index{}, result{};
            while (str[index]) 
            {
                if (str[index] == to_count) 
                {
                    result++;
                }
                index++;
            }
            tally += result;
            return result;
        };
    }

    const char to_count;
    std::size_t tally;
};

template <typename Fn, typename T>
void transform(Fn fn, const T *in, T *out, std::size_t length)
{
    for (std::size_t i{}; i < length; i++)
    {
        out[i] = fn(in[i]);
    }
}

int main(void)
{
    constexpr std::size_t len{3};
    int base_int[]{1, 2, 3}, a[len];
    float base_float[]{0.5f, 0.25f, 0.125f}, b[len];
    auto translate = [](auto x) { return x * x; };

    transform(translate, base_int, a, len);
    transform(translate, base_float, b, len);

    for (std::size_t i{}; i < len; i++)
    {
        std::cout << a[i] << "\t" << b[i] << std::endl;
    }

    char to_count { 's' }; 
    std::size_t tally{};
    auto s_counter = [&, to_count](const char *str) 
    {
        std::size_t index{};
        while (str[index])
        {
            if (str[index] == to_count)
            {
                tally++;
            }
            index++;
        }
        // return result;
    };
    auto sally = "Sally sells sea shells on the sea shore.";
    s_counter(sally);
    std::cout << "Sally: " << tally << std::endl;

    auto buffalo = "Buffalo buffalo Buffalo buffalo"
                    "Buffalo buffalo Buffalo buffalo";
    // This doesn't work, because to_count was passed by value. 
    to_count = 'f';
    tally = 0; // tally will remain zero, because buffalo doesn't contain 's'.
    s_counter(buffalo);
    std::cout << "Buffalo: " << tally << std::endl;

    LambdaFactory factory('s');
    auto first = factory.make_lambda();
    auto first_count = first(sally);
    std::cout << "first factory lambda: " << first_count << "\t" << factory.tally << std::endl;

    auto sailor = "Sailor went to the sea to see what he could see.";

    auto second = factory.make_lambda();
    auto second_count = second(sailor);
    std::cout << "second factory lambda: " << second_count << "\t" << factory.tally << std::endl;
}
