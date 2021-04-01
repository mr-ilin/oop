#include "hexagon.hpp"

Point Hexagon::Center() const {
    return _center;
}
void Hexagon::Print(std::ostream& os) const {
    for (auto vertex : _vertexes) {
        os << vertex << " ";
    }
    os << std::endl;
}

void Hexagon::WriteToFile(std::ofstream &of) const {
    for (auto vertex : _vertexes) {
        of << vertex << " ";
    }
    of << "\n";
}

double Hexagon::Square() const {
    return _circumradius * _circumradius * ((3 * sqrt(3)) / 2);
}

void Hexagon::_recount_vertexes() {
    _vertexes.clear();
    Point vertex;
    for (int i = 0; i < 6; ++i) {
        vertex.x = _center.x + _circumradius * cos( (M_2_PI * i) / 6 );
        vertex.y = _center.y + _circumradius * sin( (M_2_PI * i) / 6 );

        _vertexes.push_back(vertex);
    }
}

Hexagon::Hexagon(std::istream& is) {
    is >> _center >> _circumradius;
    _recount_vertexes();
}

Hexagon::Hexagon(std::ifstream& is) {
    is >> _center >> _circumradius;
    _recount_vertexes();
}
