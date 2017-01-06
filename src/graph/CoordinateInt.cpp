//
// Created by mafn on 1/6/17.
//

#include "CoordinateInt.hpp"

std::ostream& operator<<(std::ostream& os, CoordinateInt& cord)
{
    os << "[" << cord.x << "," << cord.y << "]";

    return os;
}
