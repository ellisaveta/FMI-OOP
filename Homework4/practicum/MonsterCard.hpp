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

#pragma once
#include <iostream>
#include <string>
#include "Card.hpp"
class MonsterCard : virtual public Card
{
	int attackPoints;
	int protectPoints;
public:
	MonsterCard();
	MonsterCard(const std::string, const std::string, const unsigned int&, const int&, const int&);
	MonsterCard(const MonsterCard&);
	//MonsterCard& operator=(const MonsterCard&);

	//getters:
	int getAttackPoints() const;
	int getProtectPoints() const;

	//setters:
	void setAttackPoints(const int&);
	void setProtectPoints(const int&);

	friend std::ostream& operator<<(std::ostream&, const MonsterCard&);
	friend std::istream& operator>>(std::istream&, MonsterCard&);
};

