/*
 * Compile with `g++ -std=c++17 -Wall -Wextra -pedantic cotln.cpp clock_of_the_long_now.cpp avout.cpp -o cotln`
 */

#include "clock_of_the_long_now.h"

ClockOfTheLongNow::ClockOfTheLongNow(const int year)
    : year{year}
{
}

void ClockOfTheLongNow::add_years(const int years)
{
    this->year += years;
}

bool ClockOfTheLongNow::set_year(const int year)
{
    if (year < 2019)
    {
        return false;
    }

    this->year = year;
    return true;
}

int ClockOfTheLongNow::get_year() const
{
    return this->year;
}