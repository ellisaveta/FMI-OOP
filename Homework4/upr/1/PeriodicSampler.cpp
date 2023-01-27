#include "PeriodicSampler.hpp"

PeriodicSampler::PeriodicSampler(std::string id, size_t period) : Subscriber(id), period(period) {}

void PeriodicSampler::signal(Message mes)
{
	signals.push_back(mes.data);
	if ((signals.size() - 1) % period == 0)
	{
		unignoredSignals.push_back(mes.data);
	}
}

int PeriodicSampler::read() const
{
	if (unignoredSignals.size() == 0)
	{
		return 0;
	}
	return unignoredSignals.back();
}
