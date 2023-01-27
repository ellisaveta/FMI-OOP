/**
* Solution to homework assignment 2
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Elisaveta Georgieva
* @idnumber 62591
* @task 1
* @compiler VC
*/

#include "Materials.hpp"
#include <iostream>

Materials::Materials(const TypeMaterial & t, const int & q) : typeMaterial(t), quantity(q) {}

TypeMaterial Materials::GetType() const
{
	return this->typeMaterial;
}

int Materials::GetQuantity() const
{
	return this->quantity;
}

void Materials::SetType(const TypeMaterial & t)
{
	this->typeMaterial = t;
}

void Materials::SetQuantity(const int & q)
{
	this->quantity = q;
}

void Materials::print() const
{
	switch (GetType())
	{
	case TypeMaterial::cloth:
		std::cout << "cloth ";
		break;
	case TypeMaterial::essence:
		std::cout << "essence ";
		break;
	case TypeMaterial::herbs:
		std::cout << "herbs ";
		break;
	case TypeMaterial::ores:
		std::cout << "ores ";
		break;
	default:
		break;
	}
	std::cout << "- " << GetQuantity() << "\n";
}
