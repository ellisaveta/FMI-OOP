#include "Special.hpp"
#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

Special::Special(const std::string & name, const int num, const int numIm, const int attack, const int protect, const std::string & effect, const unsigned level) :
	Card(name, num, numIm), HeroCard(name, num, numIm, attack, protect), MagicCard(name, num, numIm, effect), level(level) {}

void Special::set_level(const unsigned level)
{
	this->level = level;
}

unsigned Special::get_level() const
{
	return level;
}

void Special::print() const
{
	HeroCard::print();
	std::cout << "Effect: " << effect << std::endl;
	std::cout << "Level: " << level << std::endl;
}
