#pragma once

#include "brake_command.h"
#include "car_detected.h"
#include "service_bus.h"
#include "speed_update.h"

class AutoBrake
{
public:
    AutoBrake(IServiceBus&);
    void set_collision_threshold_s(double);
    double get_collision_threshold_s() const;
    double get_speed_mps() const;

private:
    double collision_threshold_s;
    double speed_mps;
};
