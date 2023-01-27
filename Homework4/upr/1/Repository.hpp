#pragma once
#pragma once
#include "Averager.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
#include <string>
#include <vector>

class Repository {
	std::vector<Subscriber *> allSubs;
public:
	Repository();
	Repository(const Repository&);
	Repository* operator=(const Repository&);
	virtual ~Repository();
	void add(Averager *);
	void add(MovingAverager *);
	void add(PeriodicSampler *);

	Subscriber *get(std::string id);
};
