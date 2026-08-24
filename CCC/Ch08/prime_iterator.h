#ifndef PRIME_ITERATOR_H
#define PRIME_ITERATOR_H

struct PrimeIterator
{
    bool operator!=(int x);
    PrimeIterator &operator++();
    int operator*() const;

private:
    int current{2};
};

#endif