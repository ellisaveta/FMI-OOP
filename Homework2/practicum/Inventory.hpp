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
#include "Backpack.hpp"
#include "Equipment.hpp"

#include <iostream>

template <class R>
class Inventory;

template<class R>
std::ostream& operator<<(std::ostream& stream, const Inventory<R>& inv);

template <class R>
class Inventory
{
	R inventory;
public:
	bool isInventoryEmpty() const;
	bool isInventoryFull() const;
	void EmptyInventory();
	R& ADDorREMOVEfromInventory();
	const R& SeeInventory() const;
	bool operator==(const Inventory&) const;
	bool operator!=(const Inventory&) const;
	friend std::ostream& operator<< <R>(std::ostream&, const Inventory<R>&);
};

template<class R>
inline bool Inventory<R>::isInventoryEmpty() const
{
	return this->inventory.isItEmpty();
}

template<class R>
inline bool Inventory<R>::isInventoryFull() const
{
	return this->inventory.isItFull();
}

template<class R>
inline void Inventory<R>::EmptyInventory()
{
	this->inventory.Empty();
}

template<class R>
inline R & Inventory<R>::ADDorREMOVEfromInventory()
{
	return this->inventory;
}

template<class R>
inline const R & Inventory<R>::SeeInventory() const
{
	return this->inventory;
}

template<class R>
inline bool Inventory<R>::operator==(const Inventory & other) const
{
	return SeeInventory().GetSlots() == other.SeeInventory().GetSlots();
}

template<class R>
inline bool Inventory<R>::operator!=(const Inventory & other) const
{
	return SeeInventory().GetSlots() != other.SeeInventory().GetSlots();
}

template<class R>
std::ostream& operator<<(std::ostream& stream, const Inventory<R>& inv)
{
	if (inv.isInventoryEmpty())
	{
		return stream << "You don't have any inventory!\n";
	}
	inv.inventory.print();
	return stream << "";
}