#include "LimitedTwowayCounter.hpp"
#include <iostream>

LimitedTwowayCounter::LimitedTwowayCounter(const int & min, const int & max) :
	LimitedCounter(max), Counter(), min(min) {}

LimitedTwowayCounter::LimitedTwowayCounter(const int & min, const int & max, const int & initial) : 
	LimitedCounter(max, initial), Counter(initial), min(min) {}

LimitedTwowayCounter::LimitedTwowayCounter(const int & min, const int & max, const int & initial, const unsigned & step) :
	LimitedCounter(max, initial, step), Counter(initial, step), min(min) {}

void LimitedTwowayCounter::increment()
{
	LimitedCounter::increment();
}

void LimitedTwowayCounter::decrement()
{
	if ((int)(this->total - this->step) >= this->min)
	{
		TwowayCounter::decrement();
		return;
	}
	std::cout << "Hit the min limit!\n";
}

int LimitedTwowayCounter::getMin() const
{
	return this->min;
}
