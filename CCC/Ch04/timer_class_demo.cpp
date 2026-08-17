// clang++ -std=c++17 -Wall -Wextra -pedantic timer_class.cpp timer_class_demo.cpp -o timerdemo

#include <cstdio>
#include <sys/time.h>
#include <utility>
#include <unistd.h>

#include "timer_class.h"

int main(void)
{
    auto original = TimerClass("original");

    printf("Doing some work...\n");
    printf("Sleeping for 2 seconds...\n");
    sleep(2);

    auto copy = TimerClass(original);
    auto moved = TimerClass(std::move(original));

    return 0;
}
