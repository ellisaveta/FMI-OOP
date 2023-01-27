/**
* Solution to homework assignment 2
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Elisaveta Georgieva
* @idnumber 62591
* @task 1
* @compiler VC
*/

#include "Money.hpp"
#include <iostream>
Money::Money(const int& g, const int& s)
{
	this->gold = g;
	this->silver = s;
	while (silver > 99)
	{
		++gold;
		silver -= 100;
	}
}

int Money::GetGold() const
{
	return this->gold;
}

int Money::GetSilver() const
{
	return this->silver;
}

void Money::SetGold(const int & g)
{
	this->gold = g;
}

void Money::SetSilver(const int & s)
{
	this->silver = s;
}

void Money::AddGold(const int & g)
{
	this->gold += g;
}

void Money::AddSilver(const int & s)
{
	this->silver += s;
	while (this->silver > 99)
	{
		this->gold++;
		this->silver -= 100;
	}
}

void Money::RemoveGold(const int & g)
{
	if (g > GetGold())
	{
		std::cout << "No enough gold!\n";
		return;
	}
	this->gold -= g;
}

void Money::RemoveSilver(const int & s)
{
	if (s % 100 > GetSilver())
	{
		std::cout << "No enough silver!\n";
		return;
	}
	this->gold -= s / 100;
	this->silver -= s % 100;
}

