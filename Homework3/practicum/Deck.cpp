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

#include "Deck.hpp"

Deck::Deck(const std::string & n)
{
	this->name = n;
}

Deck::Deck(const std::string & n, const std::vector<MonsterCard>& mon, const std::vector<MagicCard>& mag,
	const std::vector<PendulumCard> pen)
{
	this->name = n;
	for (int i = 0; i < mon.size(); ++i)
	{
		this->monCards.push_back(mon[i]);
	}
	for (int i = 0; i < mag.size(); ++i)
	{
		this->magCards.push_back(mag[i]);
	}
	for (int i = 0; i < pen.size(); ++i)
	{
		this->penCards.push_back(pen[i]);
	}
}

Deck::Deck(const Deck & deck)
{
	this->name = deck.getDeckName();
	for (int i = 0; i < deck.getMonsterCards().size(); ++i)
	{
		this->monCards.push_back(deck.getMonsterCards()[i]);
	}
	for (int i = 0; i < deck.getMagicCards().size(); ++i)
	{
		this->magCards.push_back(deck.getMagicCards()[i]);
	}	
	for (int i = 0; i < deck.getPendulumCards().size(); ++i)
	{
		this->penCards.push_back(deck.getPendulumCards()[i]);
	}
}

Deck & Deck::operator=(const Deck & deck)
{
	if (this != &deck)
	{
		this->name = deck.getDeckName();
		this->monCards.clear();
		for (int i = 0; i < deck.getMonsterCards().size(); ++i)
		{
			this->monCards.push_back(deck.getMonsterCards()[i]);
		}
		this->magCards.clear();
		for (int i = 0; i < deck.getMagicCards().size(); ++i)
		{
			this->magCards.push_back(deck.getMagicCards()[i]);
		}
		this->penCards.clear();
		for (int i = 0; i < deck.getPendulumCards().size(); ++i)
		{
			this->penCards.push_back(deck.getPendulumCards()[i]);
		}
	}
	return *this;
}

std::string Deck::getDeckName() const
{
	return this->name;
}

std::vector<MonsterCard> Deck::getMonsterCards() const
{
	return this->monCards;
}

std::vector<MagicCard> Deck::getMagicCards() const
{
	return this->magCards;
}

std::vector<PendulumCard> Deck::getPendulumCards() const
{
	return this->penCards;
}

int Deck::getMonsterCardCount() const
{
	return this->monCards.size();
}

int Deck::getMagicCardCount() const
{
	return this->magCards.size();
}

int Deck::getPendulumCardCount() const
{
	return this->penCards.size();
}

void Deck::setDeckname(const std::string & n)
{
	this->name = n;
}

void Deck::setMonsterCard(const int & index, const MonsterCard & card)
{
	if (index > monCards.size())
	{
		std::cout << "Too big index! Can not set Monster card!\n";
		return;
	}
	if (index <= 0)
	{
		std::cout << "Too small index! Can not set Monster card!\n";
		return;
	}
	this->monCards[index - 1] = card;
}

void Deck::setMagicCard(const int & index, const MagicCard & card)
{
	if (index > magCards.size())
	{
		std::cout << "Too big index! Can not set Magic card!\n";
		return;
	}
	if (index <= 0)
	{
		std::cout << "Too small index! Can not set Magic card!\n";
		return;
	}
	this->magCards[index - 1] = card;
}

void Deck::setPendulumCard(const int & index, const PendulumCard & card)
{
	if (index > penCards.size())
	{
		std::cout << "Too big index! Can not set Pendulum card!\n";
		return;
	}
	if (index <= 0)
	{
		std::cout << "Too small index! Can not set Pendulum card!\n";
		return;
	}
	this->penCards[index - 1] = card;
}

void Deck::clearDeck()
{
	this->monCards.clear();
	this->magCards.clear();
	this->penCards.clear();
}

void Deck::addMonsterCard(const MonsterCard & toAdd)
{
	this->monCards.push_back(toAdd);
}

void Deck::addMagicCard(const MagicCard & toAdd)
{
	this->magCards.push_back(toAdd);
}

void Deck::addPendulumCard(const PendulumCard & toAdd)
{
	this->penCards.push_back(toAdd);
}

std::ostream & operator<<(std::ostream & o, const Deck & deck)
{
	o << deck.name << '|' << deck.getMonsterCardCount() << '|' << deck.getMagicCardCount() << '|'
		<< deck.getPendulumCardCount() << '\n';
	for (int i = 0; i < deck.getMonsterCardCount(); ++i)
	{
		o << deck.monCards[i];
	}
	for (int i = 0; i < deck.getMagicCardCount(); ++i)
	{
		o << deck.magCards[i];
	}
	for (int i = 0; i < deck.getPendulumCardCount(); ++i)
	{
		o << deck.penCards[i];
	}
	return o;
}

std::istream & operator>>(std::istream & is, Deck & deck)
{
	std::string str;
	std::getline(is, str, '|');
	deck.name = str;
	int monsterCards = 0;
	int magicCards = 0;
	int pendulumCards = 0;
	std::getline(is, str, '|');
	for (int i = 0; i < str.length(); ++i)
	{
		monsterCards *= 10;
		monsterCards += str[i] - '0';
	}
	std::getline(is, str, '|');
	for (int i = 0; i < str.length(); ++i)
	{
		magicCards *= 10;
		magicCards += str[i] - '0';
	}
	std::getline(is, str);
	for (int i = 0; i < str.length(); ++i)
	{
		pendulumCards *= 10;
		pendulumCards += str[i] - '0';
	}
	deck.clearDeck();
	for (int i = 0; i < monsterCards; ++i)
	{
		MonsterCard card;
		is >> card;
		deck.addMonsterCard(card);
	}
	for (int i = 0; i < magicCards; ++i)
	{
		MagicCard card;
		is >> card;
		deck.addMagicCard(card);
	}
	for (int i = 0; i < pendulumCards; ++i)
	{
		PendulumCard card;
		is >> card;
		deck.addPendulumCard(card);
	}
	return is;
}
