#include <cstdio>
#include "avout.h"
#include "clock_of_the_long_now.h"

int main(void)
{
    ClockOfTheLongNow clock(2024);
    ClockOfTheLongNow *clock_ptr = &clock;
    clock_ptr->set_year(2020);
    std::printf("Clock year at %p is set to %d\n",
                (void *)clock_ptr, clock_ptr->get_year());

    Avout raz("Erasmus", 3010);
    Avout jad{"Jad", 4000};
    raz.announce();
    jad.announce();
}