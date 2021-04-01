//
//  figure.cpp
//  oop_exercise_03
//
//  Created by Илья Ильин on 16.10.2020.
//

#include <vector>
#include <iostream>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <cmath>

struct Point // Структура для хранения координат точек на плоскости
{
    double X = 0;
    double Y = 0;
};

inline std::ostream& operator<<(std::ostream& output, const Point& point)
{
    output << "(" << point.X << "," << point.Y << ")";
    return output;
}
inline std::istream& operator>>(std::istream& input, Point& point)
{
    std::string a, b;
    input >> a >> b;
    point.X = std::stod(a);
    point.Y = std::stod(b);
    return input;
}

class Figure
{
protected:
    Point _center; // Координаты центра многоугольника
    double _circumradius; // Радиус описанной вокруг многоугольника окр-ти
    std::vector<Point> _vertices;
public:
    Figure(const Point& center, const double& circumradius) : _center(center)
    {
        if (circumradius <= 0) {
            throw std::invalid_argument("Радиус не может быть <= 0");
        }
        _circumradius = circumradius;

        //std::cout << "<<<>>> It's Figure constuctor" << std::endl;
    }
    ~Figure()
    {
        _center.X = 0;
        _center.Y = 0;
        _circumradius = 0;
        _vertices.clear();

        //std::cout << "<<<>>> It's Figure destructor" << std::endl;
    }
    Point get_center() const
    {
        return _center;
    }

    double get_circumradius() const
    {
        return _circumradius;
    }
    void set_circumradius(const double& radius)
    {
        if (radius <= 0) {
            throw std::invalid_argument("Радиус не может быть <= 0");
        }
        _circumradius = radius;
        recount_vertices();
    }

    virtual double get_area() const = 0; // Метод получения площади фигуры
    virtual void recount_vertices() {} // Метод, подсчитывающий координаты вершин фигуры
    virtual void get_vertices(std::vector<Point> &vertices) const {} // Метод получения вектора координат вершин
};

class Triangle : public Figure
{
public:
    Triangle(const Point& center, const double& circumradius) : Figure(center, circumradius)
    {
        recount_vertices();
    }

    double get_area() const override
    {
        return (3 * _circumradius * _circumradius * sqrt(3)) / 4;
    }

    void recount_vertices() override
    {
        _vertices.clear();
        Point vertex;
        for (int i = 0; i < 3; ++i) {
            vertex.X = _center.X + _circumradius * cos( (M_2_PI * i) / 3 );
            vertex.Y = _center.Y + _circumradius * sin( (M_2_PI * i) / 3 );

            _vertices.push_back(vertex);
        }
    }

    void get_vertices(std::vector<Point> &vertices) const override
    {
        vertices = _vertices;
    }
};

class Octagon : public Figure
{
public:
    Octagon(const Point& center, const double& circumradius) : Figure(center, circumradius)
    {
        recount_vertices();
    }
    
    void recount_vertices() override
    {
        _vertices.clear();
        Point vertex;
        for (int i = 0; i < 8; ++i) {
            vertex.X = _center.X + _circumradius * cos( (M_2_PI * i) / 8 );
            vertex.Y = _center.Y + _circumradius * sin( (M_2_PI * i) / 8 );

            _vertices.push_back(vertex);
        }
    }

    void get_vertices(std::vector<Point> &vertices) const override
    {
        vertices = _vertices;
    }

    double get_area() const override
    {
        return _circumradius * _circumradius * ( 4 * sqrt(2) );
    }
};

class Hexagon : public Figure
{
public:
    Hexagon(const Point& center, const double& circumradius) : Figure(center, circumradius)
    {
        recount_vertices();
    }
    
    void recount_vertices() override
    {
        _vertices.clear();
        Point vertex;
        for (int i = 0; i < 6; ++i) {
            vertex.X = _center.X + _circumradius * cos( (M_2_PI * i) / 6 );
            vertex.Y = _center.Y + _circumradius * sin( (M_2_PI * i) / 6 );

            _vertices.push_back(vertex);
        }
    }

    void get_vertices(std::vector<Point> &vertices) const override
    {
        vertices = _vertices;
    }

    double get_area() const override
    {
        return _circumradius * _circumradius * ( ( 3 * sqrt(3) ) / 2 );
    }
};
