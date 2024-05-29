#pragma once
#include <iostream>
using namespace std;

class Rational {
private:
	int numer, denom;
public:
	Rational();
	Rational(const int num);
	Rational(const int num, const int denom);
	void satify(Rational& r);
	int get_numer();
	Rational& operator =(const Rational& r);
	Rational& operator +=(const Rational& r);
	Rational operator +(const Rational& r);
	Rational& operator *=(const Rational& r);
	Rational operator *(const Rational& r);
	Rational& operator /=(const Rational& r);
	Rational operator /(const Rational& r);
	Rational& operator -=(const Rational& r);
	Rational operator -(const Rational& r);
	Rational powR(const int degree);
	Rational operator ++();
	Rational& operator ++(int);
	bool operator ==(Rational& r);
	bool operator !=(Rational& r);
	friend istream& operator >>(istream& in, Rational& r);
	friend ostream& operator <<(ostream& out, const Rational& r);
};