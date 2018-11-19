#ifndef DATASTRUCTURE_BINARYSEARCH_H
#define DATASTRUCTURE_BINARYSEARCH_H

#include <iterator>
#include <functional>

enum class BinarySearchPolicy {
    UNSPECIFIED, FIRST, LAST, FIRST_NOT_LESS, LAST_NOT_GREATER
};

template<typename RandomAccessIterator,
        typename T = typename std::iterator_traits<RandomAccessIterator>::value_type,
        typename Compare = std::less <T>>
RandomAccessIterator binarySearch(RandomAccessIterator first,
                                  RandomAccessIterator last, T target, Compare comp = Compare(),
                                  BinarySearchPolicy policy = BinarySearchPolicy::UNSPECIFIED) {
    RandomAccessIterator res = last;
    while (std::distance(first, last) > 0) {
        RandomAccessIterator mid = first + std::distance(first, last) / 2;
        if (policy == BinarySearchPolicy::FIRST_NOT_LESS) {
            if (!comp(*mid, target)) {
                if (mid == first or comp(*(mid - 1), target)) {
                    res = mid;
                    break;
                } else {
                    last = mid;
                }
            } else {
                first = mid + 1;
            }
        } else if (policy == BinarySearchPolicy::LAST_NOT_GREATER) {
            if (comp(target, *mid)) {
                last = mid;
            } else {
                if (std::distance(mid, last) == 1 or comp(target, *(mid + 1))) {
                    res = mid;
                    break;
                } else {
                    first = mid + 1;
                }
            }
        } else {
            if (comp(*mid, target)) {
                first = mid + 1;
            } else if (comp(target, *mid)) {
                last = mid;
            } else {
                if (policy == BinarySearchPolicy::FIRST) {
                    if (mid == first or comp(*(mid - 1), *mid)) {
                        res = mid;
                        break;
                    } else {
                        last = mid;
                    }
                } else if (policy == BinarySearchPolicy::LAST) {
                    if (std::distance(mid, last) == 1 or comp(*mid, *(mid + 1))) {
                        res = mid;
                        break;
                    } else {
                        first = mid + 1;
                    }
                } else {
                    res = mid;
                    break;
                }
            }
        }
    }
    return res;
}

template<typename RandomAccessIterator,
        typename T = typename std::iterator_traits<RandomAccessIterator>::value_type,
        typename Compare = std::less <T>>
RandomAccessIterator binarySearch(RandomAccessIterator first,
                                  RandomAccessIterator last, T target,
                                  BinarySearchPolicy policy = BinarySearchPolicy::UNSPECIFIED) {
    return binarySearch(first, last, target, Compare(), policy);
}

#endif //DATASTRUCTURE_BINARYSEARCH_H
