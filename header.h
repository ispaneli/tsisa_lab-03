// Copyright 2019 Ilya <ilia.bezverzhenko@mail.ru>

#ifndef __LAB3_HEADER_H
#define __LAB3_HEADER_H

#include <iostream>
#include <cmath>
#include <iomanip>

const double T_max = 10000;
const double T_min = 0.01;

// Выдает значение функции в заданной точке.
double Function(const double& x) {
    return (double) - cos(0.5 * x) - 1;
}

// Выдает значение функции в заданной точке.
double multiFunction(const double& x) {
    return (double) (- cos(0.5 * x) - 1) * (sin(5 * x));
}

// Выдает случаный double на заданном отрезке.
double RAND(const double& min, const double& max) {
    double result = (double)rand() / RAND_MAX;
    return min + result * (max - min);
}

void SimulatedAnnealing(double begin, double end) {
    double Ti = T_max, X1 = RAND(begin, end);

    // Формируем таблицу.
    std::cout << std::fixed << std::setprecision(3) << std::right;
    std::cout << std::setw(3) << "N"
              << std::setw(6) << "Ti"
              << std::setw(7) << "X"
              << std::setw(10) << "F(x)"
              << std::setw(7) << "P"
              << std::setw(8) << "+/-"
              << std::endl;

    double P = 1;
    bool flag = false;
    // Цикл выполняет до достижения порога температуры.
    for(size_t i = 1; Ti > T_min; ++i) {
        // Случайная вторая точка и разность функций.
        double X2 = RAND(begin, end),
        delta_F = Function(X2) - Function(X1);

        if (delta_F <= 0) {
            X1 = X2;
            P = 1;
            flag = true;
        } else {
            // Вероятность выполнения итерация.
            P = std::exp(- delta_F / Ti);
            if (RAND(0, 1) <= P) {
                X1 = X2;
                flag = true;
            } else {
                flag = false;
            }
        }

        // Выводим значения в виде таблицы.
        std::cout << std::setw(3) << i << std::setw(7);
        if (Ti > 10)
            std::cout << (int) Ti;
        else
            std::cout << Ti;
        std::cout << std::setw(8) << X1
                  << std::setw(8) << Function((X1));
        if (P == 1) {
            std::cout << "      1   ";
        } else if (P < 0.000005) {
            std::cout << "     ~0   ";
        } else {
            std::cout << std::setprecision(5)
                      << std::setw(10) << P
                      << std::setprecision(3);
        }

        if (flag)
            std::cout << "   +" << std::endl;
        else
            std::cout << "   -" << std::endl;
        // Уменьшаем температуру в 0,95 раз.
        Ti *= 0.95;
        flag = false;
    }
}

void SimulatedAnnealingMulti(double begin, double end) {
    double Ti = T_max, X1 = RAND(begin, end);

    // Формируем таблицу.
    std::cout << std::fixed << std::setprecision(3) << std::right;
    std::cout << std::setw(3) << "N"
              << std::setw(6) << "Ti"
              << std::setw(7) << "X"
              << std::setw(10) << "F(x)"
              << std::setw(7) << "P"
              << std::setw(8) << "+/-"
              << std::endl;

    double P = 1;
    bool flag = false;
    // Цикл выполняет до достижения порога температуры.
    for(size_t i = 1; Ti > T_min; ++i) {
        // Случайная вторая точка и разность функций.
        double X2 = RAND(begin, end),
                delta_F = multiFunction(X2) - multiFunction(X1);

        if (delta_F <= 0) {
            X1 = X2;
            P = 1;
            flag = true;
        } else {
            // Вероятность выполнения итерация.
            P = std::exp(- delta_F / Ti);
            if (RAND(0, 1) <= P) {
                X1 = X2;
                flag = true;
            } else {
                flag = false;
            }
        }

        // Выводим значения в виде таблицы.
        std::cout << std::setw(3) << i << std::setw(7);
        if (Ti > 10)
            std::cout << (int) Ti;
        else
            std::cout << Ti;
        std::cout << std::setw(8) << X1
                  << std::setw(8) << multiFunction((X1));

        if (P == 1) {
            std::cout << "      1   ";
        } else if (P < 0.000005) {
            std::cout << "     ~0   ";
        } else {
            std::cout << std::setprecision(5)
                      << std::setw(10) << P
                      << std::setprecision(3);
        }
        if (flag)
            std::cout << "   +" << std::endl;
        else
            std::cout << "   -" << std::endl;

        // Уменьшаем температуру в 0,95 раз.
        Ti *= 0.95;
        flag = false;
    }
}

#endif //__LAB3_HEADER_H
