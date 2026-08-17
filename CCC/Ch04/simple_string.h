#ifndef SIMPLE_STRING_H
#define SIMPLE_STRING_H

#include <cstddef>

struct SimpleString
{
    SimpleString(std::size_t max_size);          // Constructor
    SimpleString(const SimpleString &other);     // Copy constructor
    SimpleString(SimpleString &&other) noexcept; // Move constructor

    SimpleString &operator=(const SimpleString &other);     // Copy operator
    SimpleString &operator=(SimpleString &&other) noexcept; // Move operator

    void print(const char *tag) const;
    bool append_line(const char *x);
    ~SimpleString(); // Destructor

private:
    std::size_t max_size;
    char *buffer;
    std::size_t length;
};

#endif // SIMPLE_STRING_H
