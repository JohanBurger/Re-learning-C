#include <gtest/gtest.h>
#include "optional.h"
#include "pairs.h"

TEST(OptionalTests, OptionalContainsTypes)
{
    auto matrix_opt = take(Pill::Blue);
    EXPECT_TRUE(matrix_opt);
    auto &matrix = matrix_opt.value();
    EXPECT_EQ(matrix.iteration, 6);
}

TEST(OptionalTets, NullOpt)
{
    auto matrix_opt = take(Pill::Red);
    EXPECT_FALSE(matrix_opt);
    EXPECT_FALSE(matrix_opt.has_value());
}

TEST(Pairs, PermitsAccessToMembers)
{
    auto bertie_birthname = "Wilberforce";
    Socialite bertie{bertie_birthname};
    
    auto reginald_surname = "Jeeves";
    Valet reginald{reginald_surname};

    std::pair<Socialite, Valet> inimitable_duo{bertie, reginald};
    auto &[idle_rich, butler] = inimitable_duo;
    EXPECT_STREQ(idle_rich.birthname, bertie_birthname);
    EXPECT_STREQ(butler.surname, reginald_surname);
}

TEST(Tuples, PermitsAccessToMembers)
{
    auto bertie_birthname = "Wilberforce";
    Socialite bertie{bertie_birthname};
    
    auto reginald_surname = "Jeeves";
    Valet reginald{reginald_surname};

    auto hildebrand_nickname = "Tuppy";
    Acquintance hildebrand{hildebrand_nickname};
    
    using Trio = std::tuple<Socialite, Valet, Acquintance>;
    Trio truculent_trio{bertie, reginald, hildebrand};

    auto &bertie_ref = std::get<0>(truculent_trio);
    EXPECT_STREQ(bertie_ref.birthname, bertie_birthname);

    auto &tuppy_ref = std::get<Acquintance>(truculent_trio);
    EXPECT_STREQ(tuppy_ref.nickname, hildebrand_nickname);
}

TEST(Any, AllowsUsToCastToType)
{
    int weight = 600;
    std::any hagunemnon;
    hagunemnon.emplace<EscapeCapsule>(weight);
    auto capsule = std::any_cast<EscapeCapsule>(hagunemnon);
    EXPECT_EQ(capsule.weight_kg, weight);
}

TEST(Any, ThrowsBadCast)
{
    int weight = 600;
    std::any hagunemnon;
    hagunemnon.emplace<EscapeCapsule>(weight);
    EXPECT_THROW(std::any_cast<float>(hagunemnon), std::bad_any_cast);
}

TEST(Variant, DefaultConstructor)
{
    std::variant<BugblatterBeast, EscapeCapsule> hagunemnon;
    EXPECT_EQ(hagunemnon.index(), 0);
    EXPECT_EQ(std::get<BugblatterBeast>(hagunemnon).weight_kg, 600);
    EXPECT_EQ(std::get<0>(hagunemnon).weight_kg, 600);
}

TEST(Variant, CanEmplace)
{
    int capsule_weight = 517;
    std::variant<BugblatterBeast, EscapeCapsule> hagunemnon;
    hagunemnon.emplace<EscapeCapsule>(capsule_weight);

    EXPECT_EQ(hagunemnon.index(), 1);
    EXPECT_EQ(std::get<EscapeCapsule>(hagunemnon).weight_kg, capsule_weight);
    EXPECT_EQ(std::get<1>(hagunemnon).weight_kg, capsule_weight);
}

TEST(Variant, ThrowsBadCast)
{
    std::variant<BugblatterBeast, EscapeCapsule> hagunemnon;
    EXPECT_THROW(std::get<EscapeCapsule>(hagunemnon).weight_kg, std::bad_variant_access);
    EXPECT_THROW(std::get<1>(hagunemnon).weight_kg, std::bad_variant_access);

    int capsule_weight = 517;
    hagunemnon.emplace<EscapeCapsule>(capsule_weight);

    EXPECT_THROW(std::get<BugblatterBeast>(hagunemnon).weight_kg, std::bad_variant_access);
    EXPECT_THROW(std::get<0>(hagunemnon).weight_kg, std::bad_variant_access);
}

TEST(Variant, CanVisit)
{
    std::variant<BugblatterBeast, EscapeCapsule> hagunemnon;
    int capsule_weight = 517;
    hagunemnon.emplace<EscapeCapsule>(capsule_weight);
    auto lbs = std::visit([](auto &x){return 2.2*x.weight_kg;}, hagunemnon);
    EXPECT_NE(lbs, capsule_weight);
    EXPECT_EQ(lbs, capsule_weight * 2.2);
}

TEST(Chrono, SeveralClocksSupported)
{
    auto sys_now = std::chrono::system_clock::now();
    auto hi_res = std::chrono::high_resolution_clock::now();
    auto steady = std::chrono::steady_clock::now();

    EXPECT_GT(sys_now.time_since_epoch().count(), 0);
    EXPECT_GT(hi_res.time_since_epoch().count(), 0);
    EXPECT_GT(steady.time_since_epoch().count(), 0);
}

TEST(Crono, SeveralUnitsSupported)
{
    using namespace std::literals::chrono_literals;
    auto one_s = std::chrono::seconds(1);
    auto thousand_ms = 1000ms;
    EXPECT_EQ(one_s, thousand_ms);
}

TEST(Chrono, SupportsCastToDuration)
{
    using namespace std::chrono;
    std::chrono::duration billion_ns = 1'000'000'000ns;
    auto billion_ns_as_s = duration_cast<seconds>(billion_ns);
    EXPECT_EQ(billion_ns_as_s.count(), 1);
}
