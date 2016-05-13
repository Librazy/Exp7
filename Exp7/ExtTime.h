#pragma once
#include "Time.h"

class ExtTime:protected Time
{
	int timezone;
public:
	ExtTime(int h, int m, int s, int tz);

	ExtTime& set(int h, int m, int s, int tz);

	int operator-(const ExtTime& a) const;
};
