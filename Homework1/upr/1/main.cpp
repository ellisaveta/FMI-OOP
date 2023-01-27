#include <iostream>
#include "Drink.hpp"
#include "VendingMachine.hpp"

int main()
{
	Drink d1("Ert", 234, 0.5, 1.60);
	d1.set_name("Typ");
	Drink d2("Bhu", 765, 1.20, 2.30);
	Drink d3(d1);
	VendingMachine machine;
	machine.add_drink(d1);
	machine.add_drink(d2);
	machine.add_drink(d3);
	machine.buy_drink("Tyg", 1.00);
	machine.add_drink(d3);
	VendingMachine m2(machine);
	std::cout << m2.get_income() << std::endl;
	return 0;
}