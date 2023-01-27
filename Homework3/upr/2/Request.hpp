#pragma once
#include <string>
class Request
{
protected:
	std::string message;
	std::string sender;
	int ID;

public:
	static unsigned counter;

	Request(const std::string& message, const std::string& sender);

	std::string getMessage() const;
	std::string getSender() const;
	int getCount() const;
	int getID() const;
};

