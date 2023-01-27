#include "Rational.h"
#include <iostream>
#include <numeric>

Rational::Rational()
{
	this->num = 0;
	this->denom = 1;
}
Rational::Rational(int n, int d)
{
	this->num = n;
	this->denom = d;
}
Rational::Rational(int n)
{
	this->num = n;
	this->denom = 1;
}
int Rational::getNum() const
{
	return this->num;
}
int Rational::getDenom() const
{
	return denom;
}

void Rational::print() const
{
	std::cout << num << '/' << denom;
}

double Rational::ConvertToDouble() const
{
	return (double)num/(double)denom;
}
void Rational::setNum(int n)
{
	this->num = n;
}
void Rational::setDenom(int n)
{
	this->denom = n;
}
void Rational::setValue(char* arr)
{
	int n = 0;
	int i = 0;
	for (i; arr[i] != '/'; ++i)
	{
		n *= 10;
		n += arr[i] - '0';
	}
	this->num = n;
	n = 0;
	++i;
	for (i; arr[i] != '\0'; ++i)
	{
		n *= 10;
		n += arr[i] - '0';
	}
	this->denom = n;
}

Rational Rational::Sum(Rational a, Rational b)
{
	Rational sum;
	int n = a.getNum()*b.getDenom() + a.getDenom()*b.getNum();
	sum.setNum(n);
	int d = a.getDenom()*b.getDenom();
	sum.setDenom(d);
	int nod = 0;
	while (d != 0)
	{
		nod = n % d;
		n = d;
		d = nod;
	}
	if (nod != 0)
	{
		sum.setNum(sum.getNum() / nod);
		sum.setDenom(sum.getDenom() / nod);
	}
	return sum;
}
