#include <vector>
#include "sort.h"
#include <cmath>
#include <random>
#include <cassert>

typedef std::pair<int, int> datatype;

void test_templated();

int main() {
    test_templated();
}

// A simple demonstration on how to use sort_it with a custom comparison function
void test_templated() {
    auto data = std::vector<datatype>();
    data.emplace_back(-0, 0);
    data.emplace_back(0, 2);
    data.emplace_back(1, 3);
    data.emplace_back(1, 4);
    data.emplace_back(-10, 0);
    data.emplace_back(10, 2);
    data.emplace_back(110, 2);

    auto shuffled = data;
    std::shuffle(shuffled.begin(), shuffled.end(), std::mt19937(std::random_device()()));

    sort_it(shuffled.begin(), shuffled.end(),
            [](const datatype &a, const datatype &b) -> bool {
                return sqrt(a.first * a.first + a.second * a.second) <
                       sqrt(b.first * b.first + b.second * b.second);
            });

    assert(std::equal(data.begin(), data.end(), shuffled.begin(), shuffled.end()));
}
