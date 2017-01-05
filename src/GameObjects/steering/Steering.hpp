//
// Created by jazula on 12/16/16.
//

#ifndef MINOR_KMINT_STEERING_HPP
#define MINOR_KMINT_STEERING_HPP


#include <vector>
#include "../../Math/VectorDouble.hpp"
class Vehicle;

using std::vector;
using std::pair;

class Steering {
public:
    Steering(Vehicle& _vehicle);

    VectorDouble calculate();
    VectorDouble evade(VectorDouble target_pos);
    VectorDouble seperation();
    VectorDouble allignment();
    VectorDouble cohesion();
    VectorDouble seek(VectorDouble target_pos);

private:
    Vehicle& _vehicle;

    void tag_neighbours();
    vector<Vehicle*> _neighbours;
};

#endif //MINOR_KMINT_STEERING_HPP
