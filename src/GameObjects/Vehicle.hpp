//
// Created by jazula on 12/16/16.
//

#ifndef MINOR_KMINT_VEHICLE_HPP
#define MINOR_KMINT_VEHICLE_HPP


#include "../Math/VectorDouble.hpp"
#include "../graph/CoordinateDouble.hpp"
#include "../graph/BeeField.hpp"
#include "steering/Steering.hpp"

class Vehicle {
public:
    Vehicle(BeeField& beeField, double max_speed);

private:

    CoordinateDouble pos;
    VectorDouble velocity;
    VectorDouble heading;
    VectorDouble side;

    double max_speed;
//    double max_force;
//    double max_turn_rate;

    BeeField& world;
    Steering* behaviour;

    void Move(int delta_time);
};


#endif //MINOR_KMINT_VEHICLE_HPP
