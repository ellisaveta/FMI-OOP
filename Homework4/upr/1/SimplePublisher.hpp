#pragma once
#include "Averager.hpp"
#include "Message.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
#include "Publisher.hpp"
#include <vector>

class SimplePublisher : public Publisher
{
public:

	void subscribe(Averager *);
	void subscribe(MovingAverager *);
	void subscribe(PeriodicSampler *);
};