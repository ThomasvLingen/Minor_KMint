//
// Created by jazula on 12/16/16.
//

#include <iostream>
#include "Steering.hpp"
#include "../Vehicle.hpp"

Steering::Steering(Vehicle& _vehicle)
: _vehicle(_vehicle)
{}

VectorDouble Steering::calculate()
{
    VectorDouble desired = (this->_vehicle.pos - this->_vehicle.world.beekeeper->current_position);

    if(desired.get_length() < 50) {
        desired = desired.normalise() * this->_vehicle.max_speed;
        return (desired - this->_vehicle.velocity);
    }

    return {0,0};
}
