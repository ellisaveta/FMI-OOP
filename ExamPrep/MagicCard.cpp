#include "MagicCard.hpp"
#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

MagicCard::MagicCard(const std::string & name, const int num, const int numIm, const std::string & eff) :
	Card(name, num, numIm), effect(eff) {}

void MagicCard::set_effect(const std::string & effect)
{
	this->effect = effect;
}

std::string MagicCard::get_effect() const
{
	return this->effect;
}

void MagicCard::print() const
{
	Card::print();
	std::cout << "Effect: " << effect << std::endl;
}
