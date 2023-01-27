#include "BacklogPublisher.hpp"

void BacklogPublisher::subscribe(Averager * av)
{
	subs.push_back(av);
	for (int i = 0; i < prevMes.size(); ++i)
	{
		av->signal(prevMes[i]);
	}
}

void BacklogPublisher::subscribe(MovingAverager * mAv)
{
	subs.push_back(mAv);
	for (int i = 0; i < prevMes.size(); ++i)
	{
		mAv->signal(prevMes[i]);
	}
}

void BacklogPublisher::subscribe(PeriodicSampler * pSam)
{
	subs.push_back(pSam);
	for (int i = 0; i < prevMes.size(); ++i)
	{
		pSam->signal(prevMes[i]);
	}
}

void BacklogPublisher::signal(Message mes)
{
	for (int i = 0; i < subs.size(); ++i)
	{
		subs[i]->signal(mes);
	}
	prevMes.push_back(mes);
}
