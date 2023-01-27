#include <iostream>
#include "UniqueBox.hpp"

using namespace std;
int main ()
{
	UniqueBox<int> container;
	container += 3;
	container += 5;
	std::cout << container.get_size() << std::endl;
	container += 6;
	container += 3;
	std::cout << container.get_size() << std::endl;
	std::cout << container[1] << std::endl;
	return 0;
}