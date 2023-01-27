#pragma once
#include <string>
class Error {
	std::string message;
public:
	Error(const std::string& message = "");

	std::string get_message() const;

	void SetMessage(const std::string&);
};