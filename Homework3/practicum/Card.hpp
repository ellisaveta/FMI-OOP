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
public:
	Card(const std::string& = "", const std::string& = "");
	Card(const Card&);

	//getters:
	std::string getName() const;
	std::string getEffect() const;

	//setters:
	void setName(const std::string&);
	void setEffect(const std::string&);
};