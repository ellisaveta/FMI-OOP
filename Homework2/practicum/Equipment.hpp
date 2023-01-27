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
#include "Weapon.hpp"
#include "Armor.hpp"
#include <iostream>
#include <vector>
#include <string>

template <class T>
class Equipment
{
	std::vector<T> objs;
	int slots;

public:
	Equipment() : slots(24) {}
	const int GetSlots() const;
	bool isItEmpty() const;
	bool isItFull() const;
	void Empty();
	void Add(const T&);
	void RemoveByIndex(const int&);
	const T& BestEqupment() const;
	bool operator==(const Equipment&) const;
	bool operator!=(const Equipment&) const;
	void print() const;
};

template<class T>
inline const int Equipment<T>::GetSlots() const
{
	return this->slots;
}

template<class T>
inline bool Equipment<T>::isItEmpty() const
{
	return GetSlots() == 24;
}

template<class T>
inline bool Equipment<T>::isItFull() const
{
	return GetSlots() == 0;
}

template<class T>
inline void Equipment<T>::Empty()
{
	this->objs.clear();
	this->slots = 24;
}

template<class T>
inline void Equipment<T>::Add(const T& new_el)
{
	if (new_el.GetType() == two_handed)
	{
		if (slots < 2)
		{
			std::cout << "No enough slots!\n";
			return;
		}
		this->slots -= 2;
	}
	else if (new_el.GetType() == Default)
	{
		std::cout << "Can not add default equipment! At least set type!\n";
		return;
	}
	else
	{
		if (slots < 1)
		{
			std::cout << "No enough slots!\n";
			return;
		}
		this->slots -= 1;
	}
	objs.push_back(new_el);
}

template<class T>
inline void Equipment<T>::RemoveByIndex(const int & index)
{
	if (index >= objs.size())
	{
		std::cout << "Index is too big! Nothing there!\n";
		return;
	}
	if (objs[index].GetType() == two_handed)
	{
		this->slots += 2;
	}
	else
	{
		this->slots += 1;
	}
	std::vector<T> temp;
	for (int i = 0; i < index; ++i)
	{
		temp.push_back(objs[i]);
	}
	for (int i = index + 1; i < this->objs.size(); ++i)
	{
		temp.push_back(objs[i]);
	}
	this->objs.clear();
	for (int i = 0; i < temp.size(); ++i)
	{
		this->objs.push_back(temp[i]);
	}
}

template<class T>
inline const T& Equipment<T>::BestEqupment() const
{
	if (objs.size() > 0)
	{
		double bestScore = objs[0].GetScore();
		int indexOfBest = 0;
		for (int i = 1; i < objs.size(); ++i)
		{
			double currScore = objs[i].GetScore();
			if (currScore > bestScore)
			{
				bestScore = currScore;
				indexOfBest = i;
			}
		}
		return objs[indexOfBest];
	}
	std::cout << "No equipments!\n";
	T temp;
	return temp;
}

template<class T>
inline bool Equipment<T>::operator==(const Equipment & other) const
{
	return this->BestEqupment() == other.BestEqupment();
}

template<class T>
inline bool Equipment<T>::operator!=(const Equipment & other) const
{
	return this->BestEqupment() != other.BestEqupment();
}

template<class T>
inline void Equipment<T>::print() const
{
	if (isItEmpty())
	{
		std::cout << "You don't have any equipment!\n";
		return;
	}
	for (int i = 0; i < objs.size(); ++i)
	{
		std::cout << "Equipment " << i + 1 << ":\n";
		objs[i].print();
	}
}
