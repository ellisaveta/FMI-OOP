#include "ElectionResultsDatabase.hpp"

#include <iostream>
#include <fstream>

void ElectionResultsDatabase::addResultsFromFile(const char * filename)
{
	std::ifstream fi(filename);
	if (!fi.is_open())
	{
		std::cerr << "Problem with opening input file!\n";
		return;
	}
	SectionVotes s;
	while(fi >> s)
	{
		this->sections.push_back(s);
	}
	fi.close();
}

int ElectionResultsDatabase::numberOfSections() const
{
	return this->sections.size();
}

int ElectionResultsDatabase::votesForParty(Party party) const
{
	int votes = 0;
	for (int i = 0; i < sections.size(); ++i)
	{
		votes += sections[i].votesForParty(party);
	}
	return votes;
}

Party ElectionResultsDatabase::winningParty() const
{
	int votesFor1 = votesForParty(PARTY1);
	int votesFor2 = votesForParty(PARTY2);
	int votesFor3 = votesForParty(PARTY3);
	if (votesFor1 >= votesFor2)
	{
		if (votesFor1 >= votesFor3)
		{
			return Party::PARTY1;
		}
		return Party::PARTY3;
	}
	if (votesFor2 >= votesFor3)
	{
		return Party::PARTY2;
	}
	return Party::PARTY3;
}

std::ostream & operator<<(std::ostream & o, const ElectionResultsDatabase & db)
{
	for (int i = 0; i < db.numberOfSections(); ++i)
	{
		o << db.sections[i] << '\n';
	}
	return o;
}

std::istream & operator>>(std::istream & is, ElectionResultsDatabase & db)
{
	SectionVotes s;
	while (is >> s)
	{
		db.sections.push_back(s);
	}
	return is;
}
