#include "Date.h"


Date::Date():year(0),month(static_cast<Month>(1)),day(1){}
Date::Date(int year,int month,int day):year(year),month(static_cast<Month>(month)),day(day)
{
	if(day>DayPerMonth(this->month)) {
		throw std::out_of_range("Input error");
	}
}

bool Date::isLeapYear(int year)
{
	if (!(year % 400))return true;
	if (!(year % 100))return false;
	if (!(year % 4))return true;
	return false;
}

int Date::DayPerMonth(Month m, bool isLeap)
{
	switch (m) {
	case Jan:return 31;
	case Feb:if(isLeap)return 29;else return 28;
	case Mar:return 31;
	case Apr:return 30;
	case May:return 31;
	case Jun:return 30;
	case Jul:return 31;
	case Aug:return 31;
	case Sep:return 30;
	case Oct:return 31;
	case Nov:return 30;
	case Dec:return 31;
	default:throw std::out_of_range("Input error");
	}
}

Date& Date::increment()
{
	++day;
	if(day>DayPerMonth(month,isLeapYear(year))) {
		++month; day = 1;
		if(month==Jan) {
			++year;
		}
	}
	return *this;
}
std::istream& operator>> (std::istream& in, Date& d) {
	in >> d.year >> d.month >> d.day;
	return in;
}
std::ostream& operator<< (std::ostream& out,const Date& d) {
	out<<  d.year <<" "<< d.month <<" "<< d.day;
	return out;
}
