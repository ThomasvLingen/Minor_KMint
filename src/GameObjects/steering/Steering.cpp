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
    return (
        this->seperation() * 4.0
        + this->allignment() * 1.8
        + this->cohesion() * 0.5
//        + this->evade(this->_vehicle.world.beekeeper->current_position) * 5
    ).truncate(this->_vehicle.max_force);
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

VectorDouble Steering::evade(VectorDouble target_pos)
{
    VectorDouble desired = (this->_vehicle.pos - target_pos);

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

VectorDouble Steering::allignment()
{
    VectorDouble heading = {0,0};

    if (this->_neighbours.size() > 0) {
        for (auto& neighbour : this->_neighbours) {
            heading = heading + neighbour->heading;
        }

        heading = heading / (double)this->_neighbours.size();
        heading = heading - this->_vehicle.heading;
    }

    return heading;
}

VectorDouble Steering::cohesion()
{
    VectorDouble center_of_mass = {0,0};
    VectorDouble force = {0,0};

    if (this->_neighbours.size() > 0) {
        for (auto& neighbour : this->_neighbours) {
            center_of_mass = center_of_mass + neighbour->pos;
        }

        center_of_mass = center_of_mass / (double)this->_neighbours.size();
        force = this->seek(center_of_mass);
    }

    return force;
}

VectorDouble Steering::seek(VectorDouble target_pos)
{
    VectorDouble desired = target_pos - this->_vehicle.pos;
    desired = desired.normalise() * this->_vehicle.max_speed;

    return (desired - this->_vehicle.velocity);
}
