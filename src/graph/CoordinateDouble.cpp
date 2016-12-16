//
// Created by mafn on 12/16/16.
//

#include "../Math/VectorDouble.hpp"
#include "CoordinateDouble.hpp"

CoordinateDouble::CoordinateDouble(double x, double y)
: x(x)
, y(y)
{

}

CoordinateDouble::CoordinateDouble(VectorDouble& other)
: x(other.x)
, y(other.y)
{

}

CoordinateDouble CoordinateDouble::operator+(VectorDouble& other)
{
    return *this + CoordinateDouble(other);
}

CoordinateDouble CoordinateDouble::operator+(const CoordinateDouble& other)
{
    return CoordinateDouble {
        this->x + other.x,
        this->y + other.y
    };
}

CoordinateDouble CoordinateDouble::operator-(const CoordinateDouble& other)
{
    return CoordinateDouble {
        this->x - other.x,
        this->y - other.y
    };
}

bool CoordinateDouble::operator==(const VectorDouble& other)
{
    return this->x == other.x && this->y == other.y;
}

bool CoordinateDouble::operator!=(const VectorDouble& other)
{
    return !(*this == other);
}
