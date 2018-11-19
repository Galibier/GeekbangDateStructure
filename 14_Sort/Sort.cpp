template<typename RandomAccessIterator>
void sort(RandomAccessIterator first, RandomAccessIterator last) {
    if (first != last) {
        __introsort_loop(first, last, value_type(first), __lg(last - first) * 2);
        __final_insertion_sort(first, last);
    }
}

template<typename RandomAccessIterator, typename T, typename Size>
void __introsort_loop(RandomAccessIterator first, RandomAccessIterator last, T *, Size depth_limit) {
    while (last - first > __stl_threshold) {
        if (depth_limit == 0) {
            partial_sort(first, last, last);
            return;
        }
        --depth_limit;
        RandomAccessIterator cut = __unguarded_partition(
                first, last, T(__median(*first, *(first + (last - first) / 2), *(last - 1))));
        __introsort_loop(cut, last, value_type(first), depth_limit);
        last = cut;
    }
}

template<typename RandomAccessIterator, class T>
RandomAccessIterator __unguarded_partition(RandomAccessIterator first, RandomAccessIterator last, T pivot) {
    while (true) {
        while (*first < pivot) {
            ++first;
        }
        --last;
        while (pivot < *last) {
            --last;
        }
        if (!(first < last)) {
            return first;
        }
        iter_swap(first, last);
        ++first;
    }
}

template<typename RandomAccessIterator, typename Compare>
void partial_sort(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last, Compare comp) {
    __partial_sort(first, middle, last, value_type(first), comp);
}

template<typename RandomAccessIterator, typename T, typename Compare>
void
__partial_sort(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last, T *, Compare comp) {
    make_heap(first, middle, comp);
    for (RandomAccessIterator i = middle; i < last, ++i) {
        if (comp(*i, *first)) {
            __pop_heap(first, middle, i, T(*i), comp, distance_type(first));
        }
        sort_heap(first, middle, comp);
    }
}


template<typename RandomAccessIterator>
void __final_insertion_sort(RandomAccessIterator first, RandomAccessIterator last) {
    if (last - first > __stl_threshold) {
        __insertion_sort(first, first + __stl_threshold);
        __unguarded_insertion_sort(fist + __stl_threshold, last);
    } else {
        __insertion_sort(first, last);
    }
}


template<typename RandomAccessIterator>
void __insertion_sort(RandomAccessIterator first, RandomAccessIterator last) {
    if (first == last) {
        return;
    }
    for (RandomAccessIterator i = first + 1; i != last; ++i) {
        __linear_insert(first, i, value_type(first));
    }
}

template<typename RandomAccessIterator, typename T>
void __linear_insert(RandomAccessIterator first, RandomAccessIterator last, T *) {
    T value = *last;
    if (value < *first) {
        copy_backward(first, last, last + 1);
        *first = value;
    } else {
        __unguarded_linear_insert(last, value);
    }
}

template<typename RandomAccessIterator>
void __unguarded_insertion_sort(RandomAccessIterator first, RandomAccessIterator last) {
    __unguarded_insertion_sort_aux(first, last, value_type(first));
}

template<typename RandomAccessIterator, typename T>
void __unguarded_insertion_sort_aux(RandomAccessIterator first, RandomAccessIterator last, T *) {
    for (RandomAccessIteratori = first; i != last; ++i) {
        __unguarded_linear_insert(i, T(*i));
    }
}

template<typename RandomAccessIterator, typename T>
void __unguarded_linear_insert(RandomAccessIterator last, T value) {
    RandomAccessIterator next = last;
    --next;
    while (value < *next) {
        *last = *next;
        last = next;
        --next;
    }
    *last = value;
}
