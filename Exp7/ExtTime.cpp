#include "ExtTime.h"
ExtTime::ExtTime(int h, int m, int s, int tz) : Time(h, m, s), timezone(tz)
{}

ExtTime& ExtTime::set(int h, int m, int s, int tz)
{
	Time::set(h, m, s);
	timezone = tz;
	return *this;
}

int ExtTime::operator-(const ExtTime& a) const
{
	return static_cast<Time>(*this) - a - (timezone - a.timezone) * 3600;
}
