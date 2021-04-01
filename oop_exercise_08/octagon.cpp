#include "octagon.hpp"

Point Octagon::Center() const {
    return _center;
}
void Octagon::Print(std::ostream& os) const {
    for (auto vertex : _vertexes) {
        os << vertex << " ";
    }
    os << std::endl;
}

void Octagon::WriteToFile(std::ofstream &of) const {
    for (auto vertex : _vertexes) {
        of << vertex << " ";
    }
    of << "\n";
}

double Octagon::Square() const {
    return _circumradius * _circumradius * ( 4 * sqrt(2) );
}

void Octagon::_recount_vertexes() {
    _vertexes.clear();
    Point vertex;
    for (int i = 0; i < 8; ++i) {
        vertex.x = _center.x + _circumradius * cos( (M_2_PI * i) / 8 );
        vertex.y = _center.y + _circumradius * sin( (M_2_PI * i) / 8 );

        _vertexes.push_back(vertex);
    }
}

Octagon::Octagon(std::istream& is) {
    is >> _center >> _circumradius;
    _recount_vertexes();
}

Octagon::Octagon(std::ifstream& is) {
    is >> _center >> _circumradius;
    _recount_vertexes();
}
