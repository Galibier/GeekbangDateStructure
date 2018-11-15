#include <iostream>
#include <vector>
#include <algorithm>
#include "MergeSort.h"

int main() {
    const std::vector<int> test_data{0, -1, 3, 190, -500};

    std::vector<int> a{test_data};
    mergeSort(a.begin(), a.end());
    for (auto i : a) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    std::vector<int> b{test_data};
    inplaceMergeSort(b.begin(), b.end());
    for (auto i : b) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    return 0;
}
