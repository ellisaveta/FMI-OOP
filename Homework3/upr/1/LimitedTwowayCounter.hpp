#pragma once
#include "LimitedCounter.hpp"
#include "TwowayCounter.hpp"
class LimitedTwowayCounter : public TwowayCounter, public LimitedCounter
{
protected:
	int min;

public:
	LimitedTwowayCounter(const int&, const int&);
	LimitedTwowayCounter(const int&, const int&, const int&);
	LimitedTwowayCounter(const int&, const int&, const int&, const unsigned&);

	void increment();
	void decrement() override;

	int getMin() const;
};

