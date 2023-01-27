#pragma once
#include "Message.hpp"
#include <string>
#include <vector>
class Subscriber
{
protected:
	std::vector<int> signals;
public:
	const std::string id;
	Subscriber(const std::string&);
	virtual void signal(Message);
	virtual int read() const;
};

