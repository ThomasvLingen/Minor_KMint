//
// Created by mafn on 12/16/16.
//

#include "VectorDouble.hpp"
#include <cmath>

VectorDouble VectorDouble::normalise()
{
    return this->truncate(1);
}

double VectorDouble::get_length()
{
    // We pythagoras now
    return sqrt(pow(this->x, 2) + pow(this->y, 2));
}

VectorDouble VectorDouble::operator*(const int multiplication)
{
    return {
        this->x * multiplication,
        this->y * multiplication
    };
}

VectorDouble VectorDouble::operator+(VectorDouble other)
{
    return {
        this->x + other.x,
        this->y + other.y
    };
}

VectorDouble VectorDouble::truncate(double value)
{
    double length = this->get_length();
    double div_value = length / value;

    return VectorDouble {
        this->x / div_value,
        this->y / div_value
    };
}