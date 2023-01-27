#include "Repository.hpp"

Repository::Repository() {}

Repository::Repository(const Repository & other)
{
	for (int i = 0; i < other.allSubs.size(); ++i)
	{
		Subscriber* sub = new Subscriber(*other.allSubs[i]);
		allSubs.push_back(sub);
	}
}

Repository * Repository::operator=(const Repository & other)
{
	if (this != &other)
	{
		for (int i = 0; i < allSubs.size(); ++i)
		{
			delete allSubs[i];
		}
		allSubs.clear();
		for (int i = 0; i < other.allSubs.size(); ++i)
		{
			Subscriber* sub = new Subscriber(*other.allSubs[i]);
			allSubs.push_back(sub);
		}
	}
	return this;
}

Repository::~Repository()
{}

void Repository::add(Averager * av)
{
	Averager* newAv = new Averager(*av);
	allSubs.push_back(newAv);
}

void Repository::add(MovingAverager * mAv)
{
	MovingAverager* newMAv = new MovingAverager(*mAv);
	allSubs.push_back(newMAv);
}

void Repository::add(PeriodicSampler * pSam)
{
	PeriodicSampler* newPSam = new PeriodicSampler(*pSam);
	allSubs.push_back(newPSam);
}

Subscriber * Repository::get(std::string id)
{
	for (int i = 0; i < allSubs.size(); ++i)
	{
		if (allSubs[i]->id == id)
		{
			return allSubs[i];
		}
	}
	return nullptr;
}
