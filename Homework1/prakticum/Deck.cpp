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

#include "Deck.hpp"

Deck::Deck()
{
	this->monCards = new MonsterCard[20];
	this->magCards = new MagicCard[20];
}

int Deck::getMagicCardCount() const
{
	int count = 0;
	for (int i=0; i<20; ++i)
	{
		if (this->magCards[i].getType() != none)
			++count;
	}
	return count;
}

int Deck::getMonsterCardCount() const
{
	int count = 0;
	for (int i = 0; i < 20; ++i)
	{
		if (this->monCards[i].getAttackPoints() != -1)
			++count;
	}
	return count;
}

void Deck::addMagicCard(const MagicCard& card)
{
	int emptyIndex = 0;
	for (emptyIndex; emptyIndex < 20 && magCards[emptyIndex].getType() != none; ++emptyIndex) {}
	if (emptyIndex == 20)
	{
		std::cout << "The deck is full";
		return;
	}
	magCards[emptyIndex] = card;
}

void Deck::addMonsterCard(const MonsterCard & card)
{
	int emptyIndex = 0;
	for (emptyIndex; emptyIndex < 20 && monCards[emptyIndex].getAttackPoints() != -1; ++emptyIndex) {}
	if (emptyIndex == 20)
	{
		std::cout << "The deck is full";
		return;
	}
	monCards[emptyIndex] = card;
}

void Deck::changeMagicCard(const int & index, MagicCard & card)
{
	this->magCards[index] = card;
}

void Deck::changeMonsterCard(const int & index, MonsterCard & card)
{
	this->monCards[index] = card;
}

Deck::~Deck()
{
	delete[] monCards;
	delete[] magCards;
}
