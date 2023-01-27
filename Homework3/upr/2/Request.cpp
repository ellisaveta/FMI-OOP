#include "Request.hpp"

unsigned Request::counter = 0;

Request::Request(const std::string & message, const std::string & sender) : message(message), sender(sender)
{
	counter += 1;
	this->ID = counter;
}

std::string Request::getMessage() const
{
	return this->message;
}

std::string Request::getSender() const
{
	return this->sender;
}

int Request::getCount() const
{
	return counter;
}

int Request::getID() const
{
	return this->ID;
}
