#include "prime_iterator.h"

bool PrimeIterator::operator!=(int x)
{
    return x >= this->current;
}

bool is_prime(int x)
{
    for (int i{2}; i < x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

PrimeIterator& PrimeIterator::operator++()
{
    int next{current};
    do
    {
        next++;
    }
    while(!is_prime(next));
    this->current = next;
    return *this;
}

int PrimeIterator::operator*() const
{
    return current;
}
