#pragma once
#include "Rational.h"
#include <iostream>
#include <vector>
using namespace std;

class Polynomial {
private:
    int degree; // ������� ����������
    vector<Rational> coefficients; // ������ �������������
public:
    // �����������
    Polynomial(int degree, vector<Rational>& coefficients);

    // ����� ��� ���������� �������� ���������� ��� ��������� ���������
    Rational evaluate(Rational x) const;

    // �������� ��������
    Polynomial operator +(const Polynomial& other) const;

    // �������� ���������
    Polynomial operator -(const Polynomial& other) const;

    // �������� ���������
    Polynomial operator *(Polynomial& other);

    // �������� ������� (�� �������� ��� ��� ����������� � ���������)
    Polynomial operator /(const Polynomial& other) const;

    // �������� ������ �����������
    Polynomial derivative(int order = 1) const;

    // �������� ��������������
    Polynomial integrate();

    // ����� ��� ������ ���������� � ����������� ����� ������
    friend ostream& operator<<(ostream& out, Polynomial& polynomial);
};