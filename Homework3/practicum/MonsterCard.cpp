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

#include "MonsterCard.hpp"
#include <string.h>

MonsterCard::MonsterCard() : Card(), attackPoints(-1), protectPoints(-1) {}

MonsterCard::MonsterCard(const std::string Name, const std::string effect, const int& a, const int& p) :
	Card(Name, effect), attackPoints(a), protectPoints(p) {}

MonsterCard::MonsterCard(const MonsterCard & card) : 
	Card(card.getName(), card.getEffect()), attackPoints(card.getAttackPoints()), protectPoints(card.getProtectPoints()) {}

MonsterCard & MonsterCard::operator=(const MonsterCard & card)
{
	if (this != &card)
	{
		setName(card.getName());
		setEffect(card.getEffect());
		this->attackPoints = card.getAttackPoints();
		this->protectPoints = card.getProtectPoints();
	}
	return *this;
}

int MonsterCard::getAttackPoints() const
{
	return this->attackPoints;
}

int MonsterCard::getProtectPoints() const
{
	return this->protectPoints;
}

void MonsterCard::setAttackPoints(const int& a)
{
	this->attackPoints = a;
}

void MonsterCard::setProtectPoints(const int & p)
{
	this->protectPoints = p;
}

std::ostream & operator<<(std::ostream & o, const MonsterCard & card)
{
	o << card.getName() << '|' << card.getEffect() << '|' << card.getAttackPoints() << '|' << card.getProtectPoints() << '\n';
	return o;
}

std::istream & operator>>(std::istream & is, MonsterCard & card)
{
	std::string str;
	std::getline(is, str, '|');
	card.setName(str);
	std::getline(is, str, '|');
	card.setEffect(str);
	std::getline(is, str, '|');
	int points = 0;
	for (int i = 0; i < str.length(); ++i)
	{
		points *= 10;
		points += str[i] - '0';
	}
	card.setAttackPoints(points);
	std::getline(is, str);
	points = 0;
	for (int i = 0; i < str.length(); ++i)
	{
		points *= 10;
		points += str[i] - '0';
	}
	card.setProtectPoints(points);
	return is;
}
