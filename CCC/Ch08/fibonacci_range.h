#ifndef FIBONACCI_RANGE_H
#define FIBONACCI_RANGE_H

#include "fibonacci_iterator.h"

struct FibonacciRange
{
    explicit FibonacciRange(int max);
    FibonacciIterator begin() const;
    int end() const;

private:
    const int max;
};

#endif
