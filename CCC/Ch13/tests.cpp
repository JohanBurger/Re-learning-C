#include <array>
#include <deque>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <iostream>
#include <gtest/gtest.h>

using std::array;
using std::deque;
using std::get;
using std::list;
using std::priority_queue;
using std::queue;
using std::set;
using std::size_t;
using std::stack;
using std::vector;

// std::array<int, 10> static_array{};

TEST(Array, InitializedArrayElementsInitializedToZero)
{
    array<int, 10> local_array{};
    EXPECT_EQ(local_array[0], 0);
}

TEST(Array, UninitializedArrayElemntesNotInitializedToZero)
{
    array<int, 10> local_array;
    EXPECT_NE(local_array[0], 0);
}

TEST(Array, CanBeInitializedWithBracedInitializer)
{
    const size_t array_size = 10;
    array<int, array_size> local_array{1, 2, 3};
    EXPECT_EQ(local_array[0], 1);
    EXPECT_EQ(local_array[1], 2);
    EXPECT_EQ(local_array[2], 3);

    for (size_t counter = 3; counter < array_size; counter++)
    {
        EXPECT_EQ(local_array[counter], int{});
    }
}

TEST(Array, CanGetAndSetElements)
{
    const size_t array_size = 10;
    array<int, array_size> local_array{};
    int element_value{};
    int element_index{};

    // Square brackets
    element_value = 7;
    //  ...set
    local_array[element_index] = element_value;
    //  ...get
    EXPECT_EQ(local_array[element_index], element_value);
    //  ...whoops!
    EXPECT_NO_THROW((void)local_array[array_size + 2]);

    // at()
    element_value = 13;
    element_index = 1;
    //  ..set
    local_array.at(element_index) = element_value;
    //  ...get
    EXPECT_EQ(local_array.at(element_index), element_value);
    //  ...relief
    EXPECT_THROW(local_array.at(array_size + 2), std::out_of_range);

    // get()
    element_value = 17;
    element_index = 2;
    //  ...set - The index must be know at compile-time. :(
    get<2>(local_array) = element_value;
    //  ...set
    EXPECT_EQ(get<2>(local_array), element_value);
    //  ...relief - This won't compile
    // EXPECT_THROW((void)get<10>(local_array), std::out_of_range);
}

TEST(Array, FrontAndBack)
{
    const size_t array_size = 10;
    array<int, array_size> local_array{};

    int first_element = 317;
    int last_element = 67;

    local_array.front() = first_element;
    local_array.back() = last_element;

    EXPECT_EQ(local_array.front(), local_array.at(0));
    EXPECT_EQ(local_array.back(), local_array.at(array_size - 1));
}

TEST(Array, CanGetUnderlyingArray)
{
    array<char, 5> local_array{'T', 'e', 's', 't', '!'};
    const auto *test_ptr = local_array.data();
    ASSERT_EQ(*test_ptr, 'T');
    ASSERT_EQ(test_ptr, &local_array.front());
    ASSERT_EQ(test_ptr, &local_array.at(0));
    ASSERT_EQ(test_ptr, &local_array[0]);
    ASSERT_EQ(test_ptr, &get<0>(local_array));

    auto array_size = local_array.size();
    const auto *last_element = test_ptr + (array_size - 1);
    ASSERT_EQ(*last_element, local_array.back());
}

TEST(Iterator, BeginEndFormsHalfOpenRange)
{
    array<int, 0> e{};
    EXPECT_EQ(e.begin(), e.end());
    EXPECT_TRUE(e.empty());
}

TEST(Iterator, IteratorsAreLikePointers)
{
    array<int, 3> easy_as{1, 2, 3};
    auto iter = easy_as.begin();
    EXPECT_EQ(*iter, 1);
    ++iter;
    EXPECT_EQ(*iter, 2);
    ++iter;
    EXPECT_EQ(*iter, 3);
    ++iter;
    EXPECT_EQ(iter, easy_as.end());
}

TEST(Iterator, CanLoopOverArray)
{
    array<int, 3> easy_as{1, 2, 3};
    int sum{};
    for (auto iter = easy_as.begin(); iter != easy_as.end(); ++iter)
    {
        sum += *iter;
    }
    EXPECT_EQ(sum, 6);
}

TEST(Iterator, CanBeUsedWithRangeBasedForLoop)
{
    array<int, 5> fib{1, 1, 2, 3, 5};
    int sum{};
    for (const auto element : fib)
    {
        sum += element;
    }
    EXPECT_EQ(sum, 12);
}

TEST(Vector, CanBeDefaultCreated)
{
    vector<const char *> v;
    EXPECT_TRUE(v.empty());
}

TEST(Vector, CanBeCreatedWithInitialValues)
{
    vector<int> six_nine{6, 9};
    EXPECT_EQ(six_nine.size(), 2);
    EXPECT_EQ(six_nine[0], 6);
    EXPECT_EQ(six_nine[1], 9);
}

TEST(Vector, SupportsConstructionFromIterators)
{
    array<int, 5> fibb_arr{1, 1, 2, 3, 5};
    vector<int> fibb_vec(fibb_arr.begin(), fibb_arr.end());
    EXPECT_EQ(fibb_vec.size(), fibb_arr.size());
    for (size_t i = 0; i < fibb_arr.size(); ++i)
    {
        EXPECT_EQ(fibb_vec[i], fibb_arr[i]);
    }
}

