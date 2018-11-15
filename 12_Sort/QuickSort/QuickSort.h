#ifndef DATASTRUCTURE_QUICKSORT_H
#define DATASTRUCTURE_QUICKSORT_H

#include <functional>
#include <iterator>
#include <algorithm>
#include <utility>

namespace detail {
    template<typename T, typename Compare = std::less <T>>
    const T &median(const T &a, const T &b, const T &c, Compare cmp = Compare()) {
        if (cmp(a, b) and cmp(b, c) or cmp(c, b) and cmp(b, a)) {
            return b;
        } else if (cmp(b, c) and cmp(c, a) or cmp(a, c) and cmp(c, b)) {
            return c;
        } else {
            return a;
        }
    }

    template<typename Iter,
            typename T = typename std::iterator_traits<Iter>::value_type,
            typename Compare = std::less <T>>
    const T &iterMedian(Iter a, Iter b, Iter c, Compare cmp = Compare()) {
        return median(*a, *b, *c, cmp);
    }

    template<typename BidirIt,
            typename T = typename std::iterator_traits<BidirIt>::value_type,
            typename Compare = std::less <T>>
    std::pair <BidirIt, BidirIt> inplace_partition(BidirIt first,
                                                   BidirIt last,
                                                   const T &pivot,
                                                   Compare comp = Compare()) {
        BidirIt last_less, last_greater, first_equal, last_equal;
        for (last_less = first, last_greater = first, first_equal = last;
             last_greater != first_equal;) {
            if (comp(*last_greater, pivot)) {
                std::iter_swap(last_greater++, last_less++);
            } else if (comp(pivot, *last_greater)) {
                ++last_greater;
            } else {  // pivot == *last_greater
                std::iter_swap(last_greater, --first_equal);
            }
        }
        const auto cnt = std::distance(first_equal, last);
        std::swap_ranges(first_equal, last, last_less);
        first_equal = last_less;
        last_equal = first_equal + cnt;
        return {first_equal, last_equal};
    }
}

template<typename BidirIt,
        typename T = typename std::iterator_traits<BidirIt>::value_type,
        typename Compare = std::less <T>>
void quick_sort(BidirIt first, BidirIt last, Compare comp = Compare()) {
    for (auto size = std::distance(first, last); size > 1; size = std::distance(first, last)) {
        const T pivot = detail::iter_median(first, last - 1, first + size / 2, comp);
        const auto eq = detail::inplace_partition(first, last, pivot, comp);
        quick_sort(first, eq.first, comp);
        first = eq.second;
    }
}

#endif //DATASTRUCTURE_QUICKSORT_H
