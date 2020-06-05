#include "Point.h"


double Point::get_dist() const {
    return sqrt(m_x * m_x + m_y * m_y);
};

bool Point::operator<(const IComparable& other) const{
    return get_dist() < dynamic_cast<const Point&>(other).get_dist();
}

bool Point::operator>(const IComparable& other) const {
    return get_dist() > dynamic_cast<const Point&>(other).get_dist();
}