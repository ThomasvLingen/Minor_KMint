//
// Created by jazula on 12/16/16.
//

#include "Steering.hpp"
#include "../Vehicle.hpp"

Steering::Steering(Vehicle& _vehicle)
: _vehicle(_vehicle)
{}

VectorDouble Steering::calculate()
{
    VectorDouble desired = (this->_vehicle.world.beekeeper->current_position - this->_vehicle.pos);
    desired = desired.normalise() * this->_vehicle.max_speed;

    return (desired - this->_vehicle.velocity);
}
