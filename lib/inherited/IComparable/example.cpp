#include <iostream>
#include "IComparable.h"
#include "Point.h"


int main(){
    auto collection = ComparableCollection();
    collection.push_back(std::make_unique<Point>(1,1));
    collection.push_back(std::make_unique<Point>(0,0));
    std::cout << ((Point*)(collection[0].get()))->get_dist() << "\n";
    std::cout << ((Point*)(collection[1].get()))->get_dist() << "\n";
    collection.sort();
    std::cout << ((Point*)(collection[0].get()))->get_dist() << "\n";
    std::cout << ((Point*)(collection[1].get()))->get_dist() << "\n";
}