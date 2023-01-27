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

#include "Weapon.hpp"
#include <iostream>
#include <string>
Weapon::Weapon() : type(DefaulT), kind(KindWeapon::DefauLT), hitDamage(0, 0), weaponScore(0) {}

WeaponType Weapon::GetType() const
{
	return this->type;
}

KindWeapon Weapon::GetKind() const
{
	return this->kind;
}

double Weapon::GetHitDamageAvg() const
{
	return ((double)this->hitDamage.first+(double)this->hitDamage.second)/2.0;
}

void Weapon::CalScore()
{
	weaponScore = 0.0;
	weaponScore += GetHitDamageAvg();
	for (int i = 0; i < effects.size(); ++i)
	{
		weaponScore += effects[i].second;
	}
	if (GetType() == one_handed)
	{
		weaponScore *= 0.75;
	}
	else
	{
		weaponScore *= 1.5;
	}
}

void Weapon::DefineType()
{
	if (GetKind() == KindWeapon::dagger)
	{
		this->type = one_handed;
	}
	else if (GetKind() == KindWeapon::DefauLT)
	{
		this->type = DefaulT;
	}
	else
	{
		this->type = two_handed;
	}
}

double Weapon::GetScore() const
{
	return weaponScore;
}

void Weapon::SetKind(const KindWeapon & k)
{
	this->kind = k;
	DefineType();
	CalScore();
}

void Weapon::SetHitDamage(const int & min, const int & max)
{
	this->hitDamage.first = min;
	this->hitDamage.second = max;
}

void Weapon::ChangeType(const WeaponType & t)
{
	this->type = t;
	CalScore();
}

void Weapon::AddEffect(const std::string& name, const double& power)
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

void Weapon::RemoveEffectByIndex(const int & index)
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

void Weapon::ChangePowerOfEffect(const std::string & name_effect, const double& new_power)
{
	for (int i = 0; i < effects.size(); ++i)
	{
		if (effects[i].first == name_effect)
		{
			effects[i].second = new_power;
			CalScore();
			return;
		}
	}
	std::cout << "This effect does not exist";
}

bool Weapon::operator==(const Weapon& other) const
{
	return GetScore()==other.GetScore();
}

bool Weapon::operator!=(const Weapon& other) const
{
	return GetScore()!=other.GetScore();
}

Weapon & Weapon::operator=(const Weapon & other) 
{
	if (this != &other)
	{
		this -> effects.clear();
		for (int i = 0; i < other.effects.size(); ++i)
		{
			this->effects.push_back(other.effects[i]);
		}
		this->SetKind(other.GetKind());
		this->SetHitDamage(other.hitDamage.first, other.hitDamage.second);
	}
	return *this;
}

void Weapon::print() const
{
	std::cout << "Weapon kind: ";
	switch (GetKind())
	{
	case axe:
		std::cout << "axe\n";
		break;
	case sword:
		std::cout << "sword\n";
		break;
	case dagger:
		std::cout << "dagger\n";
		break;
	case mace:
		std::cout << "mace\n";
		break;
	case staff:
		std::cout << "staff\n";
		break;
	default:
		std::cout << "Default\n";
		break;
	}
	std::cout << "Weapon type: ";
	switch (GetType())
	{
	case one_handed:
		std::cout << "one_handed\n";
		break;
	case two_handed:
		std::cout << "two_handed\n";
		break;
	default:
		std::cout << "Default\n";
		break;
	}
	std::cout << "Weapon hit damage average: " << GetHitDamageAvg() << "\n";
	std::cout << "Weapon effects:\n";
	for (int i = 0; i < effects.size(); ++i)
	{
		std::cout << effects[i].first << " " << effects[i].second << "\n";
	}
	std::cout << "Weapon score: " << GetScore() << "\n";
}
