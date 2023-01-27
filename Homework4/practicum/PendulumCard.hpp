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
#include <string>
#include "MagicCard.hpp"
#include "MonsterCard.hpp"
class PendulumCard : public MagicCard, public MonsterCard
{
	unsigned int pendulumScale;

public:
	PendulumCard();
	PendulumCard(const std::string, const std::string, const unsigned int&, const int&, const int&, const unsigned int&, const CardType&);
	PendulumCard(const PendulumCard&);
	PendulumCard& operator=(const PendulumCard&);

	//getters:
	int getPendulumScale() const;

	//setters:
	void setPendulumScale(const unsigned int&);

	friend std::ostream& operator<<(std::ostream&, const PendulumCard&);
	friend std::istream& operator>>(std::istream&, PendulumCard&);
};


