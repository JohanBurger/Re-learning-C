# include "mock_service_bus.h"

void ServiceBusMock::publish(const BrakeCommand &brake_command)
{
    this->published_command_counter++;
    this->last_command = brake_command;
}

void ServiceBusMock::subscribe(const CarDetectedCallback car_detected_callback)
{
    this->car_detected_callback = car_detected_callback;
}

void ServiceBusMock::subscribe(const SpeedUpdateCallback speed_update_callback)
{
    this->speed_update_callback = speed_update_callback;
}
