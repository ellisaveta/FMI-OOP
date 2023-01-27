#pragma once
#include "Drink.hpp"
class VendingMachine
{
public:
	VendingMachine();
	VendingMachine(const VendingMachine& from);
	VendingMachine& operator=(const VendingMachine& from);
	~VendingMachine();

	bool add_drink(const Drink& to_add);
	int buy_drink(const char* drink_name, const double money);

	double get_income() const;
	int getNumberOfDrinks() const;
	const Drink* getDrinks() const;

private:
	Drink* drinks;
	double income;
	int howManyDrinks;
};

