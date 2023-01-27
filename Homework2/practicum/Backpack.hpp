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
#include "Materials.hpp"
#include "Money.hpp"
#include <iostream>
#include <vector>

template<class K>
class Backpack
{
	std::vector<K> objs;
	int slots;
	int freeSpaceForEssence;
	int freeSpaceForOther;
public:
	Backpack() : slots(16), freeSpaceForOther(20), freeSpaceForEssence(10) {}
	const int GetSlots() const;
	bool isItEmpty() const;
	bool isItFull() const;
	void Empty();
	void Add(const K&);
	void RemoveByIndex(const int&);
	void Remove(const TypeMaterial&);
	void print() const;
};

template<class K>
inline const int Backpack<K>::GetSlots() const
{
	return this->slots;
}

template<class K>
inline bool Backpack<K>::isItEmpty() const
{
	return GetSlots() == 16 && this->freeSpaceForEssence == 10 && this->freeSpaceForOther == 20;
}

template<class K>
inline bool Backpack<K>::isItFull() const
{
	return GetSlots() == 0;
}

template<class K>
inline void Backpack<K>::Empty()
{
	this->objs.clear();
	this->slots = 16;
	this->freeSpaceForEssence = 10;
	this->freeSpaceForOther = 20;
}

template<class K>
inline void Backpack<K>::Add(const K & new_el)
{
	int slotsNeeded = 0;
	if (new_el.GetType() == TypeMaterial::essence)
	{
		slotsNeeded = new_el.GetQuantity() / 10;
		if (new_el.GetQuantity() % 10 >= this->freeSpaceForEssence)
		{
			slotsNeeded++;
		}
		if (slotsNeeded <= GetSlots())
		{
			this->slots -= slotsNeeded;
			this->freeSpaceForEssence -= new_el.GetQuantity() % 10;
			if (this->freeSpaceForEssence <= 0)
			{
				this->freeSpaceForEssence += 10;
			}
		}
		else
		{
			std::cout << "No enough slots\n";
			return;
		}
	}
	else
	{
		slotsNeeded = new_el.GetQuantity() / 20;
		if (new_el.GetQuantity() % 20 >= this->freeSpaceForOther)
		{
			slotsNeeded++;
		}
		if (slotsNeeded <= GetSlots())
		{
			this->slots -= slotsNeeded;
			this->freeSpaceForOther -= new_el.GetQuantity() % 20;
			if (this->freeSpaceForOther <= 0)
			{
				this->freeSpaceForOther += 20;
			}
		}
		else
		{
			std::cout << "No enough slots\n";
			return;
		}
	}
	objs.push_back(new_el);
}

template<class K>
inline void Backpack<K>::RemoveByIndex(const int & index)
{
	if (index >= objs.size())
	{
		std::cout << "Index is too big! Nothing there!\n";
		return;
	}
	if (objs[index].GetType() == TypeMaterial::essence)
	{
		this->slots += objs[index].GetQuantity() / 10;
		this->freeSpaceForEssence += objs[index].GetQuantity() % 10;
		if (freeSpaceForEssence > 10)
		{
			this->slots++;
			this->freeSpaceForOther -= 10;
		}
	}
	else
	{
		this->slots += objs[index].GetQuantity() / 20;
		this->freeSpaceForOther += objs[index].GetQuantity() % 20;
		if (freeSpaceForOther > 20)
		{
			this->slots++;
			this->freeSpaceForOther -= 20;
		}
	}
	std::vector<K> temp;
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

template<class K>
inline void Backpack<K>::Remove(const TypeMaterial & type_el)
{
	for (int i = 0; i < objs.size(); ++i)
	{
		if (objs[i].GetType() == type_el)
		{
			RemoveByIndex(i);
		}
	}
}

template<class K>
inline void Backpack<K>::print() const
{
	if (isItEmpty())
	{
		std::cout << "Backpack is empty!\n";
		return;
	}
	std::cout << "Backpack has:\n";
	for (int i = 0; i < objs.size(); ++i)
	{
		objs[i].print();
	}
}

template <>
class Backpack<Money>
{
	Money money;
public:
	Backpack(const int & = 0, const int& = 0);
	const int GetSlots() const
	{
		return 16;
	}
	bool isItEmpty() const
	{
		return money.GetGold() == 0 && money.GetSilver() == 0;
	}
	bool isItFull() const
	{
		return false;
	}
	void Empty()
	{
		money.SetGold(0);
		money.SetSilver(0);
	}
	void Add(const TypeMoney& t, const int& to_add)
	{
		if (t == TypeMoney::gold)
		{
			money.AddGold(to_add);
			return;
		}
		money.AddSilver(to_add);
	}
	void Add(const int& g, const int& s)
	{
		money.AddGold(g);
		money.AddSilver(s);
	}
	void Remove(const TypeMoney& t, const int& to_remove)
	{
		if (t == TypeMoney::gold)
		{
			money.RemoveGold(to_remove);
			return;
		}
		money.RemoveSilver(to_remove);
	}
	void print() const
	{
		std::cout << "Backpack has money: " << money.GetGold() << " gold, " << money.GetSilver() << " silver.\n";
	}
};

inline Backpack<Money>::Backpack(const int & g, const int & s)
{
	money.AddGold(g);
	money.AddSilver(s);
}
