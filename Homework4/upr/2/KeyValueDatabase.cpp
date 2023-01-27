#include "KeyValueDatabase.hpp"
#include <stdexcept>
#include <iostream>
#include <sstream>

KeyValueDatabase::KeyValueDatabase(const std::string & name, const std::string & location, const std::string & extension) :
	Object(name, location, extension) {}

void KeyValueDatabase::add_entry(const std::pair<std::string, int>& entry)
{
	for (int i = 0; i < data.size(); ++i)
	{
		if (data[i].first == entry.first)
		{
			throw std::invalid_argument("Entry key already exists in data!");
		}	
	}
	data.push_back(entry);
}

int KeyValueDatabase::get_value(const std::string & key) const
{
	for (int i = 0; i < data.size(); ++i)
	{
		if (data[i].first == key)
		{
			return data[i].second;
		}
	}
	throw std::invalid_argument("Key does not exist in data!");
}

bool KeyValueDatabase::operator==(const Comparable * to_comp) const
{
	const KeyValueDatabase* keyDB = dynamic_cast<const KeyValueDatabase*>(to_comp);
	if (keyDB)
	{
		if (data.size() != keyDB->data.size())
		{
			return false;
		}
		for (int i = 0; i < data.size(); ++i)
		{
			if (data[i].first != keyDB->data[i].first || data[i].second != keyDB->data[i].second)
			{
				return false;
			}
		}
		return true;
	}
	std::cerr << "Not equal types when ==\n";
	return false;
}

bool KeyValueDatabase::operator!=(const Comparable * to_comp) const
{
	const KeyValueDatabase* keyDB = dynamic_cast<const KeyValueDatabase*>(to_comp);
	if (keyDB)
	{
		if (data.size() != keyDB->data.size())
		{
			return true;
		}
		for (int i = 0; i < data.size(); ++i)
		{
			if (data[i].first != keyDB->data[i].first || data[i].second != keyDB->data[i].second)
			{
				return true;
			}
		}
		return false;
	}
	std::cerr << "Not equal types when ==\n";
	return true;
}

std::string KeyValueDatabase::debug_print() const
{
	std::string str;
	for (int i = 0; i < data.size(); ++i)
	{
		str += '{' + data[i].first + ':';
		std::stringstream ss;
		std::string temp;
		ss << data[i].second;
		ss >> temp;
		str += temp + "}\n";
	}
	return str;
}

std::string KeyValueDatabase::to_string() const
{
	std::string str = name + '\n' + location + '\n' + extension + '\n';
	for (int i = 0; i < data.size(); ++i)
	{
		str += data[i].first + ':';
		std::stringstream ss;
		ss << data[i].second;
		std::string temp;
		ss >> temp;
		str += temp + '\n';
	}
	return str;
}

void KeyValueDatabase::from_string(const std::string& str)
{
	data.clear();
	int i = 0;
	int j = 0;
	for (i = 0; i < str.length(); ++i)
	{
		if (str[i] == '\n')
		{
			this->name = str.substr(0, i);
			break;
		}
	}
	++i;
	for (j = i; j < str.length(); ++j)
	{
		if (str[j] == '\n')
		{
			this->location = str.substr(i, j - i);
			break;
		}
	}
	i = j + 1;
	for (j = i; j < str.length(); ++j)
	{
		if (str[j] == '\n')
		{
			this->extension = str.substr(i, j - i);
			break;
		}
	}
	i = j + 1;
	for (j = i; j < str.length(); ++j)
	{
		if (str[j] == '\n')
		{
			std::string line = str.substr(i, j - i);
			for (int p = 0; p < line.length(); ++p)
			{
				if (line[p] == ':')
				{
					std::pair<std::string, int> temp;
					temp.first = line.substr(0, p);
					std::stringstream ss(line.substr(p + 1));
					int x = 0;
					ss >> x;
					temp.second = x;
					this->data.push_back(temp);
					break;
				}
			}
			i = j + 1;
		}
	}
}

Object * KeyValueDatabase::clone() const
{
	return new KeyValueDatabase(*this);
}
