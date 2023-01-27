#pragma once
#include "Counter.hpp"
class TwowayCounter : virtual public Counter
{
public:
	TwowayCounter();
	TwowayCounter (const int&);
	TwowayCounter(const int&, const unsigned&);
	virtual void decrement();
};