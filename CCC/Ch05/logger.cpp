#include <cstdio>

#ifndef LOGGER_CPP
#define LOGGER_CPP
struct Logger
{
    virtual ~Logger() = default;
    virtual void log_transfer(long from, long to, double amount) = 0;
};
#endif // LOGGER_CPP

struct ConsoleLogger : Logger
{
    ConsoleLogger(const char *prepend)
        : prepend{prepend} {};
    void log_transfer(long from, long to, double amount) override
    {
        std::printf("%s: %ld -> %ld: %f\n", this->prepend, from, to, amount);
    }

private:
    const char *prepend;
};

struct FileLogger : Logger
{
    void log_transfer(long from, long to, double amount) override
    {
        std::printf("[FILE] %ld -> %ld: %f\n", from, to, amount);
    }
};
