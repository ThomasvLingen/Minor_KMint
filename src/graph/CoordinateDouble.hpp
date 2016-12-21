//
// Created by mafn on 12/16/16.
//

#ifndef MINOR_KMINT_COORDINATEDOUBLE_HPP
#define MINOR_KMINT_COORDINATEDOUBLE_HPP

#include "Vertex.hpp"

class VectorDouble;

struct CoordinateDouble {
    double x;
    double y;

    CoordinateDouble();
    CoordinateDouble(double x, double y);
    CoordinateDouble(VectorDouble& other);
    CoordinateDouble(CoordinateInt other);

    CoordinateDouble operator+(VectorDouble& other);
    CoordinateDouble operator+(const CoordinateDouble& other);
    CoordinateDouble operator-(const CoordinateDouble& other);
    bool operator==(const VectorDouble& other);
    bool operator!=(const VectorDouble& other);

    CoordinateDouble wrap(int max_x, int max_y);
};

#endif //MINOR_KMINT_COORDINATEDOUBLE_HPP