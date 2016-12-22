//
// Created by jazula on 12/16/16.
//

#include <iostream>
#include "Steering.hpp"
#include "../Vehicle.hpp"
#include "../../graph/BeeField.hpp"
#include "../Bee/Bee.hpp"

Steering::Steering(Vehicle& _vehicle)
: _vehicle(_vehicle)
{}

VectorDouble Steering::calculate()
{
    this->tag_neighbours();
    return (this->seperation() + this->evade() * 5);
}

void Steering::tag_neighbours()
{
    this->_neighbours.clear();

    for (Vehicle* target : this->_vehicle.world.bees) {

        if (target == &this->_vehicle) {
            continue;
        }

        VectorDouble distance = target->pos - this->_vehicle.pos;

        if (distance.get_length() * distance.get_length() < this->_vehicle.max_vision_range * this->_vehicle.max_vision_range) {
            this->_neighbours.push_back(target);
        }
    }
}

VectorDouble Steering::evade()
{
    VectorDouble desired = (this->_vehicle.pos - this->_vehicle.world.beekeeper->current_position);

    if (desired.get_length() < this->_vehicle.max_vision_range * 2) {
        desired = desired.normalise() * this->_vehicle.max_speed;
        return (desired - this->_vehicle.velocity);
    }

    return {0,0};
}

VectorDouble Steering::seperation()
{
    VectorDouble force = {0,0};

    for (auto& neighbour : this->_neighbours) {
        VectorDouble distance = this->_vehicle.pos - neighbour->pos;
        force = force + (distance.normalise() / distance.get_length());
    }

    return force;
}
