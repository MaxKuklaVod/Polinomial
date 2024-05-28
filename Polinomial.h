#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Polynomial {
private:
    int degree; // ������� ����������
    vector<double> coefficients; // ������ �������������
public:
    // �����������
    Polynomial(int degree, const vector<double>& coefficients);

    // ����� ��� ���������� �������� ���������� ��� ��������� ���������
    double evaluate(double x) const;

    // �������� ��������
    Polynomial operator +(const Polynomial& other) const;

    // �������� ���������
    Polynomial operator -(const Polynomial& other) const;

    // �������� ���������
    Polynomial operator *(const Polynomial& other) const;

    // �������� ������� (�� �������� ��� ��� ����������� � ���������)
    Polynomial operator /(const Polynomial& other) const;

    // �������� ������ �����������
    Polynomial derivative(int order = 1) const;

    // �������� ��������������
    Polynomial integrate() const;

    // ����� ��� ������ ���������� � ����������� ����� ������
    friend ostream& operator<<(ostream& out, const Polynomial& polynomial);
};