#include "TeamLead.hpp"
#include <iostream>

TeamLead::TeamLead(const std::string & name, double salary) : Developer(name)
{
	this->salary = salary;
	this->teamLead = this;
}

std::vector<Developer*> TeamLead::getTeam() const
{
	return this->devs;
}

void TeamLead::addDeveloperToTeam(Developer * developer, double salary)
{
	if (developer != nullptr)
	{
		for (int i = 0; i < devs.size(); ++i)
		{
			if ((*devs[i]).getName() == (*developer).getName())
			{
				(*devs[i]).setInitialSalary(salary);
				return;
			}
		}
		(*developer).setInitialSalary(salary);
		(*developer).setTeamLead(this);
		devs.push_back(developer);
		return;
	}
	std::cout << "Developer is not initialized!\n";
}

void TeamLead::removeDeveloperFromTeam(const std::string & name)
{
	for (int i = devs.size() - 1; i >= 0; --i)
	{
		if ((*devs[i]).getName() == name)
		{
			(*devs[i]).setTeamLead(nullptr);
			(*devs[i]).decreaseSalaryBy((*devs[i]).getSalary());
			std::vector<Developer*> temp;
			for (int j = 0; j < i; ++j)
			{
				temp.push_back(devs[j]);
			}
			for (int j = i + 1; j < devs.size(); ++j)
			{
				temp.push_back(devs[j]);
			}
			devs.clear();
			for (int j = 0; j < temp.size(); ++j)
			{
				devs.push_back(temp[j]);
			}
			return;
		}
	}
}

void TeamLead::removeDeveloperFromTeam(const unsigned & index)
{
	(*devs[index]).setTeamLead(nullptr);
	(*devs[index]).decreaseSalaryBy((*devs[index]).getSalary());
	std::vector<Developer*> temp;
	for (int j = 0; j < index; ++j)
	{
		temp.push_back(devs[j]);
	}
	for (int j = index + 1; j < devs.size(); ++j)
	{
		temp.push_back(devs[j]);
	}
	devs.clear();
	for (int j = 0; j < temp.size(); ++j)
	{
		devs.push_back(temp[j]);
	}
}

void TeamLead::increaseTeamSalariesBy(double amount)
{
	for (int i = 0; i < devs.size(); ++i)
	{
		(*devs[i]).increaseSalaryBy(amount);
	}
}

void TeamLead::decreaseTeamSalariesBy(double amount)
{
	for (int i = 0; i < devs.size(); ++i)
	{
		(*devs[i]).decreaseSalaryBy(amount);
	}
}

void TeamLead::addLeavingRequest(const LeavingRequest & leavingRequest)
{
	this->leavingReqs.push_back(leavingRequest);
}

void TeamLead::addPromotionRequest(const PromotionRequest & promotionRequest)
{
	this->promReqs.push_back(promotionRequest);
}

void TeamLead::fulfillLeavingRequests()
{
	for (int i = 0; i < leavingReqs.size(); ++i)
	{
		for (int j = 0; j < devs.size(); ++j)
		{
			if ((*devs[j]).getName() == leavingReqs[i].getSender())
			{
				removeDeveloperFromTeam(j);
			}
		}
	}
	this->leavingReqs.clear();
}

void TeamLead::fulfillPromotionRequests()
{
	for (int i = 0; i < promReqs.size(); ++i)
	{
		for (int j = 0; j < devs.size(); ++j)
		{
			if ((*devs[j]).getName() == promReqs[i].getSender())
			{
				(*devs[j]).increaseSalaryBy(promReqs[i].getAmount());
			}
		}
	}
	this->promReqs.clear();
}
