//
// Created by jazula on 12/16/16.
//

#include <iostream>
#include <cmath>
#include "Vehicle.hpp"
#include "../graph/BeeField.hpp"

void Vehicle::Move(int delta_time)
{
    VectorDouble steering_force = behaviour->calculate();
    VectorDouble accel = steering_force; // no mass calculation

    this->velocity = this->velocity + (accel * delta_time); // writing += operators is for losers
    if (this->velocity.get_length() > 0.00000001) { //check for div/0
        this->velocity = this->velocity.truncate(this->max_speed);
    }

    VectorDouble delta_pos = this->velocity * delta_time;
    this->pos = this->pos + delta_pos;

    if (this->velocity.get_length() > 0.00000001) { //check for div/0
        this->heading = this->velocity.normalise();
        this->side = this->heading.perpendicular();
    }

    this->velocity = this->velocity * 0.8;
    this->pos = this->pos.wrap(this->world.mWidth, this->world.mHeight);
}

Vehicle::Vehicle(BeeField& beeField, double max_speed, CoordinateDouble pos)
: pos(pos)
, max_speed(max_speed)
, world(beeField)
, behaviour(new Steering(*this ))
{}
