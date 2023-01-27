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
#include <iostream>
#include "Deck.hpp"
class Duelist
{
	std::string name;
	Deck deck;

public:
	Duelist(const std::string& = "");
	Duelist(const std::string&, const Deck&);

	//getters:
	std::string getName() const;
	Deck& getDeck();

	//setters:
	void setName(const std::string&);
	void setDeck(const Deck&);

	bool saveDeck(const std::string) const;
	bool loadDeck(const std::string);

	void duel(Duelist&);
};

