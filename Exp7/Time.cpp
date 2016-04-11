#include "Time.h"


int Time::dayTotal() const
{
	return secondFromZero / 86400;
}

int Time::hourTotal() const
{
	return secondFromZero / 3600;
}

int Time::minuteTotal() const
{
	return secondFromZero / 60;
}

int Time::secondTotal() const
{
	return secondFromZero;
}

Time& Time::operator--(const int t) &&
{
	return *this;
}

Time& Time::operator--(const int t) &
{
	Time rst(*this);
	--secondFromZero;
	return rst;
}

Time& Time::operator--() &
{
	--secondFromZero;
	return *this;
}

Time& Time::operator-=(const int t) &
{
	secondFromZero -= t;
	return *this;
}

Time& Time::operator-=(const Time& T) &
{
	secondFromZero -= T.secondFromZero;
	return *this;
}

Time& Time::operator+=(const int t) &
{
	secondFromZero += t;
	return *this;
}

Time& Time::operator+=(const Time& T) &
{
	secondFromZero += T.secondFromZero;
	return *this;
}

bool Time::operator!=(const Time& T) const
{
	return secondFromZero != T.secondFromZero;
}

bool Time::operator>=(const Time& T) const
{
	return secondFromZero >= T.secondFromZero;
}

bool Time::operator==(const Time& T) const
{
	return secondFromZero == T.secondFromZero;
}

Time::Time(const Time& t)
{
	secondFromZero = t.secondFromZero;
}

Time::Time(int hour, int minute, int second)
{
	if (hour < 0 || minute < 0 || second < 0 || hour >= 24 || minute >= 60 || second >= 60) {
		throw std::out_of_range("Input error");
	}
	secondFromZero = hour * 3600 + minute * 60 + second;
}

Time::Time(int day, int hour, int minute, int second)
{
	if (day < 0 || hour < 0 || minute < 0 || second < 0 || hour >= 24 || minute >= 60 || second >= 60) {
		throw std::out_of_range("Input error");
	}
	secondFromZero = day * 86400 + hour * 3600 + minute * 60 + second;
}

Time::Time(int t)
{
	secondFromZero = t;
}

Time::Time()
{
	secondFromZero = 0;
}

Time& Time::set(int hour, int minute, int second)
{
	if (hour < 0 || minute < 0 || second < 0 || hour >= 24 || minute >= 60 || second >= 60) {
		throw std::out_of_range("Input error");
	}
	secondFromZero = hour * 3600 + minute * 60 + second;
	return *this;
}

Time& Time::increment()
{
	++secondFromZero;
	return *this;
}

int Time::day() const
{
	return dayTotal();
}

int Time::hour() const
{
	return hourTotal() % 24;
}

int Time::minute() const
{
	return minuteTotal() % 60;
}

int Time::second() const
{
	return secondFromZero % 60;
}

bool Time::operator<=(const Time& T) const
{
	return secondFromZero <= T.secondFromZero;
}

bool Time::operator<(const Time& T) const
{
	return secondFromZero < T.secondFromZero;
}

bool Time::operator>(const Time& T) const
{
	return secondFromZero > T.secondFromZero;
}

Time& Time::operator++(const int t) &&
{
	return *this;
}

Time& Time::operator++(const int t) &
{
	Time rst(*this);
	++secondFromZero;
	return rst;
}

Time& Time::operator++() &
{
	++secondFromZero;
	return *this;
}

int Time::operator-(const Time& T) const 
{
	return secondFromZero - T.secondFromZero;
}

int Time::operator-(const int t) const 
{
	return secondFromZero - t;
}

void Time::display() const
{
	std::cout << *this << std::endl;
}

bool Time::equal(Time &other_time) const
{
	return *this == other_time;
}

bool Time::less_than(Time &other_time) const
{
	return *this < other_time;
}
