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

#include "Duelist.hpp"
#include <fstream>
Duelist::Duelist(const std::string & n)
{
	this->name = n;
}

Duelist::Duelist(const std::string & n, const Deck & d)
{
	this->name = n;
	this->deck = d;
}

std::string Duelist::getName() const
{
	return this->name;
}

Deck & Duelist::getDeck()
{
	return this->deck;
}

void Duelist::setName(const std::string & n)
{
	this->name = n;
}

void Duelist::setDeck(const Deck & d)
{
	this->deck = d;
}

bool Duelist::saveDeck(const std::string filename) const
{
	std::ofstream fo(filename, std::ios::trunc);
	if (!fo.is_open())
	{
		std::cout << "Failed to open this file correctly!\n";
		return false;
	}
	fo << deck;
	fo.close();
	return true;
}

bool Duelist::loadDeck(const std::string filename)
{
	std::ifstream fi(filename, std::ios::in);
	if (!fi.is_open())
	{
		std::cout << "Failed to open this file correctly!\n";
		return false;
	}
	fi >> deck;
	fi.close();
	return true;
}

void Duelist::duel(Duelist & opponent)
{
	if (deck.getCardsCount() != opponent.getDeck().getCardsCount())
	{
		std::cout << "Not equal card count!\n";
		return;
	}
	this->deck.shuffle();
	opponent.getDeck().shuffle();
	int pointsForThis = 0;
	int pointsForOpponent = 0;
	for (int i = 0; i < deck.getCardsCount(); ++i)
	{
		if ((*(deck.getCards()[i])) > (*(opponent.getDeck().getCards()[i])))
		{
			if((*(deck.getCards()[i])).getRarity() != (*(opponent.getDeck().getCards()[i])).getRarity())
				pointsForThis++;
		}
		else if ((*(deck.getCards()[i])) < (*(opponent.getDeck().getCards()[i])))
		{
			if ((*(deck.getCards()[i])).getRarity() != (*(opponent.getDeck().getCards()[i])).getRarity())
				pointsForOpponent++;
		}
	}
	if (pointsForOpponent > pointsForThis)
	{
		std::cout << opponent.getName() << " wins the duel!\n";
		return;
	}
	if (pointsForOpponent < pointsForThis)
	{
		std::cout << this->name << " wins the duel!\n";
		return;
	}
	std::cout << "No winner! The duel ended in a draw!\n";
}
