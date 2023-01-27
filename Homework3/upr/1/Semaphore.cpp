#include "Semaphore.hpp"

Semaphore::Semaphore() : LimitedTwowayCounter(0, 1, 0, 1), Counter() {}

Semaphore::Semaphore(const bool & b) : LimitedTwowayCounter(0, 1)
{
	if (b)
	{
		this->total = 1;
		return;
	}
}

bool Semaphore::isAvailable() const
{
	return this->total > 0;
}

void Semaphore::wait()
{
	decrement();
}

void Semaphore::signal()
{
	increment();
}
