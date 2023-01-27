#include "Deck.hpp"

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

void Deck::Copy(const Deck & other)
{
	cards.resize(other.cards.size());
	for (int i = 0; i < cards.size(); ++i)
	{
		cards[i] = other.cards[i];
	}
}

void Deck::Free()
{
	int size = cards.size();
	for (int i = 0; i < size; ++i)
	{
		cards[i]->~Card();
	}
}

Card * Deck::clone(Card * card)
{
	if (typeid(*card).hash_code() == typeid(Special).hash_code())
	{
		Special* sp = dynamic_cast<Special*>(card);
		return sp;
	}
	if (typeid(*card).hash_code() == typeid(HeroCard).hash_code())
	{
		HeroCard* her = dynamic_cast<HeroCard*>(card);
		return her;
	}
	MagicCard* mag = dynamic_cast<MagicCard*>(card);
	return mag;
}


Deck::Deck(const Deck & other)
{
	Copy(other);
}

Deck & Deck::operator=(const Deck & other)
{
	if (this != &other)
	{
		Free();
		Copy(other);
	}
	return *this;
}

std::vector<Card*> Deck::get_deck() const
{
	return cards;
}

void Deck::addCard(Card * card)
{
	cards.push_back(clone(card));
}

void Deck::print() const
{
	for (int i = 0; i < cards.size(); ++i)
	{
		if (typeid(*cards[i]).hash_code() == typeid(Special).hash_code())
		{
			Special* sp = dynamic_cast<Special*>(cards[i]);
			if(sp)
				sp->print();
		}
		else if (typeid(*cards[i]).hash_code() == typeid(HeroCard).hash_code())
		{
			HeroCard* her = dynamic_cast<HeroCard*>(cards[i]);
			if(her)
				her->print();
		}
		else
		{
			MagicCard* mag = dynamic_cast<MagicCard*>(cards[i]);
			if(mag)
				mag->print();
		}
	}
}

Deck::~Deck()
{
	Free();
}
