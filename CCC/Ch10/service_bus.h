#pragma once

#include <functional>

#include "brake_command.h"
#include "car_detected.h"
#include "speed_update.h"

using CarDetectedCallback = std::function<void(const CarDetected&)>;
using SpeedUpdateCallback = std::function<void(const SpeedUpdate&)>;

class IServiceBus
{
public:
    virtual ~IServiceBus() = default;
    virtual void publish(const BrakeCommand&) = 0;
    virtual void subscribe(const CarDetectedCallback) = 0;
    virtual void subscribe(const SpeedUpdateCallback) = 0;
};
