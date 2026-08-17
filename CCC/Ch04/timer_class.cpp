#include <sys/time.h>
#include <cstdio>
#include <cstring>
#include <stdexcept>

#include "timer_class.h"

TimerClass::TimerClass(const char *name)
    : name{nullptr}
{
    if (name == nullptr)
    {
        throw std::invalid_argument("TimerClass name must not be null.");
    }

    if (gettimeofday(&timestamp, nullptr) != 0)
    {
        throw std::runtime_error("Failed to get current time.");
    }

    this->name = new char[strlen(name) + 1];
    std::strcpy(this->name, name);
}

TimerClass::TimerClass(const TimerClass &other)
    : timestamp{other.timestamp},
      name{new char[strlen(other.name) + 1]}
{
    std::strcpy(name, other.name);
}

TimerClass::TimerClass(TimerClass &&other) noexcept
    : timestamp{other.timestamp},
      name{other.name}
{
    other.timestamp.tv_sec = 0;
    other.timestamp.tv_usec = 0;
    other.name = nullptr;
}

TimerClass &TimerClass::operator=(const TimerClass &other)
{
    if (this != &other)
    {
        char *new_name = new char[strlen(other.name) + 1];
        std::strcpy(new_name, other.name);

        delete[] name;
        name = new_name;
        timestamp = other.timestamp;
    }
    return *this;
}

TimerClass &TimerClass::operator=(TimerClass &&other) noexcept
{
    if (this != &other)
    {
        timestamp = other.timestamp;
        delete[] name;
        name = other.name;

        other.timestamp.tv_sec = 0;
        other.timestamp.tv_usec = 0;
        other.name = nullptr;
    }
    return *this;
}

TimerClass::~TimerClass()
{
    if (name != nullptr && !(timestamp.tv_sec == 0 && timestamp.tv_usec == 0))
    {
        timeval now;
        if (gettimeofday(&now, nullptr) == 0)
        {
            auto elapsed = subtract(now, timestamp);
            std::printf("%s Elapsed time: %ld.%06d seconds\n",
                        name,
                        static_cast<long>(elapsed.tv_sec),
                        static_cast<int>(elapsed.tv_usec));
        }
    }

    delete[] name;
}

timeval TimerClass::subtract(const timeval &a, const timeval &b) const
{
    timeval result;
    result.tv_sec = a.tv_sec - b.tv_sec;
    result.tv_usec = a.tv_usec - b.tv_usec;
    if (result.tv_usec < 0)
    {
        result.tv_sec--;
        result.tv_usec += 1000000;
    }
    return result;
}
