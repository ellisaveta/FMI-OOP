#include <iostream>
#include "Rational.h"
int main()
{
	Rational num(3, 4);
	num.print();
	std::cout << std::endl << num.ConvertToDouble();
	return 0;
}