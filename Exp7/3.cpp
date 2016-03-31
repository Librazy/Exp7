#include <algorithm>
#include <iostream>
#include <exception>

class Time
{
private:
	int secondFromZero;
public:
	Time()
	{
		secondFromZero = 0;
	}
	Time(int t)
	{
		secondFromZero = t;
	}
	Time(int day, int hour,int minute,int second)
	{
		if (day < 0 || hour < 0 || minute < 0 || second < 0 || hour >= 24 || minute >= 60 || second >= 60) {
			throw std::out_of_range("Input error");
		}
		secondFromZero = day * 86400 + hour * 3600 + minute * 60 + second;
	}
	Time(const Time& t)
	{
		secondFromZero = t.secondFromZero;
	}
	int dayTotal() const
	{
		return secondFromZero / 86400;
	}
	int hourTotal() const
	{
		return secondFromZero / 3600;
	}
	int minuteTotal() const
	{
		return secondFromZero / 60;
	}
	int secondTotal() const
	{
		return secondFromZero;
	}
	int day() const
	{
		return dayTotal();
	}
	int hour() const
	{
		return hourTotal() % 24;
	}
	int minute() const
	{
		return minuteTotal() % 60 ;
	}
	int second() const
	{
		return secondFromZero % 60;
	}
	bool operator==(const Time& T) const{
		return secondFromZero == T.secondFromZero;
	}
	bool operator>=(const Time& T) const {
		return secondFromZero >= T.secondFromZero;
	}
	bool operator<=(const Time& T) const {
		return secondFromZero <= T.secondFromZero;
	}
	bool operator<(const Time& T) const {
		return secondFromZero < T.secondFromZero;
	}
	bool operator>(const Time& T) const {
		return secondFromZero > T.secondFromZero;
	}
	bool operator!=(const Time& T) const {
		return secondFromZero != T.secondFromZero;
	}
	Time& operator+=(const Time& T) &{
		secondFromZero += T.secondFromZero;
		return *this;
	}
	Time& operator+=(const int t) &{
		secondFromZero += t;
		return *this;
	}
	Time& operator-=(const Time& T) &{
		secondFromZero -= T.secondFromZero;
		return *this;
	}
	Time& operator-=(const int t) &{
		secondFromZero -= t;
		return *this;
	}
	Time& operator++() &{
		++secondFromZero;
		return *this;
	}
	Time& operator--() &{
		--secondFromZero;
		return *this;
	}
	Time& operator++(const int t) &{
		Time rst(*this);
		++secondFromZero;
		return rst;
	}
	Time& operator--(const int t) &{
		Time rst(*this);
		--secondFromZero;
		return rst;
	}
	Time& operator++(const int t) &&{
		return *this;
	}
	Time& operator--(const int t) &&{
		return *this;
	}
	Time operator-(const int t) && {
		secondFromZero -= t;
		return *this;
	}
	Time operator-(const Time& T) && {
		secondFromZero -= T.secondFromZero;
		return *this;
	}
	Time operator-(const int t)const & {
		Time rst(*this);
		rst.secondFromZero -= t;
		return std::move(rst);
	}
	Time operator-(const Time& T)const & {
		Time rst(*this);
		rst.secondFromZero -= T.secondFromZero;
		return std::move(rst);
	}

	friend std::istream& operator>>(std::istream& in,Time& T) {
		int day, hour, minute, second;
		in >> day >> hour >> minute >> second;
		if(day<0||hour<0||minute<0||second<0||hour>=24||minute>=60||second>=60) {
			throw std::out_of_range("Input error");
		}
		T.secondFromZero = day * 86400 + hour * 3600 + minute * 60 + second;
		return in;
	}
	friend std::ostream& operator<< (std::ostream& out, Time& T) {
		std::cout << T.day() << " ";
		std::cout << T.hour() << ":";
		std::cout << T.minute() << ":";
		std::cout << T.second() ;
		return out;
	}
};
