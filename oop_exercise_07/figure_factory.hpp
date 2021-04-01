#pragma once

#include <memory>
#include <iostream>
#include <fstream>
#include <string>

#include "hexagon.hpp"
#include "octagon.hpp"
#include "triangle.hpp"

struct factory {
    std::shared_ptr<Figure> FigureCreate(std::istream& is);
    std::shared_ptr<Figure> FigureCreateFile(std::ifstream& is);
};
