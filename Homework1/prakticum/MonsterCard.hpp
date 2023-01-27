/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Elisaveta Georgieva
* @idnumber 62591
* @task 2
* @compiler VC
*/

#pragma once
#include <iostream>
class MonsterCard
{
	char* name;
	int attackPoints;
	int protectPoints;
public:
	MonsterCard();
	MonsterCard(const char*, const int&, const int&);
	MonsterCard(const MonsterCard&);
	MonsterCard& operator=(const MonsterCard&);

	//getters:
	char* getName() const;
	int getAttackPoints() const;
	int getProtectPoints() const;

	//setters:
	void setName(const char*);
	void setAttackPoints(const int&);
	void setProtectPoints(const int&);

	~MonsterCard();
};

