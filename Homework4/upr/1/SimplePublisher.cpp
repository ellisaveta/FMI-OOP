#include "SimplePublisher.hpp"

void SimplePublisher::subscribe(Averager * av)
{
	subs.push_back(av);
}

void SimplePublisher::subscribe(MovingAverager * mAv)
{
	subs.push_back(mAv);
}

void SimplePublisher::subscribe(PeriodicSampler * pSam)
{
	subs.push_back(pSam);
}

/*void SimplePublisher::subscribe(Subscriber * sub)
{
	if (typeid(*sub).hash_code() == typeid(Averager).hash_code())
	{
		subscribe(dynamic_cast<Averager*>(sub));
		return;
	}
	if (typeid(*sub).hash_code() == typeid(MovingAverager).hash_code())
	{
		subscribe(dynamic_cast<MovingAverager*>(sub));
		return;
	}
	subscribe(dynamic_cast<PeriodicSampler*>(sub));
}*/