TEST(Vector, AssignReplacesExistingElements)
{
    vector<int> v{0, 1, 2, 3};
    EXPECT_EQ(v.size(), 4);

    v.assign({4, 5, 6});
    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v[0], 4);
    EXPECT_EQ(v[1], 5);
    EXPECT_EQ(v[2], 6);
}

TEST(Vector, InsertPlacesNewElements)
{
    vector<int> zeros(3, 0);
    auto third_element = zeros.begin() + 2;
    // Inserts *before* the third element
    zeros.insert(third_element, 42);
    EXPECT_EQ(zeros[2], 42);
    EXPECT_EQ(zeros.size(), 4);
}

TEST(Vector, InsertAtEnd)
{
    vector<int> zeros(3, 0);
    zeros.push_back(42);
    EXPECT_EQ(zeros.back(), 42);
    EXPECT_EQ(zeros.size(), 4);
}

TEST(Vector, EmplaceMethods)
{
    vector<std::pair<int, int>> factors;
    factors.emplace_back(2, 30);
    factors.emplace_back(3, 20);
    factors.emplace_back(4, 15);
    // This is equivalent to
    // std::pair<int, int> pair(1, 60);
    // factors.insert(factors.begin(), pair);
    factors.emplace(factors.begin(), 1, 60);
    EXPECT_EQ(factors.front(), std::make_pair(1, 60));
    EXPECT_EQ(factors.size(), 4);
}

TEST(Vector, CapacityIsGreaterThanSize)
{
    vector<int> v(3, 0);
    EXPECT_GE(v.capacity(), v.size());
}

TEST(Vector, ExposesSizeManagementMethods)
{
    vector<array<uint8_t, 1024>> kb_store;
    EXPECT_GT(kb_store.max_size(), 0);
    EXPECT_TRUE(kb_store.empty());

    size_t elements{1024};
    kb_store.reserve(elements);
    EXPECT_TRUE(kb_store.empty());
    EXPECT_EQ(kb_store.capacity(), elements);

    kb_store.emplace_back();
    kb_store.emplace_back();
    EXPECT_EQ(kb_store.size(), 2);

    kb_store.shrink_to_fit();
    EXPECT_GE(kb_store.capacity(), 2);

    kb_store.clear();
    EXPECT_TRUE(kb_store.empty());
    EXPECT_GE(kb_store.capacity(), 2);
}

TEST(Deque, SupportsInsertion)
{
    deque<char> deckard;
    deckard.push_front('a');
    deckard.push_back('i');  // ai
    deckard.push_front('c'); // cai
    deckard.push_back('n');  // cain
    EXPECT_EQ(deckard[0], 'c');
    EXPECT_EQ(deckard[1], 'a');
    EXPECT_EQ(deckard[2], 'i');
    EXPECT_EQ(deckard[3], 'n');
}

TEST(Queue, SupportsPushPopFrontBack)
{
    deque<int> deq{1, 2};
    queue<int> easy_as(deq);

    EXPECT_EQ(easy_as.front(), 1);
    EXPECT_EQ(easy_as.back(), 2);
    easy_as.pop();
    easy_as.push(3);
    EXPECT_EQ(easy_as.front(), 2);
    EXPECT_EQ(easy_as.back(), 3);
    easy_as.pop();
    EXPECT_EQ(easy_as.front(), 3);
    EXPECT_EQ(easy_as.back(), 3);
    easy_as.pop();
    EXPECT_TRUE(easy_as.empty());
}

TEST(List, RemoveIf)
{
    list<int> odds{11, 22, 33, 44, 55};
    odds.remove_if([](int n)
                   { return n % 2 == 0; });
    EXPECT_EQ(odds.size(), 3);
    EXPECT_EQ(odds.front(), 11);
    EXPECT_EQ(odds.back(), 55);
}

TEST(Stack, PushPopTop)
{
    vector<int> vec{1, 3};
    stack<int, decltype(vec)> easy_as(vec);
    EXPECT_EQ(easy_as.size(), 2);
    EXPECT_EQ(easy_as.top(), 3);
    easy_as.pop();
    easy_as.push(2);
    EXPECT_EQ(easy_as.top(), 2);
    easy_as.pop();
    EXPECT_EQ(easy_as.size(), 1);
    EXPECT_EQ(easy_as.top(), 1);
}

TEST(PriorityQueue, SupportsPushPopTop)
{
    priority_queue<double> prique;
    prique.push(1.0);
    prique.push(2.0);
    prique.push(1.5);
    EXPECT_DOUBLE_EQ(prique.top(), 2.0);
    prique.pop();
    EXPECT_DOUBLE_EQ(prique.top(), 1.5);
    prique.pop();
    EXPECT_DOUBLE_EQ(prique.top(), 1.0);
    prique.pop();
    EXPECT_TRUE(prique.empty());
}

TEST(Set, SupportsConstruction)
{
    set<int> emp;
    set<int> fib{1, 1, 2, 3, 5};
    EXPECT_TRUE(emp.empty());
    EXPECT_EQ(fib.size(), 4);

    auto fib_moved(std::move(fib));
    EXPECT_EQ(fib_moved.size(), 4);
    EXPECT_TRUE(fib.empty());
}

TEST(Set, AllowsAccess)
{
    set<int> fib{1, 1, 2, 3, 5};
    // std::cout << *fib.find(3) << std::endl;
    EXPECT_EQ(*fib.find(3), 3);

    std::cout << fib.count(1) << std::endl;
}
