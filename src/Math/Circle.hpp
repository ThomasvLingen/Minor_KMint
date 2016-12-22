//
// Created by mafn on 12/22/16.
//

#ifndef MINOR_KMINT_CIRCLE_HPP
#define MINOR_KMINT_CIRCLE_HPP


#include "../graph/CoordinateDouble.hpp"

class Circle {
public:
    Circle(CoordinateDouble pos, int radius);

    CoordinateDouble position;
    int radius;

    static bool do_intersect(Circle& a, Circle& b);
private:
};


#endif //MINOR_KMINT_CIRCLE_HPP
