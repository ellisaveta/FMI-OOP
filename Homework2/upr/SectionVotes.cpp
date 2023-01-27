#include "SectionVotes.hpp"

#include <string>

SectionVotes::SectionVotes() : party1Votes(0), party2Votes(0), party3Votes(0) {}

SectionVotes::SectionVotes(int party1Votes, int party2Votes, int party3Votes) :
	party1Votes(party1Votes), party2Votes(party2Votes), party3Votes(party3Votes) {}

int SectionVotes::votesForParty(Party party) const
{
	if (party == PARTY1)
	{
		return this->party1Votes;
	}
	else if (party == PARTY2)
	{
		return this->party2Votes;
	}
	return this->party3Votes;
}

void SectionVotes::SetVotesForParty(const Party & party, const int & n)
{
	switch (party)
	{
	case PARTY1:
		this->party1Votes = n;
		break;
	case PARTY2:
		this->party2Votes = n;
		break;
	default:
		this->party3Votes = n;
		break;
	}
}

std::ostream & operator<<(std::ostream & o, const SectionVotes & section)
{
	return o << section.votesForParty(PARTY1) << ' ' << section.votesForParty(PARTY2) << ' ' << section.votesForParty(PARTY3);
}

std::istream & operator>>(std::istream & is, SectionVotes & section)
{
	int n;
	is >> n;
	section.SetVotesForParty(PARTY1, n);
	is >> n;
	section.SetVotesForParty(PARTY2, n);
	is >> n;
	section.SetVotesForParty(PARTY3, n);
	return is;
}
