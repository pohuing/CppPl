#include <chrono>
#include <iostream>
#include <algorithm>
#include "../lib/inherited/IComparable/Point.h"
#include "../lib/inherited/IComparable/IComparable.h"
#include "../lib/templated/sort.h"

#ifndef BENCHCOUNT
#define BENCHCOUNT 20
#endif

typedef std::pair<int, int> datatype;


std::pair<int, int> run_once(int count){
    std::vector<datatype> data;
    ComparableCollection collection;
    for (size_t i = 0; i < count; i++)
    {
        data.emplace_back(rand(), rand());
    }
    
    for(auto &a : data){
        collection.emplace_back(std::make_unique<Point>(a.first, a.second));
    }

    auto t1 = std::chrono::high_resolution_clock::now();
    collection.sort();
    auto d1 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - t1).count();

    auto t2 = std::chrono::high_resolution_clock::now();
        sort_it(data.begin(), data.end(),
            [](const datatype &a, const datatype &b) -> bool {
                return sqrt(a.first * a.first + a.second * a.second) <
                       sqrt(b.first * b.first + b.second * b.second);
            });
    auto d2 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - t2).count();

    std::cout << "Inherited took " << d1 << "µs\n";
    std::cout << "Templated took " << d2 << "µs\n";
    return {d1, d2};
}




int main(){
    int count = 10'000;
    std::vector<int> templated, inherited;
    for (size_t i = 0; i < BENCHCOUNT; i++)
    {
        auto a = run_once(count);
        inherited.push_back(a.first);
        templated.push_back(a.second);
    }
    sort_it(templated.begin(), templated.end());
    sort_it(inherited.begin(), inherited.end());
    std::cout << "Fastest five runs:\nTemplated \t| Inherited\n";
    auto least = BENCHCOUNT >= 5 ? 5 : BENCHCOUNT;
    for (size_t i = 0; i < BENCHCOUNT; i++)
    {
        std::cout << templated[i] << "µs\t" << inherited[i] << "µs\n";
    }
    
}

