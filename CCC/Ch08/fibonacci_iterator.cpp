#include "fibonacci_iterator.h"

bool FibonacciIterator::operator!=(int x)
{
    return x >= this->current;
}

FibonacciIterator& FibonacciIterator::operator++()
{
    const auto tmp = this->current;
    this->current += this->last;
    this->last = tmp;
    return *this;
}

int FibonacciIterator::operator*() const
{
    return current;
}
