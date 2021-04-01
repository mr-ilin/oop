#include "figure_factory.hpp"

std::shared_ptr<Figure> factory::FigureCreate(std::istream &is) {
    std::string name;
    is >> name;
    if (name == "triangle") {
        return std::shared_ptr<Figure> ( new Triangle(is));
    } else if (name == "hexagon") {
        return std::shared_ptr<Figure> ( new Hexagon(is));
    } else if (name == "octagon") {
        return std::shared_ptr<Figure> ( new Octagon(is));
    } else {
        throw std::logic_error("Invalid figure\n");
    }
}

std::shared_ptr<Figure> factory::FigureCreateFile(std::ifstream &is) {
    std::string name;
    is >> name;
    if (name == "triangle") {
        return std::shared_ptr<Figure> ( new Triangle(is));
    } else if (name == "hexagon") {
        return std::shared_ptr<Figure> ( new Hexagon(is));
    } else if (name == "octagon") {
        return std::shared_ptr<Figure> ( new Octagon(is));
    } else {
        throw std::logic_error("Invalid figure\n");
    }
}
