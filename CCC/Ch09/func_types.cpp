#include <iostream>

struct CountIf
{
    CountIf(char x) : x{x} {}
    std::size_t operator()(const char* str) const 
    {
        // std::cout << "Here" << std::endl;
        std::size_t index{}, result{};
        while (str[index])
        {
            if (str[index] == x)
            {
                result++;
                std::cout << "X";
            }
            else 
            {
                std::cout << ".";
            }
            index++;
        }
        std::cout << std::endl;
        return result;
    }
private:
    const char x;
};

int main(void)
{
    CountIf s_counter{'s'};
    auto sally = s_counter("Sally sells seashells at the seashore.");
    std::cout << "Sally: " << sally << std::endl;

    auto sailor = s_counter("Sailor went to the sea to see what he could see.");
    std::cout << "Sailor: " << sailor << std::endl;

    auto buffalo = CountIf{'f'}("Buffalo buffalo Buffalo buffalo"
                                "Buffalo buffalo Buffalo buffalo");
    std::cout << "Buffalo: " << buffalo << std::endl;
}
