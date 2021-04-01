#pragma once

#include <iostream>

struct Point {
    double x, y;
    Point (double  a,double b) { x = a; y = b;};
    Point() = default;
};

std::istream& operator >> (std::istream& is,Point& p );
std::ostream& operator << (std::ostream& os,const Point& p);
