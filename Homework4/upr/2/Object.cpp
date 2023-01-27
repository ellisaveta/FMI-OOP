#include "Object.hpp"

Object::Object(const std::string & name, const std::string & location, const std::string & extension) :
	name(name), location(location), extension(extension) {}

Object::~Object() {}


std::string Object::get_name() const
{
	return this->name;
}

std::string Object::get_location() const
{
	return this->location;
}

std::string Object::get_extension() const
{
	return this->extension;
}

std::string Object::get_fullpath() const
{
	std::string fullPath =  location + '/' + name + '.' + extension;
	return fullPath;
}
