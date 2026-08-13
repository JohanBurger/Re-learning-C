#include <cstdio>
#include <cstring>
#include <stdexcept>

#include "simple_string.h"

SimpleString::SimpleString(size_t max_size)
    : max_size{max_size}, length{}
{
    if (max_size == 0)
    {
        throw std::runtime_error("Max size must be at least 1.");
    }
    buffer = new char[max_size];
    buffer[0] = 0;
}

SimpleString::SimpleString(const SimpleString &other)
    : max_size{other.max_size},
      buffer{new char[other.max_size]},
      length{other.length}
{
}

SimpleString::SimpleString(SimpleString &&other) noexcept
    : max_size{other.max_size},
      buffer{other.buffer},
      length{other.length}
{
    other.buffer = nullptr;
    other.length = 0;
    other.max_size = 0;
}

SimpleString &SimpleString::operator=(const SimpleString &other)
{
    if (this == &other)
    {
        return *this;
    }

    const auto new_buffer = new char[other.max_size];
    delete[] buffer;
    buffer = new_buffer;
    length = other.length;
    max_size = other.max_size;
    std::strncpy(buffer, other.buffer, max_size);
    return *this;
}

SimpleString &SimpleString::operator=(SimpleString &&other) noexcept
{
    if (this == &other)
    {
        return *this;
    }

    delete[] buffer;

    buffer = other.buffer;
    length = other.length;
    max_size = other.max_size;
    
    other.buffer = nullptr;
    other.length = 0;
    other.max_size = 0;

    return *this;
}

void SimpleString::print(const char *tag) const
{
    printf("%s: %s", tag, buffer);
}

bool SimpleString::append_line(const char *x)
{
    const auto x_len = strlen(x);
    if (length + x_len + 2 > max_size)
    {
        return false;
    }
    std::strncpy(buffer + length, x, max_size - length);
    length += x_len;
    buffer[length++] = '\n';
    buffer[length] = 0;
    return true;
}

SimpleString::~SimpleString()
{
    // printf("Destroying SimpleString with contents: %s\n", buffer);
    delete[] buffer;
}
