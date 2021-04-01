#include <iostream>
#include <sstream>
#include <cstring>
#include "bottle.hpp"

// Конструктор
Bottle::Bottle(const int& a, const double& b) {
    this->setA(a);
    this->setB(b);
}

Bottle::~Bottle() {
}

// Реализация методов получения и задания внутренних полей класса
int Bottle::getA() const {
    return a_;
}
double Bottle::getB() const {
    return b_;
}
void Bottle::setA(int const & a) {
    a_ = a;
}
void Bottle::setB(double const & b) {
    if (b < 0 || b > 1) {
        std::cerr << "Incorrect percent number" << std::endl;
        exit(1);
    }

    b_ = b;
    return;
}

// Перегруженный оператор сложения бутылок
Bottle operator+(const Bottle& lhs, const Bottle& rhs) {
    return Bottle(
        lhs.getA() + rhs.getA(),
        (lhs.getA()*lhs.getB() + rhs.getA()*rhs.getB()) / (lhs.getA() + rhs.getA())
    );
}
// Перегруженный оператор вычитания бутылок
Bottle operator-(const Bottle& lhs, const Bottle& rhs) {
    return Bottle(
        lhs.getA() - rhs.getA(),
        (lhs.getA() * lhs.getB() - rhs.getA() *rhs.getB() ) / (lhs.getA() + rhs.getA())
    );
}
// Перегруженные операторы сравнения
bool operator<(const Bottle& lhs, const Bottle& rhs) {
    return (lhs.getA()*lhs.getB()) < (rhs.getA()*rhs.getB());
}
bool operator==(const Bottle& lhs, const Bottle& rhs) {
    return (lhs.getA() == rhs.getA()) && (lhs.getB() == rhs.getB());
}

// Перегруженный оператор вывода
std::ostream& operator<<(std::ostream& output, const Bottle& b) {
    output << "(" << b.getA() << "л., " << b.getB() * 100 << "%)";
    return output;
}

Bottle operator ""_b(const char* str, size_t size){
    std::stringstream ss(str);
    std::string a, b;
    ss >> a >> b;
    int A = 0;
    double B = 0;
    
    try {
        A = std::stoi(a);
        B = std::stod(b);
    }
    catch (std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
    return Bottle(A, B);
}