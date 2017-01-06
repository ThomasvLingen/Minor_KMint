//
// Created by jazula on 12/16/16.
//

#ifndef MINOR_KMINT_VEHICLE_HPP
#define MINOR_KMINT_VEHICLE_HPP


#include "../Math/VectorDouble.hpp"
#include "../graph/CoordinateDouble.hpp"
#include "steering/Steering.hpp"

class BeeField;

class Vehicle {
    friend class Steering;
public:
    Vehicle(BeeField& beeField, double max_speed, CoordinateDouble pos);

    CoordinateDouble pos;

protected:
    VectorDouble velocity;
    VectorDouble heading;
    VectorDouble side;

    double max_speed;
    double max_vision_range = 50;
    double max_force = 8;
//    double max_turn_rate;

    double wander_radius = 3;
    double wander_distance = 2.5;
    double wander_jitter = 0.5;
    VectorDouble wander_target;

    double weight = 0.1;

    BeeField& world;
    Steering* behaviour;

    void Move(float delta_time);
};


#endif //MINOR_KMINT_VEHICLE_HPP
