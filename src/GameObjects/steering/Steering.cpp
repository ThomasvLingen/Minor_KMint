//
// Created by jazula on 12/16/16.
//

#include <iostream>
#include "Steering.hpp"
#include "../Vehicle.hpp"
#include "../../graph/BeeField.hpp"
#include "../Bee/Bee.hpp"
#include "../../RandomUtil.hpp"

Steering::Steering(Vehicle& _vehicle)
: _vehicle(_vehicle)
{}

VectorDouble Steering::calculate()
{
    this->tag_neighbours();

    VectorDouble total_force {0,0};
    VectorDouble current_force {0,0};

    current_force = this->evade(this->_vehicle.world.beekeeper->current_position)
        * 15;
    if (!this->accumulate_force(total_force, current_force)) {
        return total_force;
    }

    current_force = this->seperation()
        * 100;
    if (!this->accumulate_force(total_force, current_force)) {
        return total_force;
    }

    current_force = this->allignment()
        * 1;
    if (!this->accumulate_force(total_force, current_force)) {
        return total_force;
    }

    current_force = this->cohesion()
        * 0.3;
    if (!this->accumulate_force(total_force, current_force)) {
        return total_force;
    }

    current_force = this->wander()
        * 0.1;
    if (!this->accumulate_force(total_force, current_force)) {
        return total_force;
    }

    return total_force;
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

VectorDouble Steering::arrive(VectorDouble target_pos)
{
    VectorDouble to_target = target_pos - this->_vehicle.pos;

    double distance = to_target.get_length();

    if (distance > 0) {
        const double deceleration_value = 0.5;

        double speed = distance / deceleration_value;

        speed = (speed > this->_vehicle.max_speed) ? this->_vehicle.max_speed : speed;

        VectorDouble desired = to_target * speed / distance;

        return desired - this->_vehicle.velocity;
    }

    return VectorDouble{0,0};
}

//todo make as in book
VectorDouble Steering::wander()
{
    this->_vehicle.wander_target =
        this->_vehicle.wander_target + VectorDouble{this->random_jitter() * this->_vehicle.wander_jitter,
                                        this->random_jitter() * this->_vehicle.wander_jitter};
    this->_vehicle.wander_target = this->_vehicle.wander_target.normalise();

    this->_vehicle.wander_target = this->_vehicle.wander_target * this->_vehicle.wander_radius;

    VectorDouble target = this->_vehicle.wander_target + VectorDouble{this->_vehicle.wander_distance, 0};

    return target;
}

double Steering::random_jitter()
{
    return (double)((RANDOM.get_random_int(0,200) - 100) / 100);
}

bool Steering::accumulate_force(VectorDouble& total, VectorDouble to_add)
{
    double remaining = this->_vehicle.max_force - total.get_length();

    if (remaining <= 0.0) {
        return false;
    }

    if (to_add.get_length() < remaining) {
        total = total + to_add;
    } else {
        total = total + (to_add.normalise() * remaining);
    }

    return true;
}
