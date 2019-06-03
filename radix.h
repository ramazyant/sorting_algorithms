#ifndef radix_h
#define radix_h

#include "counting.h"

template <typename T>
void radix_sort(std::vector<T> & arr) {
    int m = *std::max_element(arr.begin(), arr.end());
    //
    for (int exp = 1; m/exp > 0; exp *= 10) {
        counting_sort(arr);
    }
}

#endif /* radix_h */
