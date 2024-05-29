#pragma once
#include "Rational.h"
#include <iostream>
#include <vector>
using namespace std;

class Polynomial {
private:
    int degree; // Степень многочлена
    vector<Rational> coefficients; // Массив коэффициентов
public:
    // Конструктор
    Polynomial(int degree, vector<Rational>& coefficients);

    // Метод для вычисления значения многочлена для заданного аргумента
    Rational evaluate(Rational x) const;

    // Операция сложения
    Polynomial operator +(const Polynomial& other) const;

    // Операция вычитания
    Polynomial operator -(const Polynomial& other) const;

    // Операция умножения
    Polynomial operator *(Polynomial& other);

    // Операция деления (не придумал как это осуществить в программе)
    Polynomial operator /(const Polynomial& other) const;

    // Операция взятия производной
    Polynomial derivative(int order = 1) const;

    // Операция интегрирования
    Polynomial integrate();

    // Метод для вывода многочлена в стандартный поток вывода
    friend ostream& operator<<(ostream& out, Polynomial& polynomial);
};