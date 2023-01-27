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
#include <vector>
#include "PendulumCard.hpp"
class Deck
{
	std::string name;
	std::vector<Card*> cards;

public:
	Deck(const std::string& = "");
	Deck(const Deck&);
	Deck& operator=(const Deck&);

	//getters:
	std::string getDeckName() const;
	std::vector<Card*> getCards() const;
	int getCardsCount() const;
	int getMonsterCardCount() const;
	int getMagicCardCount() const;
	int getPendulumCardCount() const;

	void addCard(Card*);

	//setters:
	void setDeckname(const std::string&);
	void setCard(const int&, Card*);

	void clearDeck();
	void shuffle();

	friend std::ostream& operator<<(std::ostream&, const Deck&);
	friend std::istream& operator>>(std::istream&, Deck&);
};

