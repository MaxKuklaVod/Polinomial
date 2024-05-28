#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Polynomial {
private:
    int degree; // Степень многочлена
    vector<double> coefficients; // Массив коэффициентов
public:
    // Конструктор
    Polynomial(int degree, const vector<double>& coefficients);

    // Метод для вычисления значения многочлена для заданного аргумента
    double evaluate(double x) const;

    // Операция сложения
    Polynomial operator +(const Polynomial& other) const;

    // Операция вычитания
    Polynomial operator -(const Polynomial& other) const;

    // Операция умножения
    Polynomial operator *(const Polynomial& other) const;

    // Операция деления (не придумал как это осуществить в программе)
    Polynomial operator /(const Polynomial& other) const;

    // Операция взятия производной
    Polynomial derivative(int order = 1) const;

    // Операция интегрирования
    Polynomial integrate() const;

    // Метод для вывода многочлена в стандартный поток вывода
    friend ostream& operator<<(ostream& out, const Polynomial& polynomial);
};