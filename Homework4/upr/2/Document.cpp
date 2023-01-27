#include "Document.hpp"
#include <stdexcept>
#include <iostream>
#include <sstream>

Document::Document(const std::string & name, const std::string & location, const std::string & extension) :
	Object(name, location, extension), currLine(1) {}

bool Document::operator==(const Comparable * to_comp) const
{
	const Document* doc = dynamic_cast<const Document*>(to_comp);
	if (doc)
	{
		if (lines.size() != doc->lines.size())
		{
			return false;
		}
		for (int i = 0; i < lines.size(); ++i)
		{
			if (lines[i] != doc->lines[i])
			{
				return false;
			}
		}
		return true;
	}
	std::cerr << "Not equal types when ==\n";
	return false;
}

bool Document::operator!=(const Comparable * to_comp) const
{
	const Document* doc = dynamic_cast<const Document*>(to_comp);
	if (doc)
	{
		if (lines.size() != doc->lines.size())
		{
			return true;
		}
		for (int i = 0; i < lines.size(); ++i)
		{
			if (lines[i] != doc->lines[i])
			{
				return true;
			}
		}
		return false;
	}
	std::cerr << "Not equal types when ==\n";
	return true;
}

std::string Document::debug_print() const
{
	std::string str;
	for (int i = 0; i < lines.size(); ++i)
	{
		str += "Line ";
		std::stringstream ss;
		std::string temp;
		ss << (i + 1);
		ss >> temp;
		str += temp + ':' + lines[i] + '\n';
	}
	return str;
}

std::string Document::to_string() const
{
	std::string str = name + '\n' + location + '\n' + extension + '\n';
	for (int i = 0; i < lines.size(); ++i)
	{
		str += lines[i];
		str += '\n';
	}
	return str;
}

void Document::from_string(const std::string& str)
{
	lines.clear();
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
			this->location = str.substr(i, j-i);
			break;
		}
	}
	i = j + 1;
	for (j = i; j < str.length(); ++j)
	{
		if (str[j] == '\n')
		{
			this->extension = str.substr(i, j-i);
			break;
		}
	}
	i = j + 1;
	for (j = i; j < str.length(); ++j)
	{
		if (str[j] == '\n')
		{
			this->lines.push_back(str.substr(i, j-i));
			i = j + 1;
		}
	}
}

Object * Document::clone() const
{
	return new Document(*this);
}

void Document::write_line(const std::string & line)
{
	lines.push_back(line);
}

std::string Document::read_line()
{
//	try
//	{
		if (currLine > lines.size())
		{
			throw std::out_of_range("End of document!");
//			return "";
		}
		currLine++;
		return lines[currLine-2];
//	}
//	catch (const std::out_of_range& oor)
//	{
//		std::cerr << "Out of range error: " << oor.what() << "\n";
//	}
//	return "";
}

std::string Document::read_line(const unsigned line)
{
//	try
//	{
		if (line < 1 || line > lines.size())
		{
			throw std::out_of_range("Not correct index");
		}
		currLine = line;
		currLine++;
		return lines[currLine-2];
//	}
//	catch (std::out_of_range& oor)
//	{
//		std::cerr << "Out of range error: " << oor.what() << "\n";
//	}
//	return "";
}
