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
