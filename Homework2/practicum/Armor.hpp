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

enum Type{ cloth, leather, mail, Default };

class Armor
{
	Type type;
	int defense;
	std::vector <std::pair <std::string, double>> effects;
	double gearScore;

	void CalScore();
public:
	Armor();
	int GetDefense() const;
	Type GetType() const;
	double GetScore() const;
	void SetType(const Type&);
	void SetDefense(const int&);
	void AddEffect(const std::string&, const double&);
	void RemoveEffectByIndex(const int&);
	bool operator==(const Armor&) const;
	bool operator!=(const Armor&) const;
	Armor& operator=(const Armor&);
	void print() const;
};

