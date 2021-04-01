#include <iostream>
#include "editor.hpp"

void help() {
    std::cout << "+----------------------------+-----------------------------------+" << std::endl;
    std::cout << "|        create [name]       |       Создает новый документ      |" << std::endl;
    std::cout << "+----------------------------+-----------------------------------+" << std::endl;
    std::cout << "|         load [name]        |         Загружает документ        |" << std::endl;
    std::cout << "+----------------------------+-----------------------------------+" << std::endl;
    std::cout << "|         save [name]        |         Сохраняет документ        |" << std::endl;
    std::cout << "+----------------------------+-----------------------------------+" << std::endl;
    std::cout << "|add [type] [center] [radius]|          Добавляет фигуру         |" << std::endl;
    std::cout << "+----------------------------+-----------------------------------+" << std::endl;
    std::cout << "|       delete [index]       |      Удаляет фигуру по индексу    | " << std::endl;
    std::cout << "+----------------------------+-----------------------------------+" << std::endl;
    std::cout << "|            print           |   Печатает информацию по фигурам  | " << std::endl;
    std::cout << "+----------------------------+-----------------------------------+" << std::endl;
    std::cout << "|            undo            | Отмена последнего вып-го действия | " << std::endl;
    std::cout << "+----------------------------+-----------------------------------+" << std::endl;
    std::cout << "|            exit            |    Завершение работы программы    | " << std::endl;
    std::cout << "+----------------------------+-----------------------------------+" << std::endl;
    std::cout << "| types: triangle, hexagon, octagon                              | " << std::endl;
    std::cout << "+----------------------------------------------------------------+" << std::endl;
    std::cout << "| example: add triangle 0 10 10                                  | " << std::endl;
    std::cout << "+----------------------------------------------------------------+" << std::endl;
}

void create(editor& edit) {
    std::string tmp;
    std::cout << "Enter name of new document\n";
    std::cin >> tmp;
    edit.CreateDocument(tmp);
    std::cout << "Document created!\n";
}

void load(editor& edit) {
    std::string tmp;
    std::cout << "Enter path to the file\n";
    std::cin >> tmp;
    try {
        edit.LoadDocument(tmp);
        std::cout << "Document loaded\n";

    } catch (std::runtime_error& e) {
        std::cout << e.what();
    }
}

void save(editor& edit) {
    std::string tmp;
    try {
        edit.SaveDocument();
        std::cout << "save document\n";
    } catch (std::runtime_error& e) {
        std::cout << e.what();
    }
}

void add(editor& edit) {
    factory fac;
    try {
        std::shared_ptr<Figure> newElem = fac.FigureCreate(std::cin);
        edit.InsertInDocument(newElem);
    } catch (std::logic_error& e) {
        std::cout << e.what() << '\n';
    }
    std::cout << "Ok\n";
}

void remove(editor& edit) {
    uint32_t index;
    std::cout << "Enter index\n";
    std::cin >> index;
    try {
        edit.DeleteInDocument(index);
        std::cout << "Ok\n";
    } catch (std::logic_error& err) {
        std::cout << err.what() << "\n";
    }
}

int main() {
    editor edit;
    std::string command;
    while (true) {
        std::cin >> command;
        if (command == "help") {
            help();
        } else if (command == "create") {
            create(edit);
        } else if (command == "load") {
            load(edit);
        } else if (command == "save") {
            save(edit);
        } else if (command == "exit") {
            break;
        } else if (command == "add") {
            add(edit);
        } else if (command == "delete") {
            remove(edit);
        } else if (command == "print") {
            edit.PrintDocument();
        } else if (command == "undo") {
            try {
                edit.Undo();
            } catch (std::logic_error& e) {
                std::cout << e.what();
            }
        } else {
            std::cout << "Unknown command\n";
        }
    }
    return 0;
}
