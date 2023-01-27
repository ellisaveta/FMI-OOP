#pragma once
#include "Card.hpp"
class HeroCard : virtual public Card
{
protected:
	int attack_pow;
	int protect_pow;
public:
	HeroCard() = default;
	HeroCard(const std::string&, const int, const int, const int, const int);
	void set_attack_power(const int);
	void set_protect_power(const int);
	int get_attack_power() const;
	int get_protect_power() const;
	void print() const override;
	~HeroCard() override {}
};

