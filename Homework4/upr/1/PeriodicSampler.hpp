#pragma once
#include "Message.hpp"
#include "Subscriber.hpp"
#include <string>

class PeriodicSampler : public Subscriber
{
	size_t period;
	std::vector<int> unignoredSignals;
public:
	PeriodicSampler(std::string id, size_t period);

	void signal(Message) override;

	int read() const override;
};