#include <gtest/gtest.h>

#include <memory>
#include <utility>

class DeadMenOfDunharrow
{
public:
    DeadMenOfDunharrow(const char *m = " ")
        : message{m}
    {
        this->oaths_to_fulfill++;
    }

    ~DeadMenOfDunharrow()
    {
        this->oaths_to_fulfill--;
    }

    const char *message;
    static int oaths_to_fulfill;
};

int DeadMenOfDunharrow::oaths_to_fulfill{};

using UniqueOathBreakers = std::unique_ptr<DeadMenOfDunharrow>;

/*
 *  Unique pointers
 */
TEST(UniquePtrTest, EvaluatesToTrueWhenFull)
{
    UniqueOathBreakers aragorn{new DeadMenOfDunharrow};
    EXPECT_TRUE(aragorn);
}

TEST(UniquePtrTest, MakeUniqueHelper)
{
    auto aragorn = std::make_unique<DeadMenOfDunharrow>();

    auto legolas_msg = "This is a test.";
    auto legolas = std::make_unique<DeadMenOfDunharrow>(legolas_msg);

    EXPECT_EQ(DeadMenOfDunharrow::oaths_to_fulfill, 2);
    EXPECT_STREQ(aragorn->message, " ");
    EXPECT_STREQ(legolas->message, legolas_msg);
}

TEST(UniquePtrTest, EvaluatesToFalseWhenEmpty)
{
    UniqueOathBreakers aragorn{};
    ASSERT_FALSE(aragorn);
}

TEST(UniquePtrTest, IsARaiiWrapper)
{
    EXPECT_EQ(DeadMenOfDunharrow::oaths_to_fulfill, 0);
    UniqueOathBreakers aragorn{new DeadMenOfDunharrow};
    EXPECT_EQ(DeadMenOfDunharrow::oaths_to_fulfill, 1);
    {
        UniqueOathBreakers legolas{new DeadMenOfDunharrow};
        EXPECT_EQ(DeadMenOfDunharrow::oaths_to_fulfill, 2);
    }
    EXPECT_EQ(DeadMenOfDunharrow::oaths_to_fulfill, 1);
}

TEST(UniquePtrTest, PtrSemantics)
{
    auto message = "The way is out.";
    UniqueOathBreakers aragorn{new DeadMenOfDunharrow{message}};
    EXPECT_EQ((*aragorn).message, message);
    EXPECT_EQ(aragorn->message, message);
    ASSERT_NE(aragorn.get(), nullptr);

    UniqueOathBreakers legolas{};
    EXPECT_EQ(legolas, nullptr);
}

TEST(UniquePtrTest, SupportsSwap)
{
    auto msg1 = "The way is shut.";
    auto msg2 = "Until the time comes.";

    UniqueOathBreakers aragorn{new DeadMenOfDunharrow{msg1}};
    UniqueOathBreakers legolas{new DeadMenOfDunharrow{msg2}};

    aragorn.swap(legolas);

    EXPECT_STREQ(aragorn->message, msg2);
    EXPECT_STREQ(legolas->message, msg1);
}

TEST(UniquePtrTest, ResetCanReplaceObject)
{
    UniqueOathBreakers aragorn{new DeadMenOfDunharrow{}};
    EXPECT_EQ(DeadMenOfDunharrow::oaths_to_fulfill, 1);

    aragorn.reset();
    EXPECT_EQ(DeadMenOfDunharrow::oaths_to_fulfill, 0);
    EXPECT_FALSE(aragorn);

    auto msg = "It was made by those who are dead.";
    auto new_dead_man = new DeadMenOfDunharrow{msg};
    EXPECT_EQ(DeadMenOfDunharrow::oaths_to_fulfill, 1);
    aragorn.reset(new_dead_man);
    EXPECT_TRUE(aragorn);
    EXPECT_STREQ(aragorn->message, msg);
    auto new_msg = "New Message";
    aragorn.reset(new DeadMenOfDunharrow{new_msg});
    EXPECT_EQ(DeadMenOfDunharrow::oaths_to_fulfill, 1);
    EXPECT_STREQ(aragorn->message, new_msg);
}

void by_ref(const UniqueOathBreakers &) {}
void by_val(UniqueOathBreakers) {}

TEST(UniquePtrTest, CanBePassedByReference)
{
    UniqueOathBreakers aragorn{new DeadMenOfDunharrow{}};
    EXPECT_NO_THROW(by_ref(aragorn));
}

TEST(UniquePtrTest, CanBeMoved)
{
    UniqueOathBreakers aragorn{new DeadMenOfDunharrow{}};
    // This does not compile:
    // by_val(*aragorn);

    // But this does:
    EXPECT_NO_THROW(by_val(std::move(aragorn)));
}

/*
 * unique_ptr to an array
 */
TEST(UniquePtrTest, ArraySupported)
{
    std::unique_ptr<int[]> squares{new int[]{1, 4, 9, 16, 25}};
    EXPECT_EQ(squares[0], 1);
    EXPECT_EQ(squares[4], 25);
}

/*
 * Custom deleter
 */
TEST(UniquePtrTest, SupportsCustomDeleter)
{
    auto my_deleter = [](int *x)
    { delete x; };
    std::unique_ptr<int, decltype(my_deleter)> my_up{new int{42}, my_deleter};

    EXPECT_TRUE(my_up);
    EXPECT_EQ(*my_up, 42);
}

using SharedOathBreakers = std::shared_ptr<DeadMenOfDunharrow>;

TEST(SharedPtrTest, CanBeCopied)
{
    auto msg = "This is a message.";
    auto aragorn = std::make_shared<DeadMenOfDunharrow>(msg);
    EXPECT_EQ(DeadMenOfDunharrow::oaths_to_fulfill, 1);
    EXPECT_STREQ(aragorn->message, msg);
    {
        auto son_of_aragorn{aragorn};
        EXPECT_EQ(DeadMenOfDunharrow::oaths_to_fulfill, 1);
    }
    EXPECT_EQ(DeadMenOfDunharrow::oaths_to_fulfill, 1);
}

TEST(SharedPtrTest, CanBeAssigned)
{
    auto aragorn = std::make_shared<DeadMenOfDunharrow>();
    SharedOathBreakers son_of_arathorn;
    EXPECT_EQ(DeadMenOfDunharrow::oaths_to_fulfill, 1);
    son_of_arathorn = aragorn;
    EXPECT_EQ(DeadMenOfDunharrow::oaths_to_fulfill, 1);
}

TEST(SharedPtrTest, AssignmentDiscardsOriginalObject)
{
    auto aragorn = std::make_shared<DeadMenOfDunharrow>();
    auto son_of_arathorn = std::make_shared<DeadMenOfDunharrow>();
    EXPECT_EQ(DeadMenOfDunharrow::oaths_to_fulfill, 2);
    EXPECT_EQ(aragorn.use_count(), 1);
    EXPECT_EQ(son_of_arathorn.use_count(), 1);
    son_of_arathorn = aragorn;
    EXPECT_EQ(DeadMenOfDunharrow::oaths_to_fulfill, 1);
    // use_count() counts the number of shared pointers to the raw pointer.
    // Both shared pointers point to the same raw pointer, so use_count()
    // is 2 for both.
    EXPECT_EQ(aragorn.use_count(), 2);
    EXPECT_EQ(son_of_arathorn.use_count(), 2);
}

using WeakOathBrothers = std::weak_ptr<DeadMenOfDunharrow>;

TEST(WeakPtrTest, LockYieldsSharedPointer)
{
    auto msg = "The way is shut.";
    auto aragorn = std::make_shared<DeadMenOfDunharrow>(msg);
    WeakOathBrothers legolas{aragorn};
    auto first_sh_ptr = legolas.lock();

    EXPECT_NE(first_sh_ptr, nullptr);
    EXPECT_STREQ(first_sh_ptr->message, msg);
    EXPECT_EQ(aragorn.use_count(), 2);

    auto second_sh_ptr = legolas.lock();
    EXPECT_EQ(aragorn.use_count(), 3);
}

TEST(WeakPtrTest, LockYieldsEmptyWhenSharedPtrIsGone)
{
    auto msg = "The way is shut.";
    WeakOathBrothers legolas;
    {
        auto aragon = std::make_shared<DeadMenOfDunharrow>(msg);
        legolas = aragon;
    }
    auto sh_ptr = legolas.lock();
    EXPECT_FALSE(sh_ptr);
    EXPECT_EQ(sh_ptr, nullptr);
}
