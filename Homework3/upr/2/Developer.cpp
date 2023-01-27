#include "Developer.hpp"
#include "TeamLead.hpp"

Developer::Developer(const std::string & name) : name(name), salary(0.0), teamLead(nullptr) {}

std::string Developer::getName() const
{
	return this->name;
}

double Developer::getSalary() const
{
	return this->salary;
}

TeamLead * Developer::getTeamLead() const
{
	return this->teamLead;
}

void Developer::setInitialSalary(double amount)
{
	if (this->salary == 0)
	{
		this->salary = amount;
	}
}

void Developer::setTeamLead(TeamLead * teamLead)
{
	this->teamLead = teamLead;
}

void Developer::increaseSalaryBy(double amount)
{
	this->salary += amount;
}

void Developer::decreaseSalaryBy(double amount)
{
	if (this->salary > amount)
	{
		this->salary -= amount;
		return;
	}
	this->salary = 0;
}

void Developer::sendLeavingRequest()
{
	if (this->teamLead != nullptr)
	{
		LeavingRequest request(this->name);
		this->teamLead->addLeavingRequest(request);
	}
}

void Developer::sendPromotionRequest(double amount)
{
	if (this->teamLead != nullptr)
	{
		PromotionRequest request(this->name, amount);
		this->teamLead->addPromotionRequest(request);
	}
}
