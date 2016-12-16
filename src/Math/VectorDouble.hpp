//
// Created by mafn on 12/16/16.
//

#ifndef MINOR_KMINT_VECTORDOUBLE_HPP
#define MINOR_KMINT_VECTORDOUBLE_HPP


#include "../graph/CoordinateDouble.hpp"
#include <cmath>

struct VectorDouble {
    VectorDouble();
    VectorDouble(double x, double y);
    VectorDouble(CoordinateDouble obj);

    double x;
    double y;

    VectorDouble normalise();
    VectorDouble truncate(double value);
    VectorDouble perpendicular();
    double get_length();
    VectorDouble operator*(const int multiplication);
    VectorDouble operator*(const double multiplication);
    VectorDouble operator+(VectorDouble other);
};


#endif //MINOR_KMINT_VECTORDOUBLE_HPP
