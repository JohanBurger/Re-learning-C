#include <stdexcept>

#include "auto_brake.h"
#include "service_bus.h"

AutoBrake::AutoBrake(IServiceBus &service_bus) 
    : collision_threshold_s{5.L},
      speed_mps{}
{
    service_bus.subscribe([this](const SpeedUpdate &speed_update)
    {
        speed_mps = speed_update.velocity_mps;
    });

    service_bus.subscribe([this, &service_bus](const CarDetected &car_detected)
    {
        const auto relative_velocity_mps = this->speed_mps - car_detected.velocity_mps;
        const auto time_to_collision_s = car_detected.distance_m / relative_velocity_mps;
        if (time_to_collision_s > 0 
            && time_to_collision_s <= this->collision_threshold_s)
        {
            service_bus.publish(BrakeCommand{time_to_collision_s});
        }
    });
}

void AutoBrake::set_collision_threshold_s(double collision_threshold_s)
{
    if (collision_threshold_s < 1)
    {
        throw std::invalid_argument("Collision threshold less than 1.0.");
    }
    this->collision_threshold_s = collision_threshold_s;
}

double AutoBrake::get_collision_threshold_s()
{
    return this->collision_threshold_s;
}

double AutoBrake::get_speed_mps()
{
    return this->speed_mps;
}
