#include "prime_range.h"

PrimeRange::PrimeRange(int max) : max{max} {}

PrimeIterator PrimeRange::begin() const
{
    return PrimeIterator();
}

int PrimeRange::end() const
{
    return this->max;
}
