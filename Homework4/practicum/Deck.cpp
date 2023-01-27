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
#include <typeinfo>
#include <algorithm> 

Deck::Deck(const std::string & n)
{
	this->name = n;
}

Deck::Deck(const Deck & deck)
{
	this->name = deck.getDeckName();
	for (int i = 0; i < deck.getCardsCount(); ++i)
	{
		this->cards.push_back(deck.getCards()[i]);
	}
}

Deck & Deck::operator=(const Deck & deck)
{
	if (this != &deck)
	{
		this->name = deck.getDeckName();
		this->cards.clear();
		for (int i = 0; i < deck.getCardsCount(); ++i)
		{
			this->cards.push_back(deck.getCards()[i]);
		}
	}
	return *this;
}

std::string Deck::getDeckName() const
{
	return this->name;
}

std::vector<Card*> Deck::getCards() const
{
	return this->cards;
}

int Deck::getCardsCount() const
{
	return this->cards.size();
}

int Deck::getMonsterCardCount() const
{
	int monCount = 0;
	for (int i = 0; i < cards.size(); ++i)
	{
		PendulumCard* penPrt = dynamic_cast<PendulumCard*>(cards[i]);
		if (!penPrt)
		{
			MonsterCard* monPrt = dynamic_cast<MonsterCard*>(cards[i]);
			if (monPrt)
			{
				monCount++;
			}
		}
	}
	return monCount;
}

int Deck::getMagicCardCount() const
{
	int magCount = 0;
	for (int i = 0; i < cards.size(); ++i)
	{
		PendulumCard* penPrt = dynamic_cast<PendulumCard*>(cards[i]);
		if (!penPrt)
		{
			MagicCard* magPrt = dynamic_cast<MagicCard*>(cards[i]);
			if (magPrt)
			{
				magCount++;
			}
		}
	}
	return magCount;
}

int Deck::getPendulumCardCount() const
{
	int penCount = 0;
	for (int i = 0; i < cards.size(); ++i)
	{
		PendulumCard* penPrt = dynamic_cast<PendulumCard*>(cards[i]);
		if (penPrt)
		{
			penCount++;
		}
	}
	return penCount;
}

void Deck::setDeckname(const std::string & n)
{
	this->name = n;
}

void Deck::setCard(const int& index, Card* card)
{
	if (index >= cards.size())
	{
		std::cout << "Too big index! Can not set Monster card!\n";
		return;
	}
	if (index < 0)
	{
		std::cout << "Too small index! Can not set Monster card!\n";
		return;
	}
	if (typeid(*cards[index]).hash_code() != typeid(*card).hash_code())
	{
		std::cout << "Not matching types when setting card by index!\n";
		return;
	}
	PendulumCard* penPrt = dynamic_cast<PendulumCard*>(card);
	if (penPrt)
	{
		cards[index] = new PendulumCard(*penPrt);
		return;
	}
	MonsterCard* monPrt = dynamic_cast<MonsterCard*>(card);
	if (monPrt)
	{
		cards[index] = new MonsterCard(*monPrt);
		return;
	}
	MagicCard* magPrt = dynamic_cast<MagicCard*>(card);
	if (magPrt)
	{
		cards[index] = new MagicCard(*magPrt);
	}
}

void Deck::clearDeck()
{
	this->cards.clear();
}

void Deck::shuffle()
{
	std::random_shuffle(cards.begin(), cards.end());
}

void Deck::addCard(Card* toAdd)
{
	PendulumCard* penPrt = dynamic_cast<PendulumCard*>(toAdd);
	if (penPrt)
	{
		cards.push_back(new PendulumCard(*penPrt));
		return;
	}
	MonsterCard* monPrt = dynamic_cast<MonsterCard*>(toAdd);
	if (monPrt)
	{
		cards.push_back(new MonsterCard(*monPrt));
		return;
	}
	MagicCard* magPrt = dynamic_cast<MagicCard*>(toAdd);
	if (magPrt)
	{
		cards.push_back(new MagicCard(*magPrt));
	}
}


std::ostream & operator<<(std::ostream & o, const Deck & deck)
{
	int monCards = deck.getMonsterCardCount();
	int magCards = deck.getMagicCardCount();
	int penCards = deck.getPendulumCardCount();
	o << deck.name << '|' << deck.getCardsCount() << '|' << monCards << '|' << magCards << '|' << penCards << '\n';
	for (int i = 0; i < deck.getCardsCount(); ++i)
	{
		if (typeid(*deck.cards[i]).hash_code() == typeid(MonsterCard).hash_code())
		{
			o << *(dynamic_cast<MonsterCard*>(deck.cards[i]));
		}
	}
	for (int i = 0; i < deck.getCardsCount(); ++i)
	{
		if (typeid(*deck.cards[i]).hash_code() == typeid(MagicCard).hash_code())
		{
			o << *(dynamic_cast<MagicCard*>(deck.cards[i]));
		}
	}
	for (int i = 0; i < deck.getCardsCount(); ++i)
	{
		if (typeid(*deck.cards[i]).hash_code() == typeid(PendulumCard).hash_code())
		{
			o << *(dynamic_cast<PendulumCard*>(deck.cards[i]));
		}
	}
	return o;
}

std::istream & operator>>(std::istream & is, Deck & deck)
{
	std::string str;
	std::getline(is, str, '|');
	deck.name = str;
	int cardsCount = 0;
	int monsterCards = 0;
	int magicCards = 0;
	int pendulumCards = 0;
	std::getline(is, str, '|');
	for (int i = 0; i < str.length(); ++i)
	{
		cardsCount *= 10;
		cardsCount += str[i] - '0';
	}
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
		deck.addCard(&card);
	}
	for (int i = 0; i < magicCards; ++i)
	{
		MagicCard card;
		is >> card;
		deck.addCard(&card);
	}
	for (int i = 0; i < pendulumCards; ++i)
	{
		PendulumCard card;
		is >> card;
		deck.addCard(&card);
	}
	return is;
}
