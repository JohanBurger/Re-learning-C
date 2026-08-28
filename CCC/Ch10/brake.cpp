#include <iostream>
#include <stdexcept>

struct SpeedUpdate
{
    double velocity_mps;
};

struct CarDetected
{
    double distance_m;
    double velocity_mps;
};

struct BrakeCommand
{
    double time_to_collision_s;
};

struct ServiceBus
{
    void publish(const BrakeCommand&);
};

template <typename T>
struct AutoBrake
{
    AutoBrake(const T &publish) 
        : collision_threshold_s{5.L},
          speed_mps{}, 
          publish{publish}
    {
        // this->speed_mps = 0L;
    }

    void observe(const SpeedUpdate &su) 
    {
        // this->collision_threshold_s
    }

    void observe(const CarDetected &cd) {}

    void set_collision_threshold_s(double collision_threshold_s)
    {
        this->collision_threshold_s = collision_threshold_s;
    }

    double get_collision_threshold_s()
    {
        return this->collision_threshold_s;
    }

    double get_speed_mps()
    {
        return this->speed_mps;
    }

    private:
    double collision_threshold_s;

    double speed_mps;

    const T &publish;
};

constexpr void assert_that(bool statement, const char* message)
{
    if (!statement)
    {
        throw std::runtime_error{message};
    }
}
void initial_speed_is_zero()
{
    AutoBrake auto_brake{ [](const BrakeCommand&){}};
    assert_that(auto_brake.get_speed_mps() == 0L, "Speed not equal to 0");
}
void initial_sensitivity_is_five() 
{
    AutoBrake auto_brake{ [](const BrakeCommand&) {}};
    assert_that(auto_brake.get_collision_threshold_s() == 5L, "Initial threshold not equal to 5"); 
}
void run_test(void (*unit_test)(), const char *name)
{
    try 
    {
        unit_test();
        std::cout << "[+] Test " << name << "successful." << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "[-] Test Failure: " << name << ": " << e.what() << std::endl;
    }
}

int main(void)
{
    run_test(initial_speed_is_zero, "Initial speed is zero");
    run_test(initial_sensitivity_is_five, "Initial sensitivity is five");
    // ServiceBus bus;
    // AutoBrake auto_brake{
    //     [&bus] (const auto &cmd)
    //     {
    //         bus.publish(cmd);
    //     }
    // };

    // while (true) 
    // {
    //     auto_brake.observe(SpeedUpdate{10L});
    //     auto_brake.observe(CarDetected{250L, 25L});
    // }
}
