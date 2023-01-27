#include "Publisher.hpp"

Publisher::Publisher() {}

Publisher::Publisher(const Publisher & other)
{
	for (int i = 0; i < other.subs.size(); ++i)
	{
		Subscriber* sub = new Subscriber(*other.subs[i]);
		subs.push_back(sub);
	}
}

Publisher::~Publisher()
{}

Publisher * Publisher::operator=(const Publisher & other)
{
	if (this != &other)
	{
		for (int i = 0; i < subs.size(); ++i)
		{
			delete subs[i];
		}
		subs.clear();
		for (int i = 0; i < other.subs.size(); ++i)
		{
			Subscriber* sub = new Subscriber(*other.subs[i]);
			subs.push_back(sub);
		}
	}
	return this;
}

void Publisher::unsubscribe(Averager * av)
{
	for (int i = 0; i < subs.size(); ++i)
	{
		if (subs[i]->id == av->id && typeid(*subs[i]).hash_code() == typeid(Averager).hash_code())
		{
			std::vector<Subscriber*> temp;
			for (int j = 0; j < i; ++j)
			{
				temp.push_back(subs[j]);
			}
			for (int j = i + 1; j < subs.size(); ++j)
			{
				temp.push_back(subs[j]);
			}
			subs.clear();
			for (int j = 0; j < temp.size(); ++j)
			{
				subs.push_back(temp[j]);
			}
			return;
		}
	}
}

void Publisher::unsubscribe(MovingAverager * mAv)
{
	for (int i = 0; i < subs.size(); ++i)
	{
		if (subs[i]->id == mAv->id && typeid(*subs[i]).hash_code() == typeid(MovingAverager).hash_code())
		{
			std::vector<Subscriber*> temp;
			for (int j = 0; j < i; ++j)
			{
				temp.push_back(subs[j]);
			}
			for (int j = i + 1; j < subs.size(); ++j)
			{
				temp.push_back(subs[j]);
			}
			subs.clear();
			for (int j = 0; j < temp.size(); ++j)
			{
				subs.push_back(temp[j]);
			}
			return;
		}
	}
}

void Publisher::unsubscribe(PeriodicSampler * pSam)
{
	for (int i = 0; i < subs.size(); ++i)
	{
		if (subs[i]->id == pSam->id && typeid(*subs[i]).hash_code() == typeid(PeriodicSampler).hash_code())
		{
			std::vector<Subscriber*> temp;
			for (int j = 0; j < i; ++j)
			{
				temp.push_back(subs[j]);
			}
			for (int j = i + 1; j < subs.size(); ++j)
			{
				temp.push_back(subs[j]);
			}
			subs.clear();
			for (int j = 0; j < temp.size(); ++j)
			{
				subs.push_back(temp[j]);
			}
			return;
		}
	}
}

void Publisher::signal(Message mes)
{
	for (int i = 0; i < subs.size(); ++i)
	{
		subs[i]->signal(mes);
	}
}