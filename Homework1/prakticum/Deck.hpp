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

#pragma once
#include "MonsterCard.hpp"
#include "MagicCard.hpp"
class Deck
{
	MonsterCard* monCards;
	MagicCard* magCards;

public:
	Deck();

	int getMagicCardCount() const;
	int getMonsterCardCount() const;
	void addMagicCard(const MagicCard&);
	void addMonsterCard(const MonsterCard&);
	void changeMagicCard(const int&, MagicCard&);
	void changeMonsterCard(const int&, MonsterCard&);

	~Deck();
};

