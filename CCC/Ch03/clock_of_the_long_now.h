#ifndef CLOCK_OF_THE_LONG_NOW_H
#define CLOCK_OF_THE_LONG_NOW_H

class ClockOfTheLongNow
{
public:
    explicit ClockOfTheLongNow(int year);

    void add_years(int years);
    bool set_year(int year);
    int get_year() const;

private:
    int year;
};

#endif
