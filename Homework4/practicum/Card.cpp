/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Elisaveta Georgieva
* @idnumber 62591
* @task 1
* @compiler VC
*/

#include "Card.hpp"
#include <string.h>
#include <iostream>


Card::Card(const std::string & Name, const std::string & Effect, const unsigned int& Rarity)
{
	name = Name;
	effect = Effect;
	rarity = Rarity;
}

Card::Card(const Card & card)
{
	this->name = card.getName();
	this->effect = card.getEffect();
	this->rarity = card.getRarity();
}

Card::~Card()
{
}

std::string Card::getName() const
{
	return this->name;
}

std::string Card::getEffect() const
{
	return this->effect;
}

unsigned int Card::getRarity() const
{
	return this->rarity;
}

void Card::setName(const std::string & n)
{
	this->name = n;
}

void Card::setEffect(const std::string & e)
{
	this->effect = e;
}

void Card::setRarity(const unsigned int & r)
{
	this->rarity = r;
}

bool Card::operator<(const Card & card) const
{
	return this->rarity < card.getRarity();
}

bool Card::operator>(const Card & card) const
{
	return this->rarity > card.getRarity();
}

