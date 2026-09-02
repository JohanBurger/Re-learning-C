#pragma once

#include "service_bus.h"

class ServiceBusMock : public IServiceBus
{
public: 
    void publish(const BrakeCommand&) override;
    void subscribe(const CarDetectedCallback) override;
    void subscribe(const SpeedUpdateCallback) override;

    BrakeCommand last_command{};
    int published_command_counter{};
    SpeedUpdateCallback speed_update_callback{};
    CarDetectedCallback car_detected_callback{};
};
