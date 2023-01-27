#pragma once
#include "LimitedTwowayCounter.hpp"
class Semaphore : protected LimitedTwowayCounter
{
public:
	Semaphore();
	Semaphore(const bool&);

	bool isAvailable() const;

	void wait();
	void signal();
};

