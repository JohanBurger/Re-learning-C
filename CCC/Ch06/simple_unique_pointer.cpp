// clang++ -std=c++17 -Wall -Wextra -pedantic simple_unique_pointer.cpp -o sup
#include <cstdio>
#include <utility>

template <typename T>
struct SimpleUniquePointer
{
    SimpleUniquePointer() = default;
    SimpleUniquePointer(T *ptr)
        : pointer{ptr}
    {
    }

    ~SimpleUniquePointer()
    {
        if (pointer)
        {
            delete pointer;
        }
    }

    SimpleUniquePointer(const SimpleUniquePointer &) = delete;
    SimpleUniquePointer &operator=(const SimpleUniquePointer &) = delete;
    SimpleUniquePointer(SimpleUniquePointer &&other) noexcept
        : pointer{other.pointer}
    {
        other.pointer = nullptr;
    }

    SimpleUniquePointer &operator=(SimpleUniquePointer &&other) noexcept
    {
        if (this != &other)
        {
            if (pointer)
            {
                delete pointer;
            }
            pointer = other.pointer;
            other.pointer = nullptr;
        }
        return *this;
    }

    T *get()
    {
        return pointer;
    }

private:
    T *pointer{nullptr};
};

struct Tracer
{
    Tracer(const char *name) : name{name}
    {
        std::printf("Tracer %s constructed\n", name);
    }

    ~Tracer()
    {
        std::printf("Tracer %s destructed\n", name);
    }

private:
    const char *name;
};

void consumer(SimpleUniquePointer<Tracer> consumer_ptr)
{
    std::printf("(cons) consumer_ptr: 0x%p\n",
                static_cast<void *>(consumer_ptr.get()));
}

int main(void)
{
    SimpleUniquePointer<Tracer> ptr{new Tracer{"ptr_a"}};
    std::printf("(main) ptr_a: 0x%p\n",
                static_cast<void *>(ptr.get()));

    consumer(std::move(ptr));
    std::printf("(main) ptr after move: 0x%p\n",
                static_cast<void *>(ptr.get()));

    return 0;
}