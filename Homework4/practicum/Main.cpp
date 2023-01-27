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

#include <iostream>
#include "Deck.hpp"
#include "PendulumCard.hpp"
#include "Duelist.hpp"
using namespace std;

int main()
{

	MonsterCard m1("gdsf", "kill", 2, 5, 7);
	m1.getName();
	m1.getEffect();
	m1.getRarity();
	m1.getAttackPoints();
	m1.getProtectPoints();
	m1.setName("Name");
	m1.getName();
	m1.setProtectPoints(6);
	MagicCard ma1;
	ma1.setName("uywfcdsh");
	ma1.setEffect("shoot");
	ma1.setRarity(30);
	ma1.setType(CardType::SPELL);

	PendulumCard p1("yghskd", "sdcugaas", 8, 5, 6, 16, CardType::TRAP);
	p1.getName();
	p1.getEffect();
	p1.getAttackPoints();
	p1.getProtectPoints();
	p1.getRarity();
	p1.getType();
	p1.getPendulumScale();
	p1.setName("Pendulum");
	p1.setEffect("Trash");
	p1.setRarity(43);
	p1.setAttackPoints(14);
	p1.setProtectPoints(9);
	p1.setPendulumScale(5);

	PendulumCard p2 = p1;
	p2.setName("Random");

	Deck d1;
	d1.setDeckname("Deck1");
	d1.addCard(&ma1);
	d1.addCard(&p1);
	d1.addCard(&m1);
	d1.addCard(&p2);
	d1.getDeckName();
	d1.getMagicCardCount();
	d1.getCards();
	d1.getMonsterCardCount();
	d1.getCardsCount();
	d1.getPendulumCardCount();
	d1.setCard(2, &ma1);
	d1.setCard(1, &p2);
	d1.clearDeck();
	d1.getMonsterCardCount();

	MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 43, 3000, 2500);
	MonsterCard magician("Dark Magician", "The ultimate wizard.", 23, 2500, 2100);
	MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", 123, CardType::SPELL);
	MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", 9, CardType::TRAP);
	PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards", 3, 1200, 600, 8, CardType::SPELL);
	Duelist firstDuelist("Ivan Ivanov");
	firstDuelist.getDeck().setDeckname("Magician Deck");
	firstDuelist.getDeck().addCard(&dragon);
	firstDuelist.getDeck().addCard(&swords);
	firstDuelist.getDeck().addCard(&magician);
	firstDuelist.getDeck().addCard(&cylinder);
	firstDuelist.getDeck().addCard(&timegazer);
	firstDuelist.getDeck().shuffle();
	firstDuelist.saveDeck("magician_deck.txt");
	MagicCard box("Mystic Box", "Destroy one monster.", 0, CardType::SPELL);
	firstDuelist.getDeck().setCard(1, &box);
	Duelist secondDuelist("Gosho Goshev");
	secondDuelist.getDeck().addCard(&dragon);
	secondDuelist.getDeck().addCard(&swords);
	secondDuelist.getDeck().addCard(&magician);
	secondDuelist.getDeck().addCard(&cylinder);
	secondDuelist.getDeck().addCard(&timegazer);
	firstDuelist.duel(secondDuelist);
//	firstDuelist.saveDeck("magician_deck1.txt");

//	firstDuelist.saveDeck("magician_deck.txt");
	firstDuelist.loadDeck("magician_deck1.txt");
	secondDuelist.duel(firstDuelist);
	firstDuelist.saveDeck("magician_deck2.txt");

	return 0;
}