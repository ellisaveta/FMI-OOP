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

enum class TypeMoney {gold, silver};
class Money
{
	int gold;
	int silver;
public:
	Money(const int& = 0, const int& = 0);
	int GetGold() const;
	int GetSilver() const;
	void SetGold(const int&);
	void SetSilver(const int&);
	void AddGold(const int&);
	void AddSilver(const int&);
	void RemoveGold(const int&);
	void RemoveSilver(const int&);
};

