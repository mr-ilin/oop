#pragma once

#include <vector>

#include "figure.hpp"

struct Octagon : Figure{
private:
    Point _center;
    double _circumradius;
    std::vector<Point> _vertexes;
    
    void _recount_vertexes();
public:
    Point center() const override ;
    void print(std::ostream&) const  override ;
    void writeToFile(std::ofstream&) const  override ;
    double square() const override ;
    Octagon() = default;
    Octagon(std::istream& is);
    Octagon(std::ifstream& is);
};
