#include <iostream>
#include "LimitedTwowayCounter.hpp"
#include "Semaphore.hpp"
using namespace std;
int main()
{
	LimitedTwowayCounter c1(3, 8, 3);
	LimitedCounter l2(0);
	Counter c2;
	TwowayCounter t1;
	LimitedTwowayCounter c3(2, 3);
	LimitedTwowayCounter c4(3, 4, 5, 6);
	LimitedCounter l1(4, 5, 3);
	Semaphore s1;
	Semaphore s2(true);
	Semaphore s3(false);
	c1.decrement();
	l2.increment();
	c2.getStep();
	t1.decrement();
	c3.increment();
	c4.decrement();
	l1.getMax();
	s1.isAvailable();
	s1.signal();
	s2.signal();
	s2.wait();
	s3.isAvailable();
	s3.wait();
	return 0;
}