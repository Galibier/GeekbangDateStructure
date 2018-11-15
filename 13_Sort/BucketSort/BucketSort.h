#ifndef DATASTRUCTURE_BUCKETSORT_H
#define DATASTRUCTURE_BUCKETSORT_H

#include <iterator>
#include <functional>
#include <algorithm>
#include <vector>

template<size_t BucketSize,
        typename IterT,
        typename T = typename std::iterator_traits<IterT>::value_type,
        typename Compare = std::less <T>>
void bucket_sort(IterT first, IterT last, Compare cmp = Compare()) {
    const T min = *std::min_element(first, last), max = *std::max_element(first, last);
    const T range = max + 1 - min;
    const size_t bucket_num = (range - 1) / BucketSize + 1;

    std::vector <std::vector<T>> buckets(bucket_num);
    for (auto b : buckets) {
        b.reserve(2 * BucketSize);
    }

    for (IterT i = first; i != last; ++i) {
        size_t idx = (*i - min) / BucketSize;
        buckets[idx].emplace_back(*i);
    }

    IterT dest = first;
    for (auto b : buckets) {
        std::sort(b.begin(), b.end(), cmp);
        std::copy(b.begin(), b.end(), dest);
        dest += b.size();
    }

    return;
}

#endif //DATASTRUCTURE_BUCKETSORT_H
