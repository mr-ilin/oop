#include "point.hpp"

std::istream& operator >> (std::istream& is, Point& p) {
    return  is >> p.x >> p.y;
}

std::ostream& operator << (std::ostream& os,const Point& p) {
    return os << "(" << p.x << ", " << p.y << ")";
}
