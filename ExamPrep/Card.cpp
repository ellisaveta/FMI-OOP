#include "Card.hpp"
#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

Card::Card(const std::string & name, const int num, const int numIm) : name(name), number(num), num_image(numIm)
{}

void Card::set_name(const std::string & name)
{
	this -> name = name;
}

void Card::set_num(const int num)
{
	number = num;
}

void Card::set_numIm(const int numIm)
{
	num_image = numIm;
}

std::string Card::get_name() const
{
	return name;
}

int Card::get_number() const
{
	return number;
}

int Card::get_num_image() const
{
	return num_image;
}

void Card::print() const
{
	std::cout << "Card name: " << name << std::endl;
	std::cout << "Card number: " << number << std::endl;
	std::cout << "Card image number: " << num_image << std::endl;
}