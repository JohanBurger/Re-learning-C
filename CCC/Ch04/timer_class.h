#ifndef TIMER_CLASS_H
#define TIMER_CLASS_H

#include <sys/time.h>

struct TimerClass
{
    // Constructors
    TimerClass(const char* name);
    TimerClass(const TimerClass &other);
    TimerClass(TimerClass &&other) noexcept;

    // Assignment
    TimerClass &operator=(const TimerClass &other);
    TimerClass &operator=(TimerClass &&other) noexcept;

    // Destructor
    ~TimerClass();

private:
    timeval subtract(const timeval &a, const timeval &b) const;
    timeval timestamp;
    char* name;
};

#endif // TIMER_CLASS_H
