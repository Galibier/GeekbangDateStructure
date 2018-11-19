#include <iostream>
#include <vector>

#include "BinarySearch.h"

template<typename VecT, typename T = typename VecT::value_type>
void test_bsearch(const VecT &test,
                  T target,
                  BinarySearchPolicy policy = BinarySearchPolicy::UNSPECIFIED) {
    auto it = binarySearch(test.begin(), test.end(), target, policy);
    std::cout << std::distance(test.begin(), it) << std::endl;
}

int main() {
    std::vector<int> test{0, 0, 1, 2, 3, 4, 4, 5, 5, 5, 5, 5, 6, 8};  // std::less<int>()

    test_bsearch(test, 8);                                   // 14
    test_bsearch(test, -1);                                  // 14
    test_bsearch(test, 0);                                   // 0, 1
    test_bsearch(test, 0, BinarySearchPolicy::FIRST);             // 0
    test_bsearch(test, 0, BinarySearchPolicy::LAST);              // 1
    test_bsearch(test, 4);                                   // 5, 6
    test_bsearch(test, 4, BinarySearchPolicy::FIRST);             // 5
    test_bsearch(test, 4, BinarySearchPolicy::LAST);              // 6
    test_bsearch(test, 5);                                   // 7, 8, 9, 10, 11
    test_bsearch(test, 5, BinarySearchPolicy::FIRST);             // 7
    test_bsearch(test, 5, BinarySearchPolicy::LAST);              // 11
    test_bsearch(test, 7, BinarySearchPolicy::FIRST_NOT_LESS);    // 13
    test_bsearch(test, 7, BinarySearchPolicy::LAST_NOT_GREATER);  // 12
    test_bsearch(test, 7, BinarySearchPolicy::FIRST);             // 14
    test_bsearch(test, 8);                                   // 13
    test_bsearch(test, 8, BinarySearchPolicy::FIRST);             // 13
    test_bsearch(test, 8, BinarySearchPolicy::LAST);              // 13

    return 0;
}
