#pragma once
#include "Card.hpp"
#include "HeroCard.hpp"
#include "MagicCard.hpp"
#include "Special.hpp"
#include <vector>
class Deck
{
	std::vector<Card*> cards;
	void Copy(const Deck&);
	void Free();
	Card* clone(Card*);
	
public:
	Deck() = default;
	Deck(const Deck&);
	Deck& operator=(const Deck&);
	std::vector<Card*> get_deck() const;
	void addCard(Card*);
	void print() const;
	~Deck();
};

