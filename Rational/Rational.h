#pragma once
class Rational
{
private:
	int num;
	int denom;
public:
	Rational();
	Rational(int n, int d);
	Rational(int);
	int getNum() const;
	int getDenom() const;
	void print() const;
	double ConvertToDouble() const;
	void setNum(int n);
	void setDenom(int n);
	void setValue(char* arr);
	Rational Sum(Rational a, Rational b);
};

