#pragma once

#include <cstddef>
#include <ostream>

class Bottle {
public:
    Bottle(const int& a = 0, const double& b = 0);
    ~Bottle();
    int getA() const;
    double getB() const;
    void setA(int const & a);
    void setB(double const & b);

private:
    int a_; //Обьем в литрах
    double b_; // Процент заполнености, 0<=b_<=1
};

Bottle operator+(const Bottle& lhs, const Bottle& rhs);
Bottle operator-(const Bottle& lhs, const Bottle& rhs);
bool operator<(const Bottle& lhs, const Bottle& rhs);
bool operator==(const Bottle& lhs, const Bottle& rhs);
std::ostream& operator<<(std::ostream& output, const Bottle& b);
Bottle operator ""_b(const char* str, size_t size);
