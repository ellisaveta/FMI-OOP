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

#include "Duelist.hpp"

Duelist::Duelist(const char * Name)
{
	int size = strlen(Name);
	this->name = new char[size + 1];
	strcpy_s(this->name, size + 1, Name);
}

int Duelist::getMagicCardCountInDeck() const
{
	return this->deck.getMagicCardCount();
}

int Duelist::getMonsterCardCountInDeck() const
{
	return this->deck.getMonsterCardCount();
}

void Duelist::addMagicCardToDeck(const MagicCard & card)
{
	this->deck.addMagicCard(card);
}

void Duelist::addMonsterCardToDeck(const MonsterCard & card)
{
	this->deck.addMonsterCard(card);
}

void Duelist::changeMagicCardInDeck(const int & ind, MagicCard & card)
{
	this->deck.changeMagicCard(ind, card);
}

void Duelist::changeMonsterCardInDeck(const int & ind, MonsterCard & card)
{
	this->deck.changeMonsterCard(ind, card);
}

Duelist::~Duelist()
{
	delete[] name;
}
