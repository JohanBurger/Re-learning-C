#include <iostream>
#include <stdexcept>

#include "auto_brake.h"
#include "brake_command.h"
#include "car_detected.h"
#include "mock_service_bus.h"
#include "speed_update.h"

constexpr void assert_that(bool statement, const char* message)
{
    if (!statement)
    {
        throw std::runtime_error{message};
    }
}

void initial_speed_is_zero()
{
    MockServiceBus bus{};
    AutoBrake auto_brake{ bus };
    assert_that(auto_brake.get_speed_mps() == 0L, "Speed not equal to 0");
}

void initial_sensitivity_is_five() 
{
    MockServiceBus bus{};
    AutoBrake auto_brake{ bus };
    assert_that(auto_brake.get_collision_threshold_s() == 5L, "Initial threshold not equal to 5"); 
}

void sensitivity_greater_than_one()
{
    MockServiceBus bus{};
    AutoBrake auto_brake{ bus };
    try
    {
        auto_brake.set_collision_threshold_s(0.5f);
    }
    catch(const std::exception& e)
    {
        return;
    }
    assert_that(false, "No exception thrown.");
    
}

void speed_is_saved()
{
    MockServiceBus bus{};
    AutoBrake auto_brake{ bus };
    auto speed = 100.0;
    bus.speed_update_callback(SpeedUpdate{speed});
    assert_that(speed == auto_brake.get_speed_mps(), "Speed not saved to 100");

    speed = 50.0;
    bus.speed_update_callback(SpeedUpdate{speed});
    assert_that(speed == auto_brake.get_speed_mps(), "Speed not saved to 50");

    speed = 0.0;
    bus.speed_update_callback(SpeedUpdate{speed});
    assert_that(speed == auto_brake.get_speed_mps(), "Speed not saved to 0");
}

void alert_when_imminent()
{
    MockServiceBus bus{};
    AutoBrake auto_brake{ bus };

    auto_brake.set_collision_threshold_s(10.0);
    bus.speed_update_callback(SpeedUpdate{100.0});
    bus.car_detected_callback(CarDetected{100.0, 0.0});

    assert_that(bus.published_command_counter == 1, "Brake commands published not one");
}

void no_alert_when_not_imminent()
{
    MockServiceBus bus{};
    AutoBrake auto_brake{ bus };

    auto_brake.set_collision_threshold_s(2L);
    bus.speed_update_callback(SpeedUpdate{ 100L });
    bus.car_detected_callback(CarDetected{ 1000L, 50L });

    assert_that(bus.published_command_counter == 0, "Brake command published not zero");
}

void run_test(void (*unit_test)(), const char *name)
{
    try 
    {
        unit_test();
        std::cout << "[+] Test " << name << " successful." << std::endl;
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
    run_test(sensitivity_greater_than_one, "Sensitivity greater than one");
    run_test(speed_is_saved, "Speed is saved");
    run_test(alert_when_imminent, "Brake command published when imminent");
    run_test(no_alert_when_not_imminent, "No brake command published when not imminent");
}
