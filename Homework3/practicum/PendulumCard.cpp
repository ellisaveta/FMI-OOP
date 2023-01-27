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

#include "PendulumCard.hpp"

PendulumCard::PendulumCard() : Card(), MonsterCard(), MagicCard(), pendulumScale(0) {}

PendulumCard::PendulumCard(const std::string n, const std::string e, const int & a, const int & d, const unsigned int & p,
	const CardType & t) : Card(n, e), MonsterCard(n, e, a, d), MagicCard(n, e, t), pendulumScale(p)
{
	if (p < 1 || p > 13)
	{
		std::cout << "Invalid Pendulum scale!\n";
	}
}

PendulumCard::PendulumCard(const PendulumCard & card) : Card(card.getName(), card.getEffect()),
	MonsterCard(card.getName(), card.getEffect(), card.getAttackPoints(), card.getProtectPoints()), 
	MagicCard(card.getName(), card.getEffect(), card.getType()), pendulumScale(card.getPendulumScale()) {}

PendulumCard & PendulumCard::operator=(const PendulumCard & card)
{
	if (this != &card)
	{
		setName(card.getName());
		setEffect(card.getEffect());
		setAttackPoints(card.getAttackPoints());
		setProtectPoints(card.getProtectPoints());
		setType(card.getType());
		this->pendulumScale = card.getPendulumScale();
	}
	return *this;
}

int PendulumCard::getPendulumScale() const
{
	return this->pendulumScale;
}

void PendulumCard::setPendulumScale(const unsigned int & p)
{
	if (p < 1 || p > 13)
	{
		std::cout << "Invalid Pendulum scale!\n";
	}
	this->pendulumScale = p;
}

std::ostream & operator<<(std::ostream & o, const PendulumCard & card)
{
	o << card.getName() << '|' << card.getEffect() << '|' << card.getAttackPoints() << '|' << card.getProtectPoints()
		<< '|' << card.getPendulumScale() << '|';
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

std::istream & operator>>(std::istream & is, PendulumCard & card)
{
	std::string str;
	std::getline(is, str, '|');
	card.setName(str);
	std::getline(is, str, '|');
	card.setEffect(str);
	std::getline(is, str, '|');
	int points = 0;
	for (int i = 0; i < str.length(); ++i)
	{
		points *= 10;
		points += str[i] - '0';
	}
	card.setAttackPoints(points);
	std::getline(is, str, '|');
	points = 0;
	for (int i = 0; i < str.length(); ++i)
	{
		points *= 10;
		points += str[i] - '0';
	}
	card.setProtectPoints(points);
	std::getline(is, str, '|');
	points = 0;
	for (int i = 0; i < str.length(); ++i)
	{
		points *= 10;
		points += str[i] - '0';
	}
	if (points < 1 || points > 13)
	{
		std::cout << "Invalid Pendulum scale!\n";
	}
	card.setPendulumScale(points);
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
