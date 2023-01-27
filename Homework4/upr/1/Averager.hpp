#pragma once
#include "Message.hpp"
#include "Subscriber.hpp"
#include <string>

class Averager : public Subscriber
{
public:
	Averager(std::string id);
};

