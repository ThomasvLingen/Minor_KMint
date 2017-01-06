//
// Created by mafn on 12/16/16.
//

#include "VectorDouble.hpp"

VectorDouble::VectorDouble()
: x(0)
, y(0)
{

}

VectorDouble::VectorDouble(double x, double y)
: x(x)
, y(y)
{

}

VectorDouble::VectorDouble(CoordinateDouble obj)
: x(obj.x)
, y(obj.y)
{

}

VectorDouble VectorDouble::normalise()
{
    double length = this->get_length();

    return VectorDouble {
        (length == 0) ? this->x : this->x / length,
        (length == 0) ? this->y : this->y / length
    };
}

double VectorDouble::get_length()
{
    // We pythagoras now
    return sqrt(pow(this->x, 2) + pow(this->y, 2));
}

VectorDouble VectorDouble::operator*(const int multiplication)
{
    return *this * (double)multiplication;
}

VectorDouble VectorDouble::operator*(const double multiplication)
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

VectorDouble VectorDouble::operator-(VectorDouble other)
{
    return {
        this->x - other.x,
        this->y - other.y
    };
}

VectorDouble VectorDouble::truncate(double value)
{
    if (this->get_length() > value) {
        return this->normalise() * value;
    }
    return *this;
}

VectorDouble VectorDouble::perpendicular()
{
    return {
        this->x * -1,
        this->y
    };
}

VectorDouble VectorDouble::operator/(const double division)
{
    return {
        this->x / division,
        this->y / division
    };
}

ostream& operator<<(ostream& os, VectorDouble& vec)
{
    os << "[" << vec.x << "," << vec.y << "]";

    return os;
}
