#include "TestSuite.hpp"

TestSuite::TestSuite(std::string name)
{
	this->name = name;
}

void TestSuite::add(const TestCase & testC)
{
	testCases.push_back(testC);
}

std::vector<TestCase> TestSuite::filterPassing() const
{
	std::vector<TestCase> passing;
	int size = testCases.size();
	for (int i = 0; i < size; ++i)
	{
		if (testCases[i].isPassing())
		{
			passing.push_back(testCases[i]);
		}
	}
	return passing;
}

std::vector<TestCase> TestSuite::filterFailing() const
{
	std::vector<TestCase> failing;
	int size = testCases.size();
	for (int i = 0; i < size; ++i)
	{
		if (testCases[i].hasError())
		{
			failing.push_back(testCases[i]);
		}
	}
	return failing;
}

std::vector<TestCase> TestSuite::filterByErrorType(ErrorType erType) const
{
	std::vector<TestCase> filtered;
	int size = testCases.size();
	for (int i = 0; i < size; ++i)
	{
		if (testCases[i].getErrorType() == erType)
		{
			filtered.push_back(testCases[i]);
		}
	}
	return filtered;
}

void TestSuite::removeByErrorType(ErrorType erType)
{
	std::vector<TestCase> temp;
	size_t size = this->testCases.size();
	for (size_t i = 0; i < size; ++i)
	{
		if (testCases[i].getErrorType() != erType)
		{
			temp.push_back(testCases[i]);
		}
	}
	this->testCases.clear();
	size = temp.size();
	for (size_t i = 0; i < size; ++i)
	{
		this->testCases.push_back(temp[i]);
	}
	temp.empty();
}

std::string TestSuite::getName() const
{
	return this->name;
}

void TestSuite::setName(const std::string & n)
{
	this->name = n;
}
