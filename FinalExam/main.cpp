#include <iostream>
#include "Tuple.hpp"
#include "TupleContainer.hpp"

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

	Tuple<int, char> t1(23, 'a');
	t1.get_first();
	t1.get_second();
	cout<<t1.swap().get_first();
	TupleContainer<int, char> tc1;
	tc1.add_tuple(t1);
	tc1.get_count();
	tc1[0].get_second();
	TupleContainer<char, int> tc2 = tc1.swap();
	tc2[0].get_second();
	return 0;
}