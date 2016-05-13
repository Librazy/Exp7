#pragma once
#include "Time.h"
#include "Date.h"
class DateWithTime
{
public:
	DateWithTime(){}
	DateWithTime(int y,int m,int d,int h,int mm,int s):date(y,m,d),time(0,h,mm,s){}
	DateWithTime(const Date& date, int h, int mm, int s) :date(date), time(0, h, mm, s) {}
	DateWithTime(const Date& date, Time& time) :date(date), time(time) {}
	DateWithTime operator+(const int& i) const{
		Time tmp{time};
		tmp += i;
		return DateWithTime(date, tmp);
	}
	int operator-(const DateWithTime& i) const{
		return (date - i.date) * 86400 + (time - i.time);
	}
	bool operator>(const DateWithTime& i) const{
		if (date > i.date)  return true; 
		if (date < i.date)  return false;
		if (time > i.time)  return true;
		return false;
	}
	bool operator==(const DateWithTime& i) const {
		return date == i.date&&time == i.time;
	}
private:
	Date date;
	Time time;
};