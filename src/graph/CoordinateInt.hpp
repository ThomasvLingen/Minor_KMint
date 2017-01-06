//
// Created by mafn on 11/15/16.
//

#ifndef MINOR_KMINT_COORDINATEINT_HPP
#define MINOR_KMINT_COORDINATEINT_HPP

#include <ostream>

struct CoordinateInt {
    int x;
    int y;
};

std::ostream& operator<<(std::ostream& os, CoordinateInt& cord);

#endif //MINOR_KMINT_COORDINATEINT_HPP
