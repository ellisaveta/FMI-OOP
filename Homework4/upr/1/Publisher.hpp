#pragma once
#include <vector>
#include "Averager.hpp"
#include "Message.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
#include "Subscriber.hpp"

class Publisher
{
protected:
	std::vector<Subscriber*> subs;
public:
	Publisher();
	Publisher(const Publisher&);
	virtual ~Publisher();
	Publisher* operator=(const Publisher&);

	virtual void subscribe(Averager *) = 0;
	virtual void subscribe(MovingAverager *) = 0;
	virtual void subscribe(PeriodicSampler *) = 0;

	void unsubscribe(Averager *);
	void unsubscribe(MovingAverager *);
	void unsubscribe(PeriodicSampler *);

	virtual void signal(Message);
};

