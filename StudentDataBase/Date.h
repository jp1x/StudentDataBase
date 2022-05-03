#pragma once
#include <Windows.h>
#include <iostream>

class Date
{
public:
	unsigned short day;
	unsigned short month;
	unsigned short year;

	tm Tm;
	time_t now = time(nullptr);
	errno_t err = localtime_s(&Tm, &now);

	Date()
	{
		day = 0;
		month = 0;
		year = 0;
	}

	Date(unsigned short _day, unsigned short _month, unsigned short _year)
	{
		day = _day;
		month = _month;
		year = _year;
	}

	static Date DefaultDate()
	{
		Date birthday(0, 0, 0);
		return birthday;
	}

	bool DateIsValid(Date date)
	{
		if (date.year > Tm.tm_year + 1900)
			return false;

		if (date.year == Tm.tm_year + 1900 && date.month > Tm.tm_mon + 1)
			return false;

		if (date.month == Tm.tm_mon + 1 && date.day > Tm.tm_mday)
			return false;

		short daysInMonth[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

		if (date.year < 1930)
			return false;

		if (date.year % 4 == 0)
			daysInMonth[2] = 29;

		if (date.month < 1 || date.month > 12)
			return false;

		if (date.day < 1 || date.day > daysInMonth[date.month])
			return false;

		return true;
	}

	Date operator = (const Date& other)
	{
		this->day = other.day;
		this->month = other.month;
		this->year = other.year;
		return *this;
	}

	bool operator == (const Date& other)
	{
		return this->day == other.day &&
			this->month == other.month &&
			this->year == other.year;
	}
};
