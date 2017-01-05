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
    VectorDouble arrive(VectorDouble target_pos);
    VectorDouble wander();
    bool accumulate_force(VectorDouble& total, VectorDouble to_add);

private:
    Vehicle& _vehicle;

    void tag_neighbours();
    double random_jitter();
    vector<Vehicle*> _neighbours;
};

#endif //MINOR_KMINT_STEERING_HPP
