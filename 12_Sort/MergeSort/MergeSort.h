#ifndef DATASTRUCTURE_MERGESORT_H
#define DATASTRUCTURE_MERGESORT_H

namespace detail {
    template<typename InputIt1, typename InputIt2, typename OutputIt,
            typename BinaryPred = std::less<typename std::iterator_traits<InputIt1>::value_type>>
    OutputIt merge(InputIt1 first1, InputIt1 last1,
                   InputIt2 first2, InputIt2 last2,
                   OutputIt d_first,
                   BinaryPred comp = BinaryPred()) {
        for (; first1 != last1; ++d_first) {
            if (first2 == last2) {
                return std::copy(first1, last1, d_first);
            }
            if (comp(*first2, *first1)) {
                *d_first = *first2;
                ++first2;
            } else {
                *d_first = *first1;
                ++first1;
            }
        }
        return std::copy(first2, last2, d_first);
    }
}

template<typename FrwdIt,
        typename Compare = std::less<typename std::iterator_traits<FrwdIt>::value_type>>
void mergeSort(FrwdIt first, FrwdIt last, Compare cmp = Compare()) {
    const auto len = std::distance(first, last);
    if (len <= 1) {
        return;
    }

    auto cut = first + len / 2;
    mergeSort(first, cut, cmp);
    mergeSort(cut, last, cmp);
    std::vector<typename std::iterator_traits<FrwdIt>::value_type> tmp;
    tmp.reserve(len);
    detail::merge(first, cut, cut, last, std::back_inserter(tmp), cmp);
    std::copy(tmp.begin(), tmp.end(), first);
}

template<typename BidirIt,
        typename Compare = std::less<typename std::iterator_traits<BidirIt>::value_type>>
void inplaceMergeSort(BidirIt first, BidirIt last, Compare cmp = Compare()) {
    const auto len = std::distance(first, last);
    if (len <= 1) {
        return;
    }

    auto cut = first + len / 2;
    inplaceMergeSort(first, cut, cmp);
    inplaceMergeSort(cut, last, cmp);
    std::inplace_merge(first, cut, last, cmp);
}

#endif //DATASTRUCTURE_MERGESORT_H
