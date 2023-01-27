#include "HeroCard.hpp"
#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

HeroCard::HeroCard(const std::string & name, const int num, const int numIm, const int attack, const int protect) :
	Card(name, num, numIm), attack_pow(attack), protect_pow(protect) {}

void HeroCard::set_attack_power(const int attack)
{
	attack_pow = attack;
}

void HeroCard::set_protect_power(const int protect)
{
	protect_pow = protect;
}

int HeroCard::get_attack_power() const
{
	return attack_pow;
}

int HeroCard::get_protect_power() const
{
	return protect_pow;
}

void HeroCard::print() const
{
	Card::print();
	std::cout << "Attack points: " << attack_pow << std::endl;
	std::cout << "Protect points: " << protect_pow << std::endl;
}
