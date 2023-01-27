/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Elisaveta Georgieva
* @idnumber 62591
* @task 1
* @compiler VC
*/

#include "Date.hpp"
#include <iostream>

Date::Date()
{
	this->day = 1;
	this->month = 1;
	this->year = 2000;
}

Date::Date(const int& d, const int& m, const int& y)
{
	day = d;
	month = m;
	year = y;
}

bool Date::Validation() const
{
	if (this->day < 0 || this->month < 0 || this->year < 0 || this->day > DaysInThisMonth(this->month))
	{
		std::cout << "Invalid date!\n";
		return false;
	}
	return true;
}

int Date::DaysInThisMonth(const int & m) const
{
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return 31;
	if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
	if (isLeapYear()) return 29;
	return 28;
}

void Date::addDays(const int & n)
{
	if (!(this->Validation())) return;
	if ((this->day + n) >= DaysInThisMonth(this->month))
	{
		this->day = this->day + n - DaysInThisMonth(this->month);
		this->month++;
		if (month == 13)
		{
			this->month = 1;
			this->year++;
		}
	}
	else
		this->day += n;
}

void Date::removeDays(const int & n)
{
	if (!(this->Validation())) return;
	if (this->day <= n)
	{
		this->month--;
		if (month == 0)
		{
			this->month = 12;
			this->year--;
		}
		this->day = DaysInThisMonth(this->month) - (n - this->day);
	}
	else
		this->day -= n;
}

bool Date::isLeapYear() const
{
	if (this->year % 100==0) return this->year % 400 == 0;
	return this->year % 4 == 0;
}

int Date::DaysToXmas() const
{
	if (!(this->Validation())) return -1;
	Date xmas(25, 12, this->year);
	if (this->month == 12 && this->day > 25)
	{
		xmas.year++;
	}
	return this->DaysTo(xmas);
}

int Date::DaysToNewYear() const
{
	if (!(this->Validation())) return -1;
	Date newYear(1, 1, this->year + 1);
	return this->DaysTo(newYear);
}

int Date::DaysTo(const Date & event) const
{
	if (!(this->Validation())) return -1;
	if (!this->isLaterThen(event))
	{
		std::cout << "The event is over!";
		return 0;
	}
	int days = 0;
	Date current(this->day, this->month, this->year);
	if (current.month == event.month && current.day > event.day)
	{
		if (current.isLeapYear()) return 366 - (current.day - event.day);
		else return 365 - (current.day - event.day);
	}
	while (current.month != event.month)
	{
		days += current.DaysInThisMonth(current.month);
		current.month++;
		if (current.month == 13)
		{
			current.month = 1;
			current.year++;
		}
	}
	days += (event.day - this->day);
	while (current.year < event.year)
	{
		current.year++;
		if (current.isLeapYear()) days += 366;
		else
			days += 365;
	}
	return days;
}

bool Date::isLaterThen(const Date & date) const
{
	if (!(this->Validation())) return false;
	if (date.year == this->year)
	{
		if (date.month == this->month)
		{
			return date.day > this->day;
		}
		return date.month > this->month;
	}
	return date.year > this->year;
}
