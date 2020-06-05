#include <iostream>
#include "IComparable.h"
#include "Point.h"


int main(){
    auto collection = ComparableCollection();
    std::vector<std::unique_ptr<IComparable>>& ref = collection.get_data_ref();
    ref.size();
    ref.push_back(std::make_unique<Point>(1,1));
    ref.push_back(std::make_unique<Point>(0,0));
    std::cout << ((Point*)(collection.get_data_ref()[0].get()))->get_dist() << "\n";
    std::cout << ((Point*)(collection.get_data_ref()[1].get()))->get_dist() << "\n";
    collection.sort();
    std::cout << ((Point*)(collection.get_data_ref()[0].get()))->get_dist() << "\n";
    std::cout << ((Point*)(collection.get_data_ref()[1].get()))->get_dist() << "\n";
}