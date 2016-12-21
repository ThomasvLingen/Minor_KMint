//
// Created by jazula on 12/16/16.
//

#ifndef MINOR_KMINT_STEERING_HPP
#define MINOR_KMINT_STEERING_HPP


#include "../../Math/VectorDouble.hpp"
class Vehicle;

class Steering {
public:
    Steering(Vehicle& _vehicle);

    VectorDouble calculate();

private:
    Vehicle& _vehicle;
};


#endif //MINOR_KMINT_STEERING_HPP
