//
//  main.cpp
//  oop_exercise_01
//
//  Created by Илья Ильин on 04.09.2020.
//  Copyright © 2020 Илья Ильин. All rights reserved.
//
//  Создать класс vector3D, задаваемый тройкой координат. Обязательно должны быть реализованы: операции сложения и вычитания векторов, векторное произведение векторов, скалярное произведение векторов, умножения на скаляр, сравнение векторов на совпадение, вычисление длины вектора, сравнение длины векторов, вычисление угла между векторами.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <stdlib.h>

class vector3D {
public:
    // Констуктор 
    vector3D(const double& x = 0, const double& y = 0, const double& z = 0) {
        x_ = x;
        y_ = y;
        z_ = z;
    }
    // Деструктор
    ~vector3D() {}
    
    // Методы получения и изменения атрибутов
    double x() const {
        return x_;
    }
    double& x() {
        return x_;
    }
    
    double y() const {
        return y_;
    }
    double& y() {
        return y_;
    }
    
    double z() const {
        return z_;
    }
    double& z() {
        return z_;
    }

    // Векторное произведение
    vector3D crossProduct(const vector3D& v) const {
        vector3D result;
        result.x_ = this->y_ * v.z_ - this->z_ * v.y_;
        result.y_ = this->z_ * v.x_ - this->x_ * v.z_;
        result.z_ = this->x_ * v.y_ - this->y_ * v.x_;
        return result;
    }

    // Длина вектора
    double length() const {
        return sqrt( (this->x_ * this->x_) + (this->y_ * this->y_) + (this->z_ * this->z_) );
    }

    // Угол между векторами
    double angleBetweenVectors(const vector3D& v) const{
        if ((v.length() == 0) || (this->length() ==0 )) {
            return 0;
        }
        const double halfC = 180/M_PI;
        double cos1 = ((this->x_ * v.x_) + (this->y_ * v.y_) + (this->z_ * v.z_ ) ) / (this->length() * v.length()) ;
        if (cos1 < -1) {
            return 180;
        }
        if (cos1 > 1) {
            return 0;
        }
        return halfC*acos(cos1);
    }

    // Сравнение векторов
    int compareToVector(const vector3D& v) const {
        double a = this->length();
        double b = v.length();

        if (a == b)
            return 0;
        else if (a > b)
            return 1;
        else 
            return -1;
    }

private:
    double x_, y_, z_;
};
// Перегруженные операции сложения и вычитания векторов
vector3D operator+(const vector3D& lhs, const vector3D& rhs) {
    return { lhs.x() + rhs.x(), lhs.y() + rhs.y(), lhs.z() + rhs.z() };
}
vector3D operator-(const vector3D& lhs, const vector3D& rhs) {
    return { lhs.x() - rhs.x(), lhs.y() - rhs.y(), lhs.z() - rhs.z() };
}
vector3D operator+=(vector3D& lhs, const vector3D& rhs) {
    lhs = lhs + rhs;
    return { lhs.x() + rhs.x(), lhs.y() + rhs.y(), lhs.z() + rhs.z() };
}
vector3D operator-=(vector3D& lhs, const vector3D& rhs) {
    lhs = lhs - rhs;
    return { lhs.x() - rhs.x(), lhs.y() - rhs.y(), lhs.z() - rhs.z() };
}

// Умножение вектора на число
vector3D operator*(double lhs, const vector3D& rhs) {
    return { lhs * rhs.x(), lhs * rhs.y(), lhs * rhs.z() };
}
vector3D operator*(const vector3D& rhs, double lhs) {
    return { lhs * rhs.x(), lhs * rhs.y(), lhs * rhs.z() };
}
vector3D operator *=(vector3D& lhs, double rhs) {
    lhs = lhs * rhs;
    return { lhs.x() * rhs, lhs.y() * rhs, lhs.z() * rhs };
}

// Скалярное произведение векторов как перегруженный оператор умножения
double operator*(const vector3D& lhs, const vector3D& rhs) {
    return lhs.x() * rhs.x() + lhs.y() * rhs.y() + rhs.z() * lhs.z();
}

// Ввод и вывод
std::ostream& operator<<(std::ostream& output, const vector3D& v) {
    output << "(" << v.x() << "," << v.y() << "," << v.z() << ")";
    return output;
}
std::istream& operator>>(std::istream& input, vector3D& v) {
    input >> v.x() >> v.y() >> v.z();
    return input;
}

bool read_args(vector3D& v1, vector3D& v2, double& number) {
    bool to_return = true;
    std::string x1, x2, y1, y2, z1, z2, c;
    std::cout << "Введите вектор a" << std::endl;
    std::cin >> x1 >> y1 >> z1;
    std::cout << "Введите вектор b" << std::endl;
    std::cin >> x2 >> y2 >> z2;
    std::cout << "Введите число с" << std::endl;
    std::cin >> c;

    try {
        v1.x() = std::stod(x1);
        v1.y() = std::stod(y1);
        v1.z() = std::stod(z1);

        v2.x() = std::stod(x2);
        v2.y() = std::stod(y2);
        v2.z() = std::stod(z2);

        number = std::stod(c);
    }
    catch (std::exception& ex) {
		std::cerr << ex.what() << std::endl;
        to_return = false;
	}
    return to_return;
}

int main(int argc, const char * argv[]) {
    vector3D a,b;
    double c;
    if (!read_args(a, b, c)) {
        std::cout << "Некорректный ввод" << std::endl;
        return 1;
    }
    
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a - b = " << (a - b) << std::endl;
    std::cout << "Скалярное пр-е = " << (a * b) << std::endl;
    std::cout << "Векторное пр-е = " << a.crossProduct(b) << std::endl;
    std::cout << "a * c = " << (a * c) << std::endl;
    std::cout << "b * c = " << (b * c) << std::endl;

    std::cout << "Длина а = " << a.length() << std::endl;
    std::cout << "Длина b = " << b.length() << std::endl;

    if (a.compareToVector(b) == 0) {
        std::cout << "Вектора равны" << std::endl;
    } else if (a.compareToVector(b) == 1) {
        std::cout << "Вектор а длинее вектора b" << std::endl;
    } else {
        std::cout << "Вектор b длинее вектора a" << std::endl;
    }
    
    std::cout << "Угол между a и b = " << a.angleBetweenVectors(b) << " градусов" << std::endl;

    return 0;
}
