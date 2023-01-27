/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Elisaveta Georgieva
* @idnumber 62591
* @task 2
* @compiler VC
*/

#include "MonsterCard.hpp"
#include <string.h>

MonsterCard::MonsterCard()
{
	this->name = nullptr;
	this->attackPoints = -1;
	this->protectPoints = -1;
}

MonsterCard::MonsterCard(const char * Name, const int& a, const int& p)
{
	int size = strlen(Name);
	if (size > 25)
	{
		std::cout << "The name is over 25 symbols";
	}
	this->name = new char[size+1];
	strcpy_s(name, size + 1, Name);
	this->attackPoints = a;
	this->protectPoints = p;
}

MonsterCard::MonsterCard(const MonsterCard & card)
{
	int length = strlen(card.getName());
	this->name = new char[length + 1];
	strcpy_s(this->name, length + 1, card.getName());
	this->attackPoints = card.getAttackPoints();
	this->protectPoints = card.getProtectPoints();
}

MonsterCard & MonsterCard::operator=(const MonsterCard & card)
{
	if (name != nullptr)
	{
		delete[] name;
	}
	if (card.getName() == nullptr)
	{
		this->name = nullptr;
	}
	else 
	{
		int length = strlen(card.getName());
		this->name = new char[length + 1];
		strcpy_s(this->name, length + 1, card.getName());
	}
	this->attackPoints = card.getAttackPoints();
	this->protectPoints = card.getProtectPoints();
	return *this;
}

char * MonsterCard::getName() const
{
	return this->name;
}

int MonsterCard::getAttackPoints() const
{
	return this->attackPoints;
}

int MonsterCard::getProtectPoints() const
{
	return this->protectPoints;
}

void MonsterCard::setName(const char* Name)
{
	if (name != nullptr)
	{
		delete[] name;
	}
	int size = strlen(Name);
	if (size > 25)
	{
		std::cout << "The name is over 25 symbols";
	}
	this->name = new char[size + 1];
	strcpy_s(name, size + 1, Name);
}

void MonsterCard::setAttackPoints(const int& a)
{
	this->attackPoints = a;
}

void MonsterCard::setProtectPoints(const int & p)
{
	this->protectPoints = p;
}

MonsterCard::~MonsterCard()
{
	delete[] name;
}
