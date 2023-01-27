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

#include "MagicCard.hpp"

MagicCard::MagicCard() : Card(), type(CardType::none) {}

MagicCard::MagicCard(const std::string name, const std::string effect, const CardType & type) : Card(name, effect), type(type) {}

MagicCard::MagicCard(const MagicCard & card) : Card(card.getName(), card.getEffect()), type(card.getType()) {}

MagicCard & MagicCard::operator=(const MagicCard & card)
{
	if (this != &card)
	{
		setName(card.getName());
		setEffect(card.getEffect());
		this->type = card.getType();
	}
	return *this;
}

CardType MagicCard::getType() const
{
	return this->type;
}

void MagicCard::setType(const CardType & T)
{
	this->type = T;
}

std::ostream & operator<<(std::ostream & o, const MagicCard & card)
{
	o << card.getName() << '|' << card.getEffect() << '|';
	switch (card.getType())
	{
	case CardType::TRAP:
		o << "TRAP";
		break;
	case CardType::BUFF:
		o << "BUFF";
		break;
	case CardType::SPELL:
		o << "SPELL";
		break;
	default:
		break;
	}
	o << '\n';
	return o;
}

std::istream & operator>>(std::istream & is, MagicCard & card)
{
	std::string str;
	std::getline(is, str, '|');
	card.setName(str);
	std::getline(is, str, '|');
	card.setEffect(str);
	std::getline(is, str);
	CardType type;
	if (str == "TRAP")
		card.setType(CardType::TRAP);
	else if (str == "BUFF")
		card.setType(CardType::BUFF);
	else if (str == "SPELL")
		card.setType(CardType::SPELL);
	else
		card.setType(CardType::none);
	return is;
}
