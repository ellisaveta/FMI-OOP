#pragma once

#include <iostream>

enum Party
{
	PARTY1 = 0,
	PARTY2 = 1,
	PARTY3 = 2,
};

class SectionVotes
{
	int party1Votes;
	int party2Votes;
	int party3Votes;

public:
	SectionVotes();

	SectionVotes(int party1Votes, int party2Votes, int party3Votes);

	int votesForParty(Party) const;

	void SetVotesForParty(const Party&, const int&);

	friend std::ostream& operator<<(std::ostream&, const SectionVotes&);

	friend std::istream& operator>>(std::istream&, SectionVotes&);
};
