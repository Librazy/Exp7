#pragma once

#include <stdexcept>
#include <iostream>

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
	Dec,
};
inline bool operator<(Month& a,Month &b){
	return static_cast<int>(a) < static_cast<int>(b);
}
inline bool operator>(Month& a,Month &b){
	return static_cast<int>(a) > static_cast<int>(b);
}
inline Month& operator++(Month& a) {
	int i = (a + 1) % 13;
	if (i==0)i = 1;
	return a = static_cast<Month>(i);
}
inline Month& operator++(Month& a, int i) {
	Month ret(a);
	++a;
	return ret;
}
inline std::istream& operator >> (std::istream& in, Month &rs)
{
	int m; in >> m;
	rs = static_cast<Month>((m) % sizeof(Month));
	return in;
}

class Date
{

public:
	Date();
	Date(int year, int month, int day);

	Date& increment();
	bool operator==(const Date& a) const{
		return (year==a.year)&&(month==a.month)&&(day==a.day);
	}
	bool operator<(const Date& a) const{
		if(year<a.year)return true;
		if(year>a.year)return false;
		if(month<a.month)return true;
		if(month>a.month)return false;
		if(day<a.day)return true;
		return false;
	}
	bool operator>(const Date& a) const{
		if (year > a.year)return true;
		if (year < a.year)return false;
		if (month > a.month)return true;
		if (month < a.month)return false;
		if (day > a.day)return true;
		return false;
	}
	int operator-(const Date& a) const{
		if(a==*this)return 0;
		if(*this<a){
			Date tmp{*this};
			int n=0;
			while(!(tmp==a)){
				tmp.increment();
			}
			return n;
		}
		Date tmp{a};
		int n=0;
		while(!(tmp==*this)){
			tmp.increment(); ++n;
		}
		return n;
	}
	friend std::istream& operator>> (std::istream& in, Date& d);
	friend std::ostream& operator<< (std::ostream& out, const Date& d);
private:
	int year;
	Month month;
	int day;
	static bool isLeapYear(int year);
	static int DayPerMonth(Month m, bool isLeap = false);

};

