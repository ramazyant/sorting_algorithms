#ifndef merge_h
#define merge_h

#include <iterator>
#include <functional>
#include <algorithm>

template<typename RandomAccessIterator, typename Order>
void mergesort(RandomAccessIterator first, RandomAccessIterator last, Order order) {
    if ((last - first) > 1) {
        RandomAccessIterator middle = first + (last - first) / 2;
        mergesort(first, middle, order);
        mergesort(middle, last, order);
        std::inplace_merge(first, middle, last, order);
    }
}

template<typename RandomAccessIterator>
void merge_sort(RandomAccessIterator first, RandomAccessIterator last) {
    mergesort(first, last, std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>());
}

#endif /* merge_h */
