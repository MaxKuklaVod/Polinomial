#include <iostream>
#include "Rational.h"
using namespace std;

Rational::Rational() {
	this->numer = 0;
	this->denom = 1;
}
Rational::Rational(const int numer) {
	this->numer = numer;
	this->denom = 1;
}

Rational::Rational(const int numer, const int denom)
{
	this->numer = numer;
	this->denom = denom;
}

void Rational::satify(Rational& r)
{
	if (r.denom < 0)
	{
		r.numer = -r.numer;
		r.denom = -r.denom;
	}
	for (int i = 2; i <= abs(r.denom) && i <= abs(r.numer); i++)
		if (r.numer % i == 0 && r.denom % i == 0)
		{
			r.numer /= i;
			r.denom /= i;
			i--;
		}
}

Rational& Rational::operator=(const Rational& r)
{
	this->denom = r.denom;
	this->numer = r.numer;

	return *this;
}

Rational& Rational::operator+=(const Rational& r)
{
	this->numer = (r.numer * this->denom) + (this->numer * r.denom);
	this->denom = r.denom * this->denom;
	
	satify(*this);

	return *this;
}

Rational Rational::operator+(const Rational& r)
{
	Rational res(*this);
	return res += r;
}

Rational& Rational::operator*=(const Rational& r)
{
	this->numer *= r.numer;
	this->denom *= r.denom;
	satify(*this);

	return *this;
}

Rational Rational::operator*(const Rational& r)
{
	Rational res(*this);
	return res *= r;
}

Rational& Rational::operator/=(const Rational& r)
{
	this->numer *= r.denom;
	this->denom *= r.numer;
	satify(*this);

	return *this;
}

Rational Rational::operator/(const Rational& r)
{
	Rational res(*this);
	return res /= r;
}

Rational& Rational::operator-=(const Rational& r)
{
	this->numer = (this->numer * r.denom) - (r.numer * this->denom);
	this->denom = r.denom * this->denom;
	
	satify(*this);

	return *this;
}

Rational Rational::operator-(const Rational& r)
{
	Rational res(*this);
	return res -= r;
}

Rational Rational::operator++()
{
	this->numer += this->denom;
	satify(*this);
	return *this;
}

Rational& Rational::operator++(int)
{
	Rational r(*this);
	numer += denom;
	return r;
}

bool Rational::operator==(Rational& r)
{
	satify(r);
	return (this->numer == r.numer && this->denom == r.denom);
}

bool Rational::operator!=(Rational& r)
{
	return !(*this == r);
}

Rational::operator int()
{
	return this->numer / this->denom;
}

Rational::operator double()
{
	return ((double)this->numer) / this->denom;
}

istream& operator>>(istream& in, Rational& r)
{
	in >> r.numer >> r.denom;
	return in;
}

ostream& operator<<(ostream& out, const Rational& r)
{
	out << r.numer << "/" << r.denom;
	return out;

}
