#pragma once
#include "Averager.hpp"
#include "Message.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
#include "Publisher.hpp"
#include <vector>

class BacklogPublisher : public Publisher
{
	std::vector<Message> prevMes;
public:
	void subscribe(Averager *);
	void subscribe(MovingAverager *);
	void subscribe(PeriodicSampler *);

	void signal(Message) override;
};