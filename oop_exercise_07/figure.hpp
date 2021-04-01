#pragma once

#include <iostream>
#include <fstream>

#include "point.hpp"

class Figure {
public:
    virtual Point center() const = 0;
    virtual void print(std::ostream&) const = 0 ;
    virtual void writeToFile(std::ofstream&) const = 0 ;
    virtual double square() const = 0;
    virtual ~Figure() = default;
};
