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
#include "Deck.hpp"
class Duelist
{
	char* name;
	Deck deck;

public:
	
	Duelist(const char* = "Anonimus");
	int getMagicCardCountInDeck() const;
	int getMonsterCardCountInDeck() const;
	void addMagicCardToDeck(const MagicCard&);
	void addMonsterCardToDeck(const MonsterCard&);
	void changeMagicCardInDeck(const int&, MagicCard&);
	void changeMonsterCardInDeck(const int&, MonsterCard&);
	~Duelist();
};

