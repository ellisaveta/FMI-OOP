#include "Error.hpp"

Error::Error(const std::string & message)
{
	this->message = message;
}

std::string Error::get_message() const
{
	return this->message;
}

void Error::SetMessage(const std::string & m)
{
	this->message = m;
}
