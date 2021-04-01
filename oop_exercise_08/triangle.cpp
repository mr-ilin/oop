#include <cmath>

#include "triangle.hpp"
#include "point.hpp"

Point Triangle::Center() const {
    return _center;
}
void Triangle::Print(std::ostream& os) const {
    for (auto vertex : _vertexes) {
        os << vertex << " ";
    }
    os << std::endl;
}

void Triangle::WriteToFile(std::ofstream &of) const {
    for (auto vertex : _vertexes) {
        of << vertex << " ";
    }
    of << "\n";
}

double Triangle::Square() const {
    return (3 * _circumradius * _circumradius * sqrt(3)) / 4;
}

void Triangle::_recount_vertexes() {
    _vertexes.clear();
    Point vertex;
    for (int i = 0; i < 3; ++i) {
        vertex.x = _center.x + _circumradius * cos( (M_2_PI * i) / 3 );
        vertex.y = _center.y + _circumradius * sin( (M_2_PI * i) / 3 );

        _vertexes.push_back(vertex);
    }
}

Triangle::Triangle(std::istream& is) {
    is >> _center >> _circumradius;
    _recount_vertexes();
}

Triangle::Triangle(std::ifstream& is) {
    is >> _center >> _circumradius;
    _recount_vertexes();
}
