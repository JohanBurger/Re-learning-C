#ifndef AVOUT_H
#define AVOUT_H

#include "clock_of_the_long_now.h"

struct Avout
{
    Avout(const char *name, int year)
        : name{name}, apert{year}
    {
    }

    void announce() const;

    const char *name;
    ClockOfTheLongNow apert;
};

#endif