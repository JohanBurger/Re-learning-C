#include <array>
#include <gtest/gtest.h>

using std::array;
using std::get;
using std::size_t;

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

    for(size_t counter = 3; counter < array_size; counter++)
    {
        EXPECT_EQ(local_array[counter], int{});
    }
}

TEST(Array, CanGetAndSetElements)
{
    const size_t array_size = 10;
    array <int, array_size> local_array{};
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
    const auto *last_element = test_ptr + (array_size -1);
    ASSERT_EQ(*last_element, local_array.back());
}
