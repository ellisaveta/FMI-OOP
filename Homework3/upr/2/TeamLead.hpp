#pragma once
#include "Developer.hpp"
#include "LeavingRequest.hpp"
#include "PromotionRequest.hpp"
#include <vector>
#include <string>
class TeamLead : public Developer
{
	std::vector <Developer*> devs;
	std::vector <LeavingRequest> leavingReqs;
	std::vector <PromotionRequest> promReqs;

public:
	TeamLead(const std::string& name, double salary);

	std::vector <Developer*> getTeam() const;

	void addDeveloperToTeam(Developer* developer, double salary);
	void removeDeveloperFromTeam(const std::string& name);
	void removeDeveloperFromTeam(const unsigned&);


	void increaseTeamSalariesBy(double amount);
	void decreaseTeamSalariesBy(double amount);

	void addLeavingRequest(const LeavingRequest& leavingRequest);
	void addPromotionRequest(const PromotionRequest& promotionRequest);
	void fulfillLeavingRequests();
	void fulfillPromotionRequests();
};

