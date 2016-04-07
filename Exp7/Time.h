#pragma once

#include <algorithm>
#include <iostream>
#include <exception>

class Time
{
private:
	int secondFromZero;
	int dayTotal() const;

	int hourTotal() const;

	int minuteTotal() const;
	int secondTotal() const;
	int day() const;
	int hour() const;
	int minute() const;
	int second() const;
public:
	Time();
	Time(int t);
	Time(int day, int hour,int minute,int second);
	Time(int hour, int minute, int second);
	Time(const Time& t);
	Time& set(int hour, int minute, int second);
	Time& increment();

	bool operator==(const Time& T) const;
	bool operator>=(const Time& T) const;
	bool operator<=(const Time& T) const;
	bool operator<(const Time& T) const;
	bool operator>(const Time& T) const;
	bool operator!=(const Time& T) const;
	Time& operator+=(const Time& T) &;
	Time& operator+=(const int t) &;
	Time& operator-=(const Time& T) &;
	Time& operator-=(const int t) &;
	Time& operator++() &;
	Time& operator--() &;
	Time& operator++(const int t) &;
	Time& operator--(const int t) &;
	Time& operator++(const int t) &&;
	Time& operator--(const int t) &&;
	int operator-(const int t)const ;
	int operator-(const Time& T)const ;

	friend std::istream& operator>>(std::istream& in,Time& T) {
		int day, hour, minute, second;
		in >> day >> hour >> minute >> second;
		if(day<0||hour<0||minute<0||second<0||hour>=24||minute>=60||second>=60) {
			throw std::out_of_range("Input error");
		}
		T.secondFromZero = day * 86400 + hour * 3600 + minute * 60 + second;
		return in;
	}
	friend std::ostream& operator<< (std::ostream& out, const Time& T) {
		std::cout << T.day() << " ";
		std::cout << T.hour() << ":";
		std::cout << T.minute() << ":";
		std::cout << T.second() ;
		return out;
	}
	void display() const;
	bool equal(Time &other_time) const;
	bool less_than(Time &other_time) const;
};

