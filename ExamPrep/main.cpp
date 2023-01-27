#include <iostream>
#include "IntegerOperation.hpp"
#include "Special.hpp"
#include "Deck.hpp"

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif


using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	IntegerOperation test;
	test.insert(5);
	test.insert(3);
	test.insert(7);
	test.sum();
	std::cout << test.get_result() << std::endl;
	test.sub();
	std::cout << test.get_result() << std::endl;
	test.multiply();
	std::cout << test.get_result() << std::endl;

	IntegerOperation test1;
	test1.insert(5);
	test1.insert(3);
	test1.insert(7);
	IntegerOperation test2;
	test2.insert(2);
	test2.insert(14);
	test2.insert(4);
	std::cout << test1 + test2 << std::endl;
	std::cout << test1 - test2 << std::endl;
	std::cout << test1 * test2 << std::endl;
	std::cout << "----------------------------\n";

	HeroCard h1("jsd", 3, 5, 4, 7);
	h1.print();
	MagicCard ma1("mnfcjh", 5, 2, "Kill");
	ma1.print();
	Special s1("sgfd", 7, 4, 2, 5, "Speak", 5);
	s1.print();
	Deck d;
	d.addCard(&h1);
	d.addCard(&ma1);
	d.addCard(&s1);
	d.print();

	return 0;
}