// clang++ -std=c++17 -Wall -Wextra -pedantic point.cpp -o point

#include <cstdio>
#include <cstddef>
#include <new>

struct Point
{
    Point() : x{}, y{}, z{}
    {
        printf("Point constructed: at %p\n", static_cast<void *>(this));
    }

    ~Point()
    {
        printf("Point destructed: at %p\n", static_cast<void *>(this));
    }

    double x, y, z;
};

int main(void)
{
    constexpr std::size_t point_size = sizeof(Point);
    alignas(Point) std::byte data[3 * point_size];
    printf("Data starts at %p\n", static_cast<void *>(data));
    auto point1 = new (&data[0 * point_size]) Point();
    auto point2 = new (&data[1 * point_size]) Point();
    auto point3 = new (&data[2 * point_size]) Point();
    point1->~Point();
    point2->~Point();
    point3->~Point();
}
