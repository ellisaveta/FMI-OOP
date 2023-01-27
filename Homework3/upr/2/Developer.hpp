#pragma once
#include <string>
class TeamLead;

class Developer
{
protected:
	std::string name;
	double salary;
	TeamLead* teamLead;

public:
	Developer(const std::string& name);

	std::string getName() const;
	double getSalary() const;
	TeamLead* getTeamLead() const;

	void setInitialSalary(double amount);
	void setTeamLead(TeamLead*);

	void increaseSalaryBy(double amount);
	void decreaseSalaryBy(double amount);

	void sendLeavingRequest();
	void sendPromotionRequest(double amount);
};

