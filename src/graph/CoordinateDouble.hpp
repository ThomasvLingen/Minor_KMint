//
// Created by mafn on 12/16/16.
//

#ifndef MINOR_KMINT_COORDINATEDOUBLE_HPP
#define MINOR_KMINT_COORDINATEDOUBLE_HPP

class VectorDouble;

struct CoordinateDouble {
    double x;
    double y;

    CoordinateDouble(double x, double y);
    CoordinateDouble(VectorDouble& other);

    CoordinateDouble operator+(VectorDouble& other);
    CoordinateDouble operator+(const CoordinateDouble& other);
    CoordinateDouble operator-(const CoordinateDouble& other);
    bool operator==(const VectorDouble& other);
    bool operator!=(const VectorDouble& other);
};

#endif //MINOR_KMINT_COORDINATEDOUBLE_HPP
