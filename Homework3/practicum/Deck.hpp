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
	std::vector<MonsterCard> monCards;
	std::vector<MagicCard> magCards;
	std::vector<PendulumCard> penCards;

public:
	Deck(const std::string& = "");
	Deck(const std::string&, const std::vector<MonsterCard>&, const std::vector<MagicCard>&, const std::vector<PendulumCard>);
	Deck(const Deck&);
	Deck& operator=(const Deck&);

	//getters:
	std::string getDeckName() const;
	std::vector<MonsterCard> getMonsterCards() const;
	std::vector<MagicCard> getMagicCards() const;
	std::vector<PendulumCard> getPendulumCards() const;
	int getMonsterCardCount() const;
	int getMagicCardCount() const;
	int getPendulumCardCount() const;

	void addMonsterCard(const MonsterCard&);
	void addMagicCard(const MagicCard&);
	void addPendulumCard(const PendulumCard&);

	//setters:
	void setDeckname(const std::string&);
	void setMonsterCard(const int&, const MonsterCard&);
	void setMagicCard(const int&, const MagicCard&);
	void setPendulumCard(const int&, const PendulumCard&);

	void clearDeck();

	friend std::ostream& operator<<(std::ostream&, const Deck&);
	friend std::istream& operator>>(std::istream&, Deck&);
};

