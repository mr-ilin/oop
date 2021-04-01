//
//  main.cpp
//  oop_exercise_03
//
//  Created by Илья Ильин on 16.10.2020.
//

/*
 Разработать классы согласно варианту задания, классы должны наследоваться от базового класса Figure. Фигуры являются фигурами вращения. Все классы должны поддерживать набор общих методов:
 1. Вычисление геометрического центра фигуры;
 2. Вывод в стандартный поток вывода std::cout координат вершин фигуры;
 3. Вычисление площади фигуры;
 Вариант 7:
 6-угольник, 8-угольник, треугольник
 */

#include "figure.cpp"

void print_info()
{
    std::cout << "+----------------------------+--------------------------------+" << std::endl;
    std::cout << "|add [type] [center] [radius]|        Добавляет фигуру        |" << std::endl;
    std::cout << "+----------------------------+--------------------------------+" << std::endl;
    std::cout << "|       delete [index]       |    Удаляет фигуру по индексу   | " << std::endl;
    std::cout << "+----------------------------+--------------------------------+" << std::endl;
    std::cout << "|            print           | Печатает информацию по фигурам | " << std::endl;
    std::cout << "+----------------------------+--------------------------------+" << std::endl;
    std::cout << "|            area            |      Печатает общую площадь    | " << std::endl;
    std::cout << "+----------------------------+--------------------------------+" << std::endl;
    std::cout << "| types: triangle, hexagon, octagon                           | " << std::endl;
    std::cout << "+-------------------------------------------------------------+" << std::endl;
    std::cout << "| example: add triangle 0 10 10                               | " << std::endl;
    std::cout << "+-------------------------------------------------------------+" << std::endl;
}

int main(int argc, const char * argv[])
{
    print_info();
    
    std::string cmd = "";
    std::vector<Figure*> figures;
    
    while (std::cin >> cmd)
    {
        try
        {
            if (cmd == "add")
            {
                std::string obj_type = "";
                std::cin >> obj_type;

                Point center;
                std::cin >> center;
                std::string str_radius = "";
                std::cin >> str_radius;
                double radius = std::stod(str_radius);

                if (obj_type == "triangle")
                {
                    Triangle* t_ptr = new Triangle(center, radius);
                    figures.push_back(t_ptr);
                }
                else
                if (obj_type == "hexagon")
                {
                    Hexagon* h_ptr = new Hexagon(center, radius);
                    figures.push_back(h_ptr);
                }
                else
                if (obj_type == "octagon")
                {
                    Octagon* o_ptr = new Octagon(center, radius);
                    figures.push_back(o_ptr);
                }
                else
                {
                    throw std::invalid_argument("Invalid object type");
                }
            }
            else
            if (cmd == "delete")
            {
                size_t idx = -1;
                std::cin >> idx;
                
                if (idx < 0 || idx >= figures.size())
                {
                    throw std::out_of_range("Invalid index");
                }
                
                figures.erase(figures.begin() + (idx - 1));
            }
            else
            if (cmd == "print")
            {
                for (auto figure : figures)
                {
                    std::vector<Point> vertices;
                    figure->get_vertices(vertices);
                    size_t n = vertices.size();
                    std::string obj_type = "";
                    switch (n) {
                        case 3:
                            obj_type = "triangle";
                            break;
                        case 6:
                            obj_type = "hexagon";
                            break;
                        case 8:
                            obj_type = "octagon";
                            break;
                        default:
                            obj_type = "unknown";
                            break;
                    }
                    std::cout << ">>> Type: " << obj_type << std::endl;
                    std::cout << "Center: " << figure->get_center() << std::endl;
                    std::cout << "Area: " << figure->get_area() << std::endl;
                    std::cout << "Vertices: " << std::endl;
                    
                    for (auto vertex : vertices)
                    {
                        std::cout << vertex << std::endl;
                    }
                }
            }
            else
            if (cmd == "area")
            {
                double summary = 0;
                for (auto figure : figures)
                {
                    summary += figure->get_area();
                }
                std::cout << "Summary area is " << summary << std::endl;
            }
            else
            {
                char c;
                while((c =getchar() != '\n')) { }
                
                throw std::invalid_argument("Invalid command");
            }
        }
        catch (std::exception& ex)
        {
            std::cout << ex.what() << std::endl;
        }
    }
    
    return 0;
}
