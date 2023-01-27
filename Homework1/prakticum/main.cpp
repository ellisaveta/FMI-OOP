#include <iostream>
#include "Date.hpp"
#include "MonsterCard.hpp"
#include "MagicCard.hpp"
#include "Deck.hpp"
#include "Duelist.hpp"
#include <iomanip>
int main()
{
	char a[]="56";
	std::cout << std::setw(2) << std::setfill('0') << a;
	Date c(20, 11, 2000);
	c.addDays(31);
	Date k(31, 3, 2007);
	k.addDays(9);
	std::cout << std::endl << c.isLeapYear();
	std::cout << std::endl << c.DaysToXmas();

	std::cout << std::endl << k.DaysToXmas();
	k.removeDays(9);
	Date o(1, 1, 2009);
	std::cout << std::endl << k.DaysToNewYear();
	std::cout << std::endl << k.DaysTo(o);

	Date d1(31, 3, 2014); // 31.03.2014
	Date d2; //01.01.2000
	d1.addDays(1); // 01.04.2014
	d1.removeDays(1); //31.03.2014
	std::cout<<std::endl<<d1.DaysToXmas(); //269
	std::cout << std::endl << d1.isLeapYear(); //false (2014 is not a leap year)
	std::cout << std::endl << d1.isLaterThen(o); //false

	Date s(3, 3, 2007);
	Date r(3, 3, 2009);
	r.removeDays(89);
	std::cout << std::endl << s.DaysTo(r);

	//-----------------------------------------
	Duelist w("Az");

	//MonsterCard d;
	//d.setAttackPoints(2);
	MagicCard b("ertyhb", "ywuegds", spell);
	Deck e;
	std::cout << std::endl << e.getMagicCardCount();

	e.addMagicCard(b);
	std::cout << std::endl << e.getMagicCardCount();
	std::cout << std::endl << e.getMonsterCardCount();
	//e.addMonsterCard(d);
	std::cout << std::endl << e.getMonsterCardCount();

	Deck d;
	// 4-th card in the Monster deck becomes "Blue-eyes white dragon" with
	//ATK: 3000 DEF: 2500
	MonsterCard ca("Blue-eyes white dragon", 3000, 2500);
	d.changeMonsterCard(4, ca);
	// 5-th card in the Magic deck is added/changed to "Monster reborn"
	MagicCard ma("Monster reborn", "revive", spell);
	d.changeMagicCard(2, ma);
	//Returns the amount of MagicCards in the deck
	std::cout<<std::endl<<d.getMagicCardCount(); //1
	//Returns the amount of MonsterCards in the deck
	std::cout << std::endl << d.getMonsterCardCount(); //1
	Duelist player1("Seto Kaiba");
	///Changes the 2-nd monster card in the Monster deck to“Dark Magician”
	MonsterCard DarkMagician("Dark Magician", 2500, 2100);
	player1.changeMonsterCardInDeck(2, DarkMagician);
	Duelist player2("Yugi Muto");
	//Changes the 2-nd magic card in the Magic deck to “Reflection”
	MagicCard Reflection("Reflection", "Reflects the last played spell", trap);
		player2.changeMagicCardInDeck(2, Reflection);
		player2.changeMagicCardInDeck(0, Reflection);
		player2.changeMagicCardInDeck(19, Reflection);
		player2.changeMagicCardInDeck(2, b);
	std::cout << std::endl << player2.getMagicCardCountInDeck(); //1
	return 0;
}
