#include "Error.hpp"
#include <cstring>

bool Error::hasMessage() const
{
	return this->message!=nullptr;
}

const char * Error::getMessage() const
{
	return this->message;
}

ErrorType Error::getType() const
{
	return this->type;
}

Error::Error(ErrorType t, const char * m)
{
	this->type = t;
	if (m != nullptr)
	{
		int size = strlen(m);
		this->message = new char[size + 1];
		strcpy_s(this->message, size + 1, m);
	}
	else
	{
		this->message = nullptr;
	}
}

Error::Error(const Error & copyFrom)
{
	if (copyFrom.getMessage() == nullptr)
	{
		this->message = nullptr;
	}
	else
	{
		int size = strlen(copyFrom.getMessage());
		this->message = new char[size + 1];
		strcpy_s(this->message, size + 1, copyFrom.getMessage());
	}
	this->type = copyFrom.getType();
}

Error::~Error()
{
	delete[] this->message;
}

Error Error::newNone()
{
	Error new_none;
	return new_none;
}

Error Error::newBuildFailed(const char * message)
{
	Error new_error(ErrorType::BuildFailed, message);
	return new_error;
}

Error Error::newWarning(const char * message)
{
	Error new_error(ErrorType::Warning, message);
	return new_error;
}

Error Error::newFailedAssertion(const char * message)
{
	Error new_error(ErrorType::FailedAssertion, message);
	return new_error;
}

Error & Error::operator=(const Error & er)
{
	if (this != &er)
	{
		delete[] message;
		if (er.getMessage() == nullptr)
		{
			this->message = nullptr;
		}
		else
		{
			int size = strlen(er.getMessage());
			this->message = new char[size + 1];
			strcpy_s(this->message, size + 1, er.getMessage());
		}
		this->type = er.getType();
	}
	return *this;
}
