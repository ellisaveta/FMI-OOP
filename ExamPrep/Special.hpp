#pragma once
#include "HeroCard.hpp"
#include "MagicCard.hpp"

class Special : public HeroCard, public MagicCard
{
	unsigned level;
public:
	Special() = default;
	Special(const std::string&, const int, const int, const int, const int, const std::string&, const unsigned);
	void set_level(const unsigned);
	unsigned get_level() const;
	void print() const override;
	~Special() override {};
};

