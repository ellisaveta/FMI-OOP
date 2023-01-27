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

#pragma once

class Date
{
	int day;
	int month;
	int year;

	int DaysInThisMonth(const int&) const;
	bool Validation() const;
public:
	Date();
	Date(const int&, const int&, const int&);
	void addDays(const int&);
	void removeDays(const int&);
	bool isLeapYear() const;
	int DaysToXmas() const;
	int DaysToNewYear() const;
	int DaysTo(const Date&) const;
	bool isLaterThen(const Date&) const;
};