//
//  main.cpp
//  oop_exercise_02
//
//  Created by Илья Ильин on 18.09.2020.
//  Copyright © 2020 Илья Ильин. All rights reserved.
//
//  Создать класс Bottle для работы с емкостями. Класс должен состоять из двух вещественных чисел: 
//  a- объем емкости в литрах и b – процент наполнения емкости (0 – пустая, 1 – полная). 
//  Реализовать операции сложения и вычитания, а также сравнения объектов класса бутылка в виде перегрузки операторов. 
//  При сложении должен складываться фактический объем заполнения бутылок. 
//  Необходимо реализовать пользовательский литерал для работы с константами типа Bottle.
//

#include "bottle.hpp"
#include <iostream>

bool ReadBottles(Bottle& bottle1, Bottle& bottle2) {
    std::string a1, a2, b1, b2;
    bool to_return = true;
    std::cout << "Введите первую бутылку" << std::endl;
    std::cin >> a1 >> b1;
    std::cout << "Введите вторую бутылку" << std::endl;
    std::cin >> a2 >> b2;
    try {
        bottle1.setA(std::stoi(a1));
        bottle2.setA(std::stoi(a2));

        bottle1.setB(std::stod(b1));
        bottle2.setB(std::stod(b2));
    }
    catch (std::exception& ex) {
        std::cerr << "Введены неправильные данные" << std::endl;
		std::cerr << ex.what() << std::endl;
        to_return = false;
	}
    return to_return;
}

int main(int argc, const char * argv[]) {
    Bottle bottle1, bottle2;
    if (!ReadBottles(bottle1, bottle2)) {
        return 1;
    }

    Bottle bottle3 = "1 1"_b; // Пользовательский литерал

    std::cout << "Сумма :" << bottle1 + bottle2 << std::endl;
    std::cout << "Разность :" << bottle1 - bottle2 << std::endl;
    if (bottle1 == bottle2) {
        std::cout << "Бутылки равны" << std::endl;
    } else if (bottle1.getA() * bottle1.getB() == bottle2.getA() * bottle2.getB()) {
        std::cout << "Бутылки равны по обьему" << std::endl;
    } else if (bottle1 < bottle2) {
        std::cout << "Первая бутылка меньше" << std::endl;
    } else {
        std::cout << "Вторая бутылка меньше" << std::endl;
    }

    std::cout << "\nОперации для константы 1л. 100% заполнености:" << std::endl;
    std::cout << bottle3 << std::endl;
    std::cout << "Сумма :" << bottle1 + bottle3 << std::endl;
    std::cout << "Разность :" << bottle1 - bottle3 << std::endl;
    if (bottle1 == bottle3) {
        std::cout << "Бутылки равны" << std::endl;
    } else if (bottle1 < bottle3) {
        std::cout << "Первая бутылка меньше" << std::endl;
    } else {
        std::cout << "Константная бутылка меньше" << std::endl;
    }

    return 0;
}
