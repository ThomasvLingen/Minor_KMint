//
// Created by mafn on 12/22/16.
//

#include "Circle.hpp"

#include <cmath>

Circle::Circle(CoordinateDouble pos, int radius)
: position(pos)
, radius(radius)
{

}

bool Circle::do_intersect(Circle& a, Circle& b)
{
    double dx = a.position.x - b.position.x;
    double dy = a.position.y - b.position.y;
    int combined_radius = a.radius + b.radius;

    return pow(dx, 2) + pow(dy, 2) < pow(combined_radius, 2);
}
