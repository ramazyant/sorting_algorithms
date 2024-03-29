#ifndef quick_h
#define quick_h

#include <iterator>
#include <functional>

template<typename RandomAccessIterator, typename Order>
void quicksort(RandomAccessIterator first, RandomAccessIterator last, Order order) {
    if (last - first > 1) {
        RandomAccessIterator split = std::partition(first+1, last, std::bind2nd(order, *first));
        std::iter_swap(first, split-1);
        quicksort(first, split-1, order);
        quicksort(split, last, order);
    }
}

template<typename RandomAccessIterator>
void quick_sort(RandomAccessIterator first, RandomAccessIterator last) {
    quicksort(first, last, std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>());
}

#endif /* quick_h */
