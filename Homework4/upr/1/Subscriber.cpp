#include "Subscriber.hpp"

Subscriber::Subscriber(const std::string & id) : id(id) {}

void Subscriber::signal(Message mes)
{
	signals.push_back(mes.data);
}

int Subscriber::read() const
{
	if (signals.size() == 0)
	{
		return 0;
	}
	int total = 0;
	for (int i = 0; i < signals.size(); ++i)
	{
		total += signals[i];
	}
	return total / signals.size();
}
