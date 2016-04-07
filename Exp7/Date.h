#pragma once

#include <stdexcept>
#include <iostream>

class Date
{

public:
	Date();
	Date(int year, int month, int day);

	enum Month
	{
		Jan = 1,
		Feb,
		Mar,
		Apr,
		May,
		Jun,
		Jul,
		Aug,
		Sep,
		Oct,
		Nov,
		Dec
	};


	Date& increment();
	friend std::istream& operator>> (std::istream& in, Date& d);
	friend std::ostream& operator<< (std::ostream& out, const Date& d);
private:
	int year;
	Month month;
	int day;
	static bool isLeapYear(int year);
	static int DayPerMonth(Month m, bool isLeap = false);
	friend const Month& operator++(Month &rs)
	{
		return rs = static_cast<Month>((rs + 1) % sizeof(Month));
	}
	friend std::istream& operator >> (std::istream& in, Month &rs)
	{
		int m; in >> m;
		rs = static_cast<Month>((m) % sizeof(Month));
		return in;
	}
};

