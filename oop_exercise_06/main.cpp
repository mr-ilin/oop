#include "rectangle.hpp"
#include "list.hpp"
#include "allocator.hpp"

auto print_help() -> void {
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

auto interactive_loop() -> void {
    std::string cmd;
    int idx;

    List< Rectangle<int>, allocators::stack_allocator<Rectangle<int>> > list;

    while (std::cin >> cmd) {
        if (cmd == "add") {
            std::cin >> idx;
            auto iter = list.begin();
            for (int i = 0; i < idx; ++i) {
                ++iter;
            }
            
            try {
                Rectangle<int> input_rec;
                std::cin >> input_rec;
                list.insert(iter, std::move(input_rec));
            } catch (std::exception& exp) {
                std::cerr << "ERROR: " <<exp.what() << std::endl;
                continue;
            }
        } else if (cmd == "del") {
            std::cin >> idx;
            auto iter = list.begin();
            for (int i = 0; i < idx; ++i) {
                ++iter;
            }
            
            try {
                list.erase(iter);
            } catch (std::exception& exp) {
                std::cerr << "ERROR: " <<exp.what() << std::endl;
                continue;
            }
        } else if (cmd == "print") {
            if (list.size() == 0) { 
                std::cout << "List is empty" << std::endl; 
            } 
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

auto main() -> void {
    try {
        print_help();
        interactive_loop();
    } catch (std::exception& exp) {
        std::cerr << "ERROR: " <<exp.what() << std::endl;
    }
    return 0;
}