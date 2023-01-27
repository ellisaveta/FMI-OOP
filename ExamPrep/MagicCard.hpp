#pragma once
#include "Card.hpp"
class MagicCard : virtual public Card
{
protected:
	std::string effect;
public:
	MagicCard() = default;
	MagicCard(const std::string&, const int, const int, const std::string&);
	void set_effect(const std::string&);
	std::string get_effect() const;
	void print() const override;
	~MagicCard() override {};
};

