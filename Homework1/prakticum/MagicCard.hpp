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

enum Type {none, trap, buff, spell};

class MagicCard
{
	char* name;
	char* effect;
	Type type;

public:
	MagicCard();
	MagicCard(const char*, const char*, const Type&);
	MagicCard(const MagicCard&);
	MagicCard& operator=(const MagicCard&);

	//getters:
	char* getName() const;
	char* getEffect() const;
	Type getType() const;

	//setters:
	void setName(const char*);
	void setEffect(const char*);
	void setType(const Type&);

	~MagicCard();
};

