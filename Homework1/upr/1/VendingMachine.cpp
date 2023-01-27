#include "VendingMachine.hpp"
#include<cstring>

VendingMachine::VendingMachine()
{
	this->howManyDrinks = 0;
	this->drinks = new Drink[0];
	this->income = 0.0;
}

VendingMachine::VendingMachine(const VendingMachine & from)
{
	this->howManyDrinks = from.getNumberOfDrinks();
	this->drinks = new Drink[howManyDrinks];
	for (int i = 0; i < howManyDrinks; ++i)
	{
		this->drinks[i] = from.getDrinks()[i];
	}
	this->income = from.get_income();
}

VendingMachine & VendingMachine::operator=(const VendingMachine & from)
{
	if (this != &from)
	{
		delete[] drinks;
		this->howManyDrinks = from.getNumberOfDrinks();
		this->drinks = new Drink[howManyDrinks];
		for (int i = 0; i < howManyDrinks; ++i)
		{
			this->drinks[i] = from.getDrinks()[i];
		}
		this->income = from.get_income();
	}
	return *this;
}

VendingMachine::~VendingMachine()
{
	delete[] drinks;
}

bool VendingMachine::add_drink(const Drink & to_add)
{
	for (int i = 0; i < this->howManyDrinks; ++i)
	{
		if (strcmp(this->drinks[i].get_name(), to_add.get_name())==0)
		{
			return false;
		}
	}
	this->howManyDrinks += 1;
	Drink* new_drinks = new Drink[this->howManyDrinks];
	for (int i = 0; i < howManyDrinks - 1; ++i)
	{
		new_drinks[i] = this->drinks[i];
	}
	new_drinks[howManyDrinks - 1] = to_add;
	delete[] drinks;
	drinks = new_drinks;
	return true;
}

int VendingMachine::buy_drink(const char * drink_name, const double money)
{
	for (int i = 0; i < this->howManyDrinks; ++i)
	{
		if (strcmp(this->drinks[i].get_name(), drink_name) == 0)
		{
			if (money >= this->drinks[i].get_price())
			{
				this->howManyDrinks -= 1;
				Drink* new_drinks = new Drink[this->howManyDrinks];
				int index = 0;
				for (index; index < i; ++index)
				{
					new_drinks[index] = this->drinks[index];
				}
				index++;
				for (int j=i; j<this->howManyDrinks && index < this->howManyDrinks + 1; ++index, ++j)
				{
					new_drinks[j] = this->drinks[index];
				}
				delete[] drinks;
				drinks = new_drinks;
				this->income += money;
				return 0;
			}
			this->income += money;
			return 1;
		}
	}
	return 2;
}

double VendingMachine::get_income() const
{
	return this->income;
}

int VendingMachine::getNumberOfDrinks() const
{
	return this->howManyDrinks;
}

const Drink * VendingMachine::getDrinks() const
{
	return this->drinks;
}
