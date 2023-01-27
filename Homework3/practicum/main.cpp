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

	MonsterCard m1("gdsf", "kill", 5, 7);
	m1.getName();
	m1.getEffect();
	m1.getAttackPoints();
	m1.getProtectPoints();
	m1.setName("Name");
	m1.getName();
	m1.setProtectPoints(6);
	MagicCard ma1;
	ma1.setName("uywfcdsh");
	ma1.setEffect("shoot");
	ma1.setType(CardType::SPELL);

	PendulumCard p1("yghskd", "sdcugaas", 5, 6, 16,CardType::TRAP);
	p1.getName();
	p1.getEffect();
	p1.getAttackPoints();
	p1.getProtectPoints();
	p1.getType();
	p1.getPendulumScale();
	p1.setName("Pendulum");
	p1.setEffect("Trash");
	p1.setAttackPoints(14);
	p1.setProtectPoints(9);
	p1.setPendulumScale(5);

	PendulumCard p2 = p1;
	p2.setName("Random");

	Deck d1;
	d1.setDeckname("Deck1");
	d1.addMagicCard(ma1);
	d1.addPendulumCard(p1);
	d1.addMonsterCard(m1);
	d1.addPendulumCard(p2);
	d1.getDeckName();
	d1.getMagicCardCount();
	d1.getMagicCards();
	d1.getMonsterCardCount();
	d1.getMonsterCards();
	d1.getPendulumCardCount();
	d1.getPendulumCards();
	d1.setMonsterCard(2, m1);
	d1.setPendulumCard(1, p2);
	d1.clearDeck();
	d1.getMonsterCardCount();

	MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 3000, 2500);
	MonsterCard magician("Dark Magician", "The ultimate wizard.", 2500, 2100);
	MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", CardType::SPELL);
	MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", CardType::TRAP);
	PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards", 1200, 600, 8, CardType::SPELL);
	Duelist firstDuelist("Ivan Ivanov");
	firstDuelist.getDeck().setDeckname("Magician Deck");
	firstDuelist.getDeck().addMonsterCard(dragon);
	firstDuelist.getDeck().addMagicCard(swords);
	firstDuelist.getDeck().addMonsterCard(magician);
	firstDuelist.getDeck().addMagicCard(cylinder);
	firstDuelist.getDeck().addPendulumCard(timegazer);

	firstDuelist.saveDeck("magician_deck.txt");
	firstDuelist.loadDeck("magician_deck1.txt");
	firstDuelist.saveDeck("magician_deck.txt");

	MagicCard box("Mystic Box", "Destroy one monster.", CardType::SPELL);
	firstDuelist.getDeck().setMagicCard(1, box);

	return 0;
}