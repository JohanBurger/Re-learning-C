#ifndef FIBONACCI_ITERATOR_H
#define FIBONACCI_ITERATOR_H

struct FibonacciIterator
{
    bool operator!=(int x);
    FibonacciIterator &operator++();
    int operator*() const;

private:
    int current{1};
    int last{1};
};

#endif