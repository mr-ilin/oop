#pragma once

#include <iostream>
#include <fstream>

#include "point.hpp"

class Figure {
public:
    virtual Point Center() const = 0;
    virtual void Print(std::ostream&) const = 0 ;
    virtual void WriteToFile(std::ofstream&) const = 0 ;
    virtual double Square() const = 0;
    virtual ~Figure() = default;
};
