#include "Counter.hpp"

Counter::Counter() : total(0), step(1) {}

Counter::Counter(const int & initial) : total(initial), step(1) {}

Counter::Counter(const int & initial, const unsigned & step) : total(initial), step(step) {}

void Counter::increment()
{
	this->total += this->step;
}

int Counter::getTotal() const
{
	return this->total;
}

const unsigned Counter::getStep() const
{
	return this->step;
}
