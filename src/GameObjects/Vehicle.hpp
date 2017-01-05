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
    double max_vision_range = 30;
    double max_force = 25;
//    double max_turn_rate;

    BeeField& world;
    Steering* behaviour;

    void Move(int delta_time);
};


#endif //MINOR_KMINT_VEHICLE_HPP
