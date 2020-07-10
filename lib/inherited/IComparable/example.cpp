#include <iostream>
#include "IComparable.h"
#include "Point.h"
#include <cmath>

class Point3D : public Point{
public:
    Point3D(int x, int y, int z) 
        : Point(x,y), m_z(z){}
        
    double get_dist() const override{
        return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
    }

    std::string to_string() const override {
        return "(" + std::to_string(m_x) + " " + std::to_string(m_y) + " " + std::to_string(m_z) + ")";
    }

    int get_z() const {
        return m_z;
    }

private:
    int m_z;
};

void print_all(ComparableCollection& collection){
    for(auto& a : collection){
        std::cout << ((Point*)(a.get()))->get_dist() << " " << ((Point*)(a.get()))->to_string() << "\n";
    }
}

int main(){
    auto collection = ComparableCollection();
    collection.push_back(std::make_unique<Point>(1,1));
    collection.push_back(std::make_unique<Point>(0,0));
    print_all(collection);

    collection.sort();
    print_all(collection);

    collection.push_back(std::make_unique<Point3D>(0,0,1));
    collection.sort();
    print_all(collection);
}