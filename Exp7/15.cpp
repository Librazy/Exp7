#include "IntSet.h"


IntSet::IntSet()
{
	iset.clear();
}

IntSet::IntSet(const IntSet & s)
{
	iset = s.iset;
}
IntSet::~IntSet()
{
	iset.clear();
}

bool IntSet::is_empty() const
{
	return iset.empty();
}

int IntSet::size() const
{
	return iset.size();
}

bool IntSet::is_element(int e) const
{
	return iset.find(e) != iset.cend();
}

bool IntSet::is_subset(const IntSet & s) const
{
	for(int i:iset) {
		if (!is_element(i))return false;
	}
	return true;
}

bool IntSet::is_equal(const IntSet& s) const
{
	return is_subset(s) && s.is_subset(*this);
}

void IntSet::display() const
{
	std::for_each(iset.cbegin(), iset.cend(), [](int i) {std::cout << i << " ";  });
}

IntSet& IntSet::insert(int e)
{
	iset.emplace(e);
	return *this;
}

IntSet& IntSet::remove(int e)
{
	auto i=iset.find(e);
	if(i!=iset.cend()) {
		iset.erase(i);
	}
	return *this;
}

IntSet IntSet::union2(const IntSet& s) const
{
	IntSet res;
	std::for_each(iset.cbegin(), iset.cend(), [&res](int i) {res.insert(i); });
	std::for_each(s.iset.cbegin(), s.iset.cend(), [&res](int i) {res.insert(i); });
	return res;
}
IntSet IntSet::intersection2(const IntSet& s) const
{
	IntSet res;
	std::for_each(iset.cbegin(), iset.cend(), [&res,&s](int i) {if(s.is_element(i))res.insert(i); });
	return res;
}
IntSet IntSet::difference2(const IntSet& s) const
{
	IntSet res;
	std::for_each(iset.cbegin(), iset.cend(), [&res, &s](int i) {if (!s.is_element(i))res.insert(i); });
	std::for_each(s.iset.cbegin(), s.iset.cend(), [&res, this](int i) {if (!this->is_element(i))res.insert(i); });
	return res;
}