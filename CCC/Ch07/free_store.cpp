// clang++ -std=c++17 -Wall -Wextra -pedantic free_store.cpp -o free_store
#include <cstddef>
#include <cstdio>
#include <new>
#include <stdexcept>

struct Bucket
{
    static constexpr std::size_t data_size{0x1000}; // 4096
    alignas(std::max_align_t) std::byte data[data_size];
};

struct Heap
{
    void *allocate(std::size_t bytes)
    {
        if (bytes > Bucket::data_size)
        {
            throw std::bad_alloc{};
        }
        for (std::size_t i{}; i < n_heap_buckets; i++)
        {
            if (!bucket_used[i])
            {
                bucket_used[i] = true;
                return buckets[i].data;
            }
        }
        throw std::bad_alloc{};
    }

    void free(void *ptr)
    {
        for (std::size_t i{}; i < n_heap_buckets; i++)
        {
            if (ptr == buckets[i].data)
            {
                bucket_used[i] = false;
                return;
            }
        }
        throw std::runtime_error{"Pointer not allocated by this heap"};
    }

    static const std::size_t n_heap_buckets{10};
    Bucket buckets[n_heap_buckets]{};
    bool bucket_used[n_heap_buckets]{false};
};

Heap heap;

void *operator new(std::size_t bytes)
{
    return heap.allocate(bytes);
}

void operator delete(void *ptr) noexcept
{
    return heap.free(ptr);
}

int main(void)
{
    printf("Buckes: %p\n", static_cast<void *>(heap.buckets));
    printf("Bucket size: 0x%zx\n", sizeof(Bucket));
    auto breakfast = new unsigned int{0xC0FFFEE};
    auto dinner = new unsigned int{0xDEADBEEF};
    printf("Breakfast: %p 0x%x\n", static_cast<void *>(breakfast), *breakfast);
    printf("Dinner:    %p 0x%x\n", static_cast<void *>(dinner), *dinner);

    delete breakfast;
    delete dinner;

    try
    {
        while (true)
        {
            new char;
            printf("Allocated a char\n");
        }
    }
    catch (const std::bad_alloc &e)
    {
        printf("Caught bad_alloc: %s\n", e.what());
    }
    catch (const std::runtime_error &e)
    {
        printf("Caught runtime_error: %s\n", e.what());
    }
}
