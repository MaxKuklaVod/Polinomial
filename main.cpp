#include "Polinomial.h"
#include <iostream>
#include <vector>

int main() {

    setlocale(LC_ALL, "RU");

    vector<double> coeffs1 = { 1, -2, 3, 4 };
    Polynomial p1(3, coeffs1);

    vector<double> coeffs2 = { 2, 1, -1 };
    Polynomial p2(2, coeffs2);

    cout << "Многочлен p1: " << p1 << endl;
    cout << "Многочлен p2: " << p2 << endl;

    cout << "Значение p1 при x = 2: " << p1.evaluate(2) << endl;

    Polynomial p3 = p1 + p2;
    cout << "p1 + p2 = " << p3 << endl;

    Polynomial p4 = p1 - p2;
    cout << "p1 - p2 = " << p4 << endl;

    Polynomial p5 = p1 * p2;
    cout << "p1 * p2 = " << p5 << endl;

    Polynomial p6 = p1.derivative(2);
    cout << "Вторая производная p1 = " << p6 << endl;

    Polynomial p7 = p1.integrate();
    cout << "Интеграл p1 = " << p7 << "C" << endl;

    Polynomial p8 = p1 / p2;
    cout << "p1 / p2 = " << p8 << endl;

    return 0;
}

//Класс Polynomial:
//degree: Хранит степень многочлена.
//coefficients: Хранит массив коэффициентов, начиная с коэффициента при старшем члене.
//Конструктор: Инициализирует degree и coefficients.
//evaluate(x): Вычисляет значение многочлена для заданного аргумента x.
//Операторы перегрузки:
// +, -, *:  Перегруженные операторы для сложения, вычитания, умножения многочленов.
// << :  Перегруженный оператор для вывода многочлена в стандартный поток вывода.
// derivative(order): Вычисляет производную многочлена заданного порядка.
// integrate(): Вычисляет интеграл многочлена.