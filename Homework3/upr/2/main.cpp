#include <iostream>
#include "Developer.hpp"
#include "TeamLead.hpp"
#include "Request.hpp"
#include "LeavingRequest.hpp"
#include "PromotionRequest.hpp"
using namespace std;
int main()
{
	Developer dev1("Ivan Petrov");
	dev1.getName();
	dev1.getSalary();
	dev1.getTeamLead();
	dev1.setInitialSalary(0);
	dev1.getSalary();
	Developer dev2("Petar");

	TeamLead t1("Georg Vasilev", 300);
	t1.addDeveloperToTeam(&dev1, 205);
	t1.getTeam();
	t1.getTeamLead();
	dev1.getTeamLead();
	dev1.getSalary();
	t1.increaseTeamSalariesBy(102);
	t1.decreaseTeamSalariesBy(37);
	t1.removeDeveloperFromTeam("Teias");
	t1.removeDeveloperFromTeam("Ivan Petrov");
	t1.getTeam();
	t1.getSalary();
	t1.addDeveloperToTeam(&dev2, 150);
	t1.addDeveloperToTeam(&dev1, 160);


	Request r1("Request1", "Ivan");
	Request r2("Request2", "Georg");
	r1.getMessage();
	r1.getCount();
	r2.getSender();
	r2.getID();
	LeavingRequest l1("Petar");
	l1.getCount();
	PromotionRequest p1("Ivan Petrov", 400);
	l1.getCount();
	l1.getID();
	p1.getMessage();
	p1.getID();
	t1.addLeavingRequest(l1);
	t1.addPromotionRequest(p1);
	t1.fulfillPromotionRequests();
	t1.fulfillLeavingRequests();
	dev1.sendPromotionRequest(260);
	dev1.sendLeavingRequest();
	dev2.sendLeavingRequest();
	return 0;
}