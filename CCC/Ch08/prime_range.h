#ifndef PRIME_RANGE_H
#define PRIME_RANGE_H

#include "prime_iterator.h"

struct PrimeRange
{
    explicit PrimeRange(int max);
    PrimeIterator begin() const;
    int end() const;
    
private:
    const int max;
};

#endif
