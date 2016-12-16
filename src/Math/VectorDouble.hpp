//
// Created by mafn on 12/16/16.
//

#ifndef MINOR_KMINT_VECTORDOUBLE_HPP
#define MINOR_KMINT_VECTORDOUBLE_HPP


struct VectorDouble {
    double x;
    double y;

    VectorDouble normalise();
    double get_length();
};


#endif //MINOR_KMINT_VECTORDOUBLE_HPP
