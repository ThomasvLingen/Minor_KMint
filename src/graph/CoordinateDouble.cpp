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

CoordinateDouble::CoordinateDouble(CoordinateInt other)
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

CoordinateDouble CoordinateDouble::wrap(int max_x, int max_y)
{
    double new_x = fmod(this->x, max_x);
    double new_y = fmod(this->y, max_y);

    return {
        (new_x < 0) ? new_x + max_x : new_x,
        (new_y < 0) ? new_y + max_y : new_y
    };
}

CoordinateDouble::CoordinateDouble()
: x(0)
, y(0)
{

}

double CoordinateDouble::get_raw_distance_to_point(CoordinateDouble pos)
{
    return pow(this->x - pos.x, 2) + pow(this->y - pos.y, 2);
}
