#ifndef counting_h
#define counting_h

#include <cstdio>
#include <vector>
#include <algorithm>

template <typename T>
void counting_sort (std::vector<T> & arr) {
    int max = *std::max_element(arr.begin(), arr.end());
    int min = *std::min_element(arr.begin(), arr.end());
    size_t range = max - min + 1;
    //
    std::vector<T> count(range), output(arr.size());
    for(int i = 0; i < arr.size(); ++i) {
        ++count[arr[i] - min];
    }
    //
    for(int i = 1; i < count.size(); ++i) {
        count[i] += count[i - 1];
    }
    //
    for(long i = arr.size() - 1; i >= 0; --i) {
        output[count[arr[i] - min] - 1] = arr[i];
        --count[arr[i] - min];
    }
    //
    for(int i = 0; i < arr.size(); ++i) {
        arr[i] = output[i];
    }
}

#endif /* counting_h */
