#include "MovingAverager.hpp"

MovingAverager::MovingAverager(std::string id, size_t windowSize) : Subscriber(id), windowSize(windowSize) {}

void MovingAverager::signal(Message mes)
{
	if (signals.size() == windowSize)
	{
		std::vector <int> temp;
		for (int i = 1; i < signals.size(); ++i)
		{
			temp.push_back(signals[i]);
		}
		signals.clear();
		for (int i = 0; i < temp.size(); ++i)
		{
			signals.push_back(temp[i]);
		}
	}
	signals.push_back(mes.data);
}
