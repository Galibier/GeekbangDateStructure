#ifndef DATASTRUCTURE_BINARYSEARCH_H
#define DATASTRUCTURE_BINARYSEARCH_H

#include <iterator>
#include <functional>

template<typename RandomAccessIterator,
        typename T = typename std::iterator_traits<RandomAccessIterator>::value_type,
        typename Compare = std::less <T>>
RandomAccessIterator binarySearch(RandomAccessIterator first, RandomAccessIterator last, T target, Compare comp = Compare()) {
    RandomAccessIterator res = last;
    while (std::distance(first, last) > 0) {
        RandomAccessIterator mid = first + std::distance(first, last) / 2;
        if (comp(*mid, target)) {
            first = mid + 1;
        } else if (comp(target, *mid)) {
            last = mid;
        } else {
            res = mid;
            break;
        }
    }
    return res;
}

#endif //DATASTRUCTURE_BINARYSEARCH_H
