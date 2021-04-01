#include "rectangle.hpp"
#include "list.hpp"

void print_help() {
    std::cout 
    << "+---------------------------------+-------------------------------------------+\n"
    << "| add [idx] [vertex_1] [vertex_2] |              Добавляет фигуру             |\n"
    << "+---------------------------------+-------------------------------------------+\n"
    << "|           del [index]           |         Удаляет фигуру по индексу         |\n"
    << "+---------------------------------+-------------------------------------------+\n"
    << "|              print              |        Печатает фигуры из списка          |\n"
    << "+---------------------------------+-------------------------------------------+\n"
    << "|          less [value]           | Печатает кол-во фигур, с площадью < value |\n"
    << "+---------------------------------+-------------------------------------------+\n"
    << "|              help               |              Печать справки               |\n"
    << "+---------------------------------+-------------------------------------------+\n"
    << "|         <end of line>           |           Для завершения программы        |\n"
    << "+---------------------------------+-------------------------------------------+\n"
    << "|   Формат ввода координат: \"1 2\" для координаты (1, 2)                       |\n"
    << "+---------------------------------+-------------------------------------------+\n"
    << std::endl;
}

void interactive_loop() {
    std::string cmd;
    int idx;

    List<Rectangle<int>> list;

    while (std::cin >> cmd) {
        if (cmd == "add") {
            std::cin >> idx;
            List<Rectangle<int>>::ListIterator iter(list, idx);
            try {
                Rectangle<int> input_rec;
                std::cin >> input_rec;
                list.insert(iter, input_rec);
            } catch (std::exception& exp) {
                std::cerr << "ERROR: " <<exp.what() << std::endl;
                continue;
            }
        } else if (cmd == "del") {
            std::cin >> idx;
            List<Rectangle<int>>::ListIterator iter(list, idx);
            try {
                list.erase(iter);
            } catch (std::exception& exp) {
                std::cerr << "ERROR: " <<exp.what() << std::endl;
                continue;
            }
        } else if (cmd == "print") {
            if (list.empty()) { std::cout << "List is empty" << std::endl; } 
            else {
                std::for_each(list.begin(), list.end(), [](const Rectangle<int>& rec) { std::cout << rec << std::endl; });
            }
        } else if (cmd == "less") {
            double max_area;
            std::cin >> max_area;
            int res = std::count_if(list.begin(), list.end(), [&max_area](const Rectangle<int>& rec){ return rec.area() < max_area; });
            std::cout << "Total amount = " << res << std::endl;
        } else if (cmd == "help") {
            print_help();
        } else {
            std::cerr << "ERROR: Invalid commad" << std::endl;
        }   
    }
}

int main() {
    try {
        print_help();
        interactive_loop();
    } catch (std::exception& exp) {
        std::cerr << "ERROR: " <<exp.what() << std::endl;
    }
    return 0;
}