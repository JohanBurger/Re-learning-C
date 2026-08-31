#pragma once

#include "service_bus.h"

class MockServiceBus : public IServiceBus
{
public: 
    void publish(const BrakeCommand&) override;
    void subscribe(const CarDetectedCallback) override;
    void subscribe(const SpeedUdateCallback) override;

    BrakeCommand last_command{};
    int published_command_counter{};
    SpeedUdateCallback speed_update_callback{};
    CarDetectedCallback car_detected_callback{};
};
