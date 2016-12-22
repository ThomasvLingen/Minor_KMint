//
// Created by mafn on 12/22/16.
//

#ifndef MINOR_KMINT_VECTORUTIL_HPP
#define MINOR_KMINT_VECTORUTIL_HPP

#include <vector>
#include <algorithm>

class VectorUtil {
public:
    template<class T>
    static void remove(std::vector<T>& haystack, T to_remove)
    {
        haystack.erase(
            std::remove(haystack.begin(), haystack.end(), to_remove),
            haystack.end()
        );
    }
};

#endif //MINOR_KMINT_VECTORUTIL_HPP
