#include <iostream>
#include <vector>

#include "sorts.h"

int main() {
    const std::vector<int> test_data{1, 2, 3, 9, 8, 7, 6, 4, 5};

    std::vector<int> a(test_data.begin(), test_data.end());
    bubbleSort(a.begin(), a.end());
    for (auto i : a) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    std::vector<int> b(test_data.begin(), test_data.end());
    insertionSort(b.begin(), b.end());
    for (auto i : b) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    std::vector<int> c(test_data.begin(), test_data.end());
    selectionSort(c.begin(), c.end());
    for (auto i : c) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    std::vector<int> d(test_data.begin(), test_data.end());
    bubbleDownSort(d.begin(), d.end());
    for (auto i : d) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    std::vector<int> e(test_data.begin(), test_data.end());
    shellSort(e.begin(), e.end());
    for (auto i : e) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}