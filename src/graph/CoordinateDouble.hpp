//
// Created by mafn on 12/16/16.
//

#ifndef MINOR_KMINT_COORDINATEDOUBLE_HPP
#define MINOR_KMINT_COORDINATEDOUBLE_HPP

struct CoordinateDouble {
    double x;
    double y;

    CoordinateDouble operator+(const CoordinateDouble& other)
    {
        return CoordinateDouble {
            this->x + other.x,
            this->y + other.y
        };
    }

    CoordinateDouble operator-(const CoordinateDouble& other)
    {
        return CoordinateDouble {
            this->x - other.x,
            this->y - other.y
        };
    }
};

#endif //MINOR_KMINT_COORDINATEDOUBLE_HPP
