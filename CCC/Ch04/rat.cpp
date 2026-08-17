#include <cstdio>

// // We could also make this extern. This would make the variable available
// // to other translation units, but we don't need to do that here.

// // This is not thread-safe
// // static int rat_things_power{200};

// void power_up_rat_thing(int nuclear_isotopes)
// {
//     static thread_local int rat_things_power{200};

//     rat_things_power += nuclear_isotopes;
//     const auto waste_heat = rat_things_power * 20;
//     if (waste_heat > 10'000)
//     {
//         std::printf("Warning! Hot doggie!\n");
//     }
//     std::printf("Rat things power: %d\n", rat_things_power);
// }

struct RatThing
{
    static thread_local int rat_things_power;
    static void power_up_rat_thing(int nuclear_isotopes)
    {
        rat_things_power += nuclear_isotopes;
        const auto waste_heat = rat_things_power * 20;
        if (waste_heat > 10'000)
        {
            std::printf("Warning! Hot doggie!\n");
        }
        std::printf("Rat things power: %d\n", rat_things_power);
    }
};

thread_local int RatThing::rat_things_power = 200;

int main(void)
{
    // std::printf("Rat things power: %d\n", rat_things_power);
    RatThing::power_up_rat_thing(100);
    // std::printf("Rat things power after power-up: %d\n", rat_things_power);
    RatThing::power_up_rat_thing(500);
    // std::printf("Rat things power after second power-up: %d\n", rat_things_power);

    int *my_int_ptr = new int(42);
    delete my_int_ptr;

    auto array_size = 10;
    int *my_int_array_ptr = new int[array_size];
    delete[] my_int_array_ptr;
}
