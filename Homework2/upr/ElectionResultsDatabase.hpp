#pragma once

#include "SectionVotes.hpp"

#include <vector>

class ElectionResultsDatabase
{
	
	std::vector<SectionVotes> sections;

public:

	void addResultsFromFile(const char* filename);

	int numberOfSections() const;

	int votesForParty(Party) const;

	Party winningParty() const;

	friend std::ostream& operator<<(std::ostream&, const ElectionResultsDatabase&);

	friend std::istream& operator>>(std::istream&, ElectionResultsDatabase&);
};