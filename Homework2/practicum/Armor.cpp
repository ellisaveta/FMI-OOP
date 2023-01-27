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

#include "Armor.hpp"
#include <iostream>
Armor::Armor() : type(Default), defense(0), gearScore(0.0) {}

int Armor::GetDefense() const
{
	return defense;
}

Type Armor::GetType() const
{
	return this->type;
}

double Armor::GetScore() const
{
	return gearScore;
}

void Armor::SetType(const Type & t)
{
	this->type = t;
}

void Armor::SetDefense(const int & d)
{
	this->defense = d;
}

void Armor::AddEffect(const std::string& name, const double& power)
{
	std::pair<std::string, double> new_ef(name, power);
	for (int i = 0; i < effects.size(); ++i)
	{
		if (effects[i].first == new_ef.first)
		{
			effects[i].second = new_ef.second;
			CalScore();
			return;
		}
	}
	effects.push_back(new_ef);
	CalScore();
}

void Armor::RemoveEffectByIndex(const int & index)
{
	if (index >= effects.size())
	{
		std::cout << "Index is too big! Nothing there!\n";
		return;
	}
	std::vector<std::pair <std::string, double>> temp;
	for (int i = 0; i < index; ++i)
	{
		temp.push_back(effects[i]);
	}
	for (int i = index + 1; i < this->effects.size(); ++i)
	{
		temp.push_back(effects[i]);
	}
	this->effects.clear();
	for (int i = 0; i < temp.size(); ++i)
	{
		this->effects.push_back(temp[i]);
	}
	CalScore();
}

void Armor::CalScore()
{
	gearScore = 0.0;
	for (int i = 0; i < effects.size(); ++i)
	{
		gearScore += effects[i].second;
	}
}

bool Armor::operator==(const Armor & other) const
{
	return GetScore()==other.GetScore();
}

bool Armor::operator!=(const Armor & other) const
{
	return GetScore()!=other.GetScore();
}

Armor & Armor::operator=(const Armor & other)
{
	if (this != &other)
	{
		effects.clear();
		for (int i = 0; i < other.effects.size(); ++i)
		{
			this->effects.push_back(other.effects[i]);
		}
		SetType(other.GetType());
		SetDefense(other.GetDefense());
	}
	return *this;
}

void Armor::print() const
{
	std::cout << "Armor type: ";
	switch (GetType())
	{
	case cloth:
		std::cout << "cloth\n";
		break;
	case leather:
		std::cout << "leather\n";
		break;
	case mail:
		std::cout << "mail\n";
		break;
	default:
		std::cout << "Default\n";
		break;
	}
	std::cout << "Armor defence: " << GetDefense() << "\n";
	std::cout << "Armor effects:\n";
	for (int i = 0; i < effects.size(); ++i)
	{
		std::cout << effects[i].first << " " << effects[i].second << "\n";
	}
	std::cout << "Armor score: " << GetScore() << "\n";
}
