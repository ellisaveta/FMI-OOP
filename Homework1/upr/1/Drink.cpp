#include "Drink.hpp"
#include <cstring>

Drink::Drink(const char * init_name, const int init_calories, const double & init_quantity, const double & init_price) : 
	calories(init_calories), quantity(init_quantity), price(init_price)
{
	int size = 0;
	size = strlen(init_name);
	this->name = new char[size + 1];
	strcpy_s(name, size + 1, init_name);
}

Drink::Drink(const Drink & cpyFrom)
{
	int size = 0;
	size = strlen(cpyFrom.get_name());
	this->name = new char[size + 1];
	strcpy_s(name, size + 1, cpyFrom.get_name());
	this->calories = cpyFrom.get_calories();
	this->quantity = cpyFrom.get_quantity();
	this->price = cpyFrom.get_price();
}

Drink::Drink()
{
	this->name = nullptr;
	this->calories = 0;
	this->quantity = 0.0;
	this->price = 0.0;
}

Drink & Drink::operator=(const Drink & drink)
{
	if (this != &drink)
	{
		delete[] name;
		int size = 0;
		size = strlen(drink.get_name());
		this->name = new char[size + 1];
		strcpy_s(name, size + 1, drink.get_name());
		this->calories = drink.get_calories();
		this->quantity = drink.get_quantity();
		this->price = drink.get_price();
	}
	return *this;
}

Drink::~Drink()
{
	delete[] name;
}

const char * Drink::get_name() const
{
	return this->name;
}

int Drink::get_calories() const
{
	return this->calories;
}

double Drink::get_quantity() const
{
	return this->quantity;
}

double Drink::get_price() const
{
	return this->price;
}

void Drink::set_name(const char * new_name)
{
	if (this->name != nullptr)
	{
		delete[] name;
	}
	int size = 0;
	size = strlen(new_name);
	this->name = new char[size + 1];
	strcpy_s(name, size + 1, new_name);
}
