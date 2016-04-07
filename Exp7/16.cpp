#include "LinearList.h"

bool LinearList::insert(int x, int pos)
{
	if(pos<0||pos>intv.size()) {
		return false;
	}else if(pos==intv.size()) {
		intv.push_back(x);
		return true;
	}
	auto i = intv.begin()+pos;
	intv.insert(i,x);
	return true;
}

bool LinearList::remove(int &x, int pos)
{
	if (pos < 0 || pos >= intv.size()) {
		return false;
	}
	auto i = intv.begin()+pos;
	x = *i;
	intv.erase(i);
	return false;
}

int LinearList::element(int pos) const
{
	auto i = intv.begin() + pos;
	return *i;
}

int LinearList::search(int x) const
{
	auto i = intv.begin();
	while(*i!=x) {
		++i;
	}
	return i-intv.begin();
}

int LinearList::length() const
{
	return intv.size();
}
