// Copyright 2019 Ilya <ilia.bezverzhenko@mail.ru>

#include "header.h"

int main() {
    std::cout << "##########################" << std::endl;
    std::cout << "  ЛАБОРАТОРНАЯ РАБОТА №3." << std::endl;
    std::cout << "       (вариант №5)" << std::endl;
    std::cout << "##########################" << std::endl;
    std::cout << std::endl;

    double a = -2, b = 4;

    SimulatedAnnealing(a, b);

    SimulatedAnnealingMulti(a, b);

    return 0;
}
