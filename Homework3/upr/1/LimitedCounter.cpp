#include "LimitedCounter.hpp"
#include <iostream>

LimitedCounter::LimitedCounter(const int & max) : Counter(), max(max) {}

LimitedCounter::LimitedCounter(const int & max, const int & initial) : Counter(initial), max(max) {}

LimitedCounter::LimitedCounter(const int & max, const int & initial, const unsigned & step) : 
	Counter(initial, step), max(max) {}

void LimitedCounter::increment()
{
	if((int)(this->total + this->step) <= this->max)
	{
		Counter::increment();
		return;
	}
	std::cout << "Hit the max limit!\n";
}

int LimitedCounter::getMax() const
{
	return this->max;
}
