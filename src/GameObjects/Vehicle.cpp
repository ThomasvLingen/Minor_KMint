//
// Created by jazula on 12/16/16.
//

#include "Vehicle.hpp"

void Vehicle::Move(int delta_time)
{
    VectorDouble steering_force(5,5); //= behaviour->calculate();
    VectorDouble accel = steering_force; // no mass calculation

    this->velocity = this->velocity + (accel * delta_time); // writing += operators is for losers
    this->velocity.truncate(this->max_speed);

    VectorDouble delta_pos = this->velocity * delta_time;
    this->pos = this->pos + delta_pos;

    if (this->velocity.get_length() > 0.00000001) { //check for div/0
        this->heading = this->velocity.normalise();
        this->side = this->heading.perpendicular();
    }

    this->pos = this->pos.wrap(600, 600); //hardcoded screensize
}

Vehicle::Vehicle(BeeField& beeField, double max_speed)
: max_speed(max_speed)
, world(beeField)
{}
