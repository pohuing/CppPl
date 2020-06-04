#include <cmath>
#include <iostream>
#include "IComparable.h"

class Point : public IComparable{
public:
    Point(int x, int y) : m_x(x), m_y(y){}
    double get_dist() const{
        return sqrt(m_x * m_x + m_y * m_y);
    }
    bool operator<(const IComparable& other) const override {
        return get_dist() < dynamic_cast<const Point&>(other).get_dist();
    }
    bool operator>(const IComparable& other) const override {
        return get_dist() > dynamic_cast<const Point&>(other).get_dist();
    }

private:
    int m_x, m_y;
};


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