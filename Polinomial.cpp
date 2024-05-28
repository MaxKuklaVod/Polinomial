#include "Polinomial.h"
#include <iostream>
#include <vector>
using namespace std;

Polynomial::Polynomial(int degree, const vector<double>& coefficients)
{
	this->degree = degree;
	this->coefficients = coefficients;
}

double Polynomial::evaluate(double x) const
{
    double result = 0;
    for (int i = 0; i <= degree; i++) {
        result += coefficients[i] * pow(x,i);
    }
    return result;
}

Polynomial Polynomial::operator +(const Polynomial& other) const
{
    int maxDegree = max(degree, other.degree);
    vector<double> newCoefficients(maxDegree + 1, 0);

    for (int i = 0; i <= degree; i++) {
        newCoefficients[i] += coefficients[i];
    }
    for (int i = 0; i <= other.degree; i++) {
        newCoefficients[i] += other.coefficients[i];
    }

    return Polynomial(maxDegree, newCoefficients);
}

Polynomial Polynomial::operator -(const Polynomial& other) const
{
    int maxDegree = max(degree, other.degree);
    vector<double> newCoefficients(maxDegree + 1, 0);

    for (int i = 0; i <= degree; i++) {
        newCoefficients[i] += coefficients[i];
    }
    for (int i = 0; i <= other.degree; i++) {
        newCoefficients[i] -= other.coefficients[i];
    }

    return Polynomial(maxDegree, newCoefficients);
}

Polynomial Polynomial::operator *(const Polynomial& other) const
{
    int newDegree = degree + other.degree;
    vector<double> newCoefficients(newDegree + 1, 0);

    for (int i = 0; i <= degree; i++) {
        for (int j = 0; j <= other.degree; j++) {
            newCoefficients[i + j] += coefficients[i] * other.coefficients[j];
        }
    }

    return Polynomial(newDegree, newCoefficients);
}

Polynomial Polynomial::operator /(const Polynomial& other) const
{
    return Polynomial(other);
}

Polynomial Polynomial::derivative(int order) const
{
    if (order < 0) {
        throw invalid_argument("������� ����������� ������ ���� ��������������� ������.");
    }

    if (order == 0) {
        return *this; // ����������� �������� ������� - ��� ���������
    }

    int newDegree = degree;
    vector<double> Coefficients = coefficients;

    for (int j = 1; j <= order; j++) {
        newDegree -= 1;
        vector<double> newCoefficients(newDegree + 1, 0);

        for (int i = 1; i <= newDegree + 1; i++) {
            newCoefficients[i - 1] = Coefficients[i] * i;
        }
        Coefficients = newCoefficients;
    }

    return Polynomial(newDegree, Coefficients);
}

Polynomial Polynomial::integrate() const
{
    int newDegree = degree + 1;
    vector<double> newCoefficients(newDegree + 1, 0);

    for (int i = 0; i <= degree; i++) {
        newCoefficients[i + 1] = coefficients[i] / (i + 1);
    }

    return Polynomial(newDegree, newCoefficients);
}

ostream& operator<<(ostream& out, const Polynomial& polynomial)
{
    for (int i = polynomial.degree; i >= 0; i--) {
        if (polynomial.coefficients[i] != 0) {
            if (i == 1) {
                out << polynomial.coefficients[i] << "x";
            }
            else if (i > 1) {
                out << polynomial.coefficients[i] << "x^" << i;
            }
            else if (i == 0) {
                out << polynomial.coefficients[i];
            }
            if (i > 0) {
                out << " + ";
            }
        }
        
    }
    return out;
}