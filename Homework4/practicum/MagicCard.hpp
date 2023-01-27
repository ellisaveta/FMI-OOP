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

enum class CardType { none, TRAP, BUFF, SPELL };

class MagicCard : virtual public Card
{
	CardType type;

public:
	MagicCard();
	MagicCard(const std::string, const std::string, const unsigned int&, const CardType&);
	MagicCard(const MagicCard&);
	MagicCard& operator=(const MagicCard&);

	//getters:
	CardType getType() const;

	//setters:
	void setType(const CardType&);

	friend std::ostream& operator<<(std::ostream&, const MagicCard&);
	friend std::istream& operator>>(std::istream&, MagicCard&);
};


