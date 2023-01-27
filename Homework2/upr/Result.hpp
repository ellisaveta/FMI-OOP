#pragma once
#include <iostream>

#include "Error.hpp"
#include "Optional.hpp"

template<typename T>

class Result {
	Optional<T> result;
	Optional<Error> error;

public:
	Result();
	Result(const T &result);
	Result(const std::string &error_message);

	Optional<T> get_result() const;
	Optional<Error> get_error() const;

	bool operator==(const T&) const;
	bool operator==(const Error&) const;

	void setResult(const T&);
	void setError(const std::string&);
};

template<typename T>
inline Result<T>::Result()
{}

template<typename T>
inline Result<T>::Result(const T & result)
{
	Optional<T> opt(result);
	this->result = opt;
}

template<typename T>
inline Result<T>::Result(const std::string & error_message)
{
	Error er(error_message);
	Optional<Error> opt(er);
	this->error = opt;
}

template<typename T>
inline Optional<T> Result<T>::get_result() const
{
	if (this->result.is_none())
	{
		std::cout << "No result!\n";
	}
	return this->result;
}

template<typename T>
inline Optional<Error> Result<T>::get_error() const
{
	if (this->error.is_none())
	{
		std::cout << "No error message!\n";
	}
	return this->error;
}

template<typename T>
inline bool Result<T>::operator==(const T & obj) const
{
	return !this->result.is_none();
}

template<typename T>
inline bool Result<T>::operator==(const Error & er) const
{
	return !this->error.is_none();
}

template<typename T>
inline void Result<T>::setResult(const T & r)
{
	this->result.SetValue(r);
}

template<typename T>
inline void Result<T>::setError(const std::string & e)
{
	this->error.SetValue(e);
}
