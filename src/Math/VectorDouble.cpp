//
// Created by mafn on 12/16/16.
//

#include "VectorDouble.hpp"
#include <cmath>

VectorDouble VectorDouble::normalise()
{
    double length = this->get_length();

    return VectorDouble {
        this->x / length,
        this->y / length
    };
}

double VectorDouble::get_length()
{
    // We pythagoras now
    return sqrt(pow(this->x, 2) + pow(this->y, 2));
}
