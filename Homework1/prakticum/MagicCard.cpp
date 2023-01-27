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

#include "MagicCard.hpp"

MagicCard::MagicCard()
{
	this->name = nullptr;
	this->effect = nullptr;
	this->type = none;
}

MagicCard::MagicCard(const char * Name, const char * Effect, const Type& T)
{
	int size = strlen(Name);
	if (size > 25)
	{
		std::cout << "The name is over 25 symbols";
	}
	this->name = new char[size + 1];
	strcpy_s(name, size + 1, Name);
	size = strlen(Effect);
	if (size > 100)
	{
		std::cout << "The effect is over 100 symbols";
	}
	this->effect = new char[size + 1];
	strcpy_s(effect, size + 1, Effect);
	this->type = T;
}

MagicCard::MagicCard(const MagicCard & card)
{
	int length = strlen(card.getName());
	this->name = new char[length + 1];
	strcpy_s(this->name, length + 1, card.getName());
	length = strlen(card.getEffect());
	this->effect = new char[length + 1];
	strcpy_s(this->effect, length + 1, card.getEffect());
	this->type = card.getType();
}

MagicCard & MagicCard::operator=(const MagicCard & card)
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
	if (card.getEffect() == nullptr)
	{
		this->effect = nullptr;
	}
	else
	{
		int length = strlen(card.getEffect());
		this->effect = new char[length + 1];
		strcpy_s(this->effect, length + 1, card.getEffect());
	}
	this->type = card.getType();
	return *this;
}

char * MagicCard::getName() const
{
	return this->name;
}

char * MagicCard::getEffect() const
{
	return this->effect;
}

Type MagicCard::getType() const
{
	return this->type;
}

void MagicCard::setName(const char * Name)
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

void MagicCard::setEffect(const char * Effect)
{
	if (effect != nullptr)
	{
		delete[] effect;
	}
	int size = strlen(Effect);
	if (size > 100)
	{
		std::cout << "The effect is over 100 symbols";
	}
	this->effect = new char[size + 1];
	strcpy_s(effect, size + 1, Effect);
}

void MagicCard::setType(const Type & T)
{
	this->type = T;
}

MagicCard::~MagicCard()
{
	delete[] name;
	delete[] effect;
}
