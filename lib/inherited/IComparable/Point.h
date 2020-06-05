//
// Created by patri on 05.06.2020.
//

#ifndef CPPPL_POINT_H
#define CPPPL_POINT_H

#include "IComparable.h"
#include <cmath>


class Point : public IComparable{
public:
    Point(int x, int y) : m_x(x), m_y(y){}
    double get_dist() const;
    bool operator<(const IComparable& other) const override;
    bool operator>(const IComparable& other) const override;

private:
    int m_x, m_y;
};


#endif //CPPPL_POINT_H
