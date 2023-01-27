#pragma once
#include <string>
class Card
{
protected:
	std::string name;
	int number;
	int num_image;
public:
	Card() = default;
	Card(const std::string&, const int, const int);
	void set_name(const std::string&);
	void set_num(const int);
	void set_numIm(const int);
	std::string get_name() const;
	int get_number() const;
	int get_num_image() const;
	virtual void print() const;
	virtual ~Card() {}
};

