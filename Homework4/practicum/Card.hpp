/**
* Solution to homework assignment 1
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
#include <string>
class Card
{
protected:
	std::string name;
	std::string effect;
	unsigned int rarity;
public:
	Card(const std::string& = "", const std::string& = "", const unsigned int& = 0);
	Card(const Card&);
	virtual ~Card() = 0;

	//getters:
	std::string getName() const;
	std::string getEffect() const;
	unsigned int getRarity() const;

	//setters:
	void setName(const std::string&);
	void setEffect(const std::string&);
	void setRarity(const unsigned int&);

	bool operator<(const Card&) const;
	bool operator>(const Card&) const;
};

