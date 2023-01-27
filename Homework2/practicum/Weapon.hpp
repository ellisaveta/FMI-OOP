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

#pragma once

#include <utility>
#include <string>
#include <vector>

enum WeaponType { one_handed, two_handed, DefaulT};
enum KindWeapon{ axe, sword, dagger, mace, staff, DefauLT};

class Weapon
{
	WeaponType type;
	KindWeapon kind;
	std::pair<int, int> hitDamage;
	std::vector <std::pair <std::string, double>> effects;
	double weaponScore;

	void CalScore();
	void DefineType();
public:
	Weapon();
	WeaponType GetType() const;
	KindWeapon GetKind() const;
	double GetHitDamageAvg() const;
	double GetScore() const;
	void SetKind(const KindWeapon&);
	void SetHitDamage(const int&, const int&);
	void ChangeType(const WeaponType&);
	void AddEffect(const std::string&, const double&);
	void RemoveEffectByIndex(const int&);
	void ChangePowerOfEffect(const std::string&, const double&);
	bool operator==(const Weapon&) const;
	bool operator!=(const Weapon&) const;
	Weapon& operator=(const Weapon&);
	void print() const;
};

