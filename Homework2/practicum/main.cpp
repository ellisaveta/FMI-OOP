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

#include <iostream>
#include <vector>
#include <string>

#include "Armor.hpp"
#include "Weapon.hpp"
#include "Equipment.hpp"

#include "Money.hpp"
#include "Materials.hpp"
#include "Backpack.hpp"

#include "Inventory.hpp"
using namespace std;
int main()
{
	Armor ar1;
	ar1.SetType(leather);
	ar1.AddEffect("Rf", 4.5);
	ar1.AddEffect("Ts", 5.6);
	ar1.SetDefense(2);
	ar1.RemoveEffectByIndex(1);
	ar1.AddEffect("Asd", 7.7);
	ar1.GetScore();
	ar1.GetDefense();
	ar1.GetType();

	Armor arrr;
	arrr = ar1;

	Weapon w1;
	w1.SetKind(axe);
	w1.SetHitDamage(3, 8);
	w1.AddEffect("wer", 5.6);
	w1.AddEffect("gfd", 7.6);
	w1.AddEffect("wer", 2.3);
	w1.RemoveEffectByIndex(0);
	w1.AddEffect("trerew", 9.9);
	w1.GetHitDamageAvg();
	w1.GetKind();
	w1.GetScore();
	w1.GetType();
	w1.ChangeType(one_handed);
	w1.GetScore();
	w1.ChangePowerOfEffect("gfd", 3.3);
	w1.GetScore();
	w1.SetKind(sword);
	w1.GetScore();

	Armor a2;
	a2.AddEffect("FDYS", 2.3);
	a2.SetType(mail);
	a2.SetDefense(5);
	Armor a3;
	a3.SetType(cloth);
	a3.SetDefense(9);
	a3.AddEffect("sfass", 2.3);
	if (a2 == a3)
		cout << "yes\n";

	Equipment<Armor> e1;
	e1.Add(ar1);
	e1.Add(a2);
	e1.RemoveByIndex(1);
	e1.Add(a3);
	e1.Add(a2);
	e1.BestEqupment();
	e1.isItFull();
	e1.isItEmpty();
	e1.GetSlots();
//	e1.Empty();
	e1.GetSlots();
	e1.isItFull();
	e1.isItEmpty();

	Weapon w2;
	w2.SetKind(mace);
	w2.AddEffect("Tyuas", 5.4);
	w2.SetHitDamage(4, 8);
	Weapon w3;
	w3.SetKind(dagger);
	w3.SetHitDamage(5, 6);
	w3.AddEffect("ufdh", 10.3);
	w3.AddEffect("fdkvgjds", 1245.3);

	Weapon w4 = w2;

	Equipment<Weapon> e2;
	e2.Add(w1);
	e2.Add(w2);
	e2.RemoveByIndex(0);
	e2.Add(w3);
	e2.Add(w2);
	e2.BestEqupment();
	e2.isItFull();
	e2.isItEmpty();
	e2.GetSlots();
//	e2.Empty();
	e2.GetSlots();
	e2.isItFull();
	e2.isItEmpty();
	
	Equipment<Weapon> e3;
	e3.Add(w4);
	e3 == e2;
	e2 != e3;
	e2 == e2;
	e3 == e3;

	e1.print();
	e2.print();

	Money m1(2, 3);
	Money m2(2, 456);
	m1.AddGold(3);
	m1.AddSilver(100);
	m2.GetGold();
	m1.GetSilver();
	m2.RemoveSilver(300);
	m1.RemoveGold(1);
	m2.SetGold(2);
	m2.SetSilver(67);
	Materials ma1(TypeMaterial::cloth, 50);
	Materials ma2;
	ma2.SetType(TypeMaterial::essence);
	ma2.SetQuantity(20);
	ma1.GetType();
	ma2.GetQuantity();

	Backpack<Materials> b;
	b.GetSlots();
	b.Add(ma1);
	b.Add(ma2);
	b.isItEmpty();
	b.RemoveByIndex(0);
	b.Add(ma1);
	b.Remove(TypeMaterial::essence);
	b.Add(ma2);
	b.isItEmpty();
	b.isItFull();
//	b.Empty();
	b.isItEmpty();
	b.isItFull();

	Backpack<Money> b1;
	b1.Add(TypeMoney::gold, 6);
	b1.Add(TypeMoney::silver, 467);
	b1.Remove(TypeMoney::silver, 147);
	b1.Remove(TypeMoney::gold, 1);
	b1.isItEmpty();
	b1.isItFull();
	b1.Empty();
	b1.isItEmpty();
	b1.Add(4, 678);

	b.print();
	b1.print();

	Inventory<Backpack<Money>> in1;
	in1.ADDorREMOVEfromInventory().Add(3, 5);
	in1.ADDorREMOVEfromInventory().Remove(TypeMoney::silver, 6);
	cout << in1;

	Inventory<Backpack<Money>> in2;
	in2.ADDorREMOVEfromInventory().Add(4, 70);

	in2 == in1;
	in1 != in2;

	Inventory<Backpack<Materials>> in3;
	in3.isInventoryEmpty();
	in3.isInventoryFull();
	in3.ADDorREMOVEfromInventory().Add(ma1);
	in3.ADDorREMOVEfromInventory().Add(ma2);
	in3.ADDorREMOVEfromInventory().Remove(TypeMaterial::essence);
	in3.ADDorREMOVEfromInventory().Add(ma2);
	in3.ADDorREMOVEfromInventory().Remove(TypeMaterial::herbs);
	cout << in3;
	Inventory<Backpack<Materials>> in4;
	in4.ADDorREMOVEfromInventory().Add(ma1);
	in4 == in3;
	in3 != in4;

	in4.EmptyInventory();

	Inventory<Equipment<Armor>> in5;
	in5.isInventoryEmpty();
	in5.isInventoryFull();
	in5.ADDorREMOVEfromInventory().Add(ar1);
	in5.ADDorREMOVEfromInventory().Add(a2);
	in5.ADDorREMOVEfromInventory().RemoveByIndex(5);
	cout << in5;
	Inventory<Equipment<Armor>> in6;
	in6.ADDorREMOVEfromInventory().Add(a3);
	in5 == in6;
	in6 != in5;
	in6.EmptyInventory();

	Inventory<Equipment<Weapon>> in7;
	in7.isInventoryEmpty();
	in7.isInventoryFull();
	in7.ADDorREMOVEfromInventory().Add(w1);
	in7.ADDorREMOVEfromInventory().Add(w3);
	in7.ADDorREMOVEfromInventory().RemoveByIndex(0);
	in7.ADDorREMOVEfromInventory().Add(w2);
	cout << in7;

	Inventory<Equipment<Weapon>> in8;
	in8.ADDorREMOVEfromInventory().Add(w4);
	in8.ADDorREMOVEfromInventory().Add(w3);
	in7 == in8;
	in8 != in7;

	in8.EmptyInventory();
	in8.isInventoryEmpty();

	return 0;
}