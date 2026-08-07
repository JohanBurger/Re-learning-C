#include <iostream>

int step_function(int step)
{
    int result = 0;
    if (step < 0)
    {
        result = -1;
    }
    else if (step > 0)
    {
        result = 1;
    }

    return result;
}

int main()
{
    std::cout << "Hello, World!" << std::endl;

    int the_answer = 42;
    int lucky_number{the_answer / 6};

    std::cout << "The answer is: " << the_answer << std::endl;
    std::cout << "The lucky number is: " << lucky_number << std::endl;

    if (the_answer > 0)
        std::cout << "The answer is positive." << std::endl;
    else if (the_answer < 0)
        std::cout << "The answer is negative." << std::endl;
    else
        std::cout << "The answer is zero." << std::endl;

    int step_output = step_function(the_answer);
    std::cout << "Step function output for the answer: " << step_output << std::endl;
    return 0;
}
