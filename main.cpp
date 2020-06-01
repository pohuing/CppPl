#include <iostream>
#include <vector>
#include "lib/templated/sort.h"
#include <cmath>
#include <iostream>
#include <iterator>
#include <random>
#include <assert.h>

typedef std::pair<int, int> datatype;

void test_templated();

int main() {
    test_templated();
}

void test_templated() {
    auto data = std::vector<datatype>();
    data.emplace_back(0, 2);
    data.emplace_back(1, 2);
    data.emplace_back(-1, 2);
    data.emplace_back(3, 2);

    auto shuffled = data;

    std::shuffle(shuffled.begin(), shuffled.end(), std::mt19937(std::random_device()()));
    assert(!std::equal(data.begin(), data.end(), shuffled.begin(), shuffled.end()));

sort_it<datatype>(shuffled.begin(), shuffled.end(),
                                                   [](const datatype &a, const datatype &b) -> bool {
                                                       return sqrt(a.first * a.first + a.second * a.second) <
                                                              sqrt(b.first * b.first + b.second * b.second);
                                                   });

    assert(std::equal(data.begin(), data.end(), shuffled.begin(), shuffled.end()));
}
