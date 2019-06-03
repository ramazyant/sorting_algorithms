#ifndef insertion_h
#define insertion_h

#include <algorithm>
#include <iterator>

template <typename RandomAccessIterator, typename Predicate>
void insertionsort(RandomAccessIterator begin, RandomAccessIterator end, Predicate p) {
    for (auto i = begin; i != end; ++i) {
        auto j = i + 1;
        std::rotate(std::upper_bound(begin, i, *i, p), i, j);
    }
}

template <typename RandomAccessIterator>
void insertion_sort(RandomAccessIterator begin, RandomAccessIterator end) {
    insertionsort(begin, end, std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>());
}

#endif /* insertion_h */
