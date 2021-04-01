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
    Point Center() const override ;
    void Print(std::ostream&) const  override ;
    void WriteToFile(std::ofstream&) const  override ;
    double Square() const override ;
    Octagon() = default;
    Octagon(std::istream& is);
    Octagon(std::ifstream& is);
};
