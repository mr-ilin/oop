#pragma  once

#include <vector>

#include "figure.hpp"

struct Triangle : Figure {
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
    Triangle() = default;
    Triangle(std::istream& is);
    Triangle(std::ifstream& is);
};
