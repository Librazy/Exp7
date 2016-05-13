// _Int.cpp -- _Int class methods
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include "Num.h"

#define SS std::stringstream

using std::ostream;
using std::istream;
using std::vector;
using std::string;

// constructor methods

Num::Num(LL num)
{
	if (!num) _sign = 0;
	else if (num > 0) _sign = 1;
	else
	{
		_sign = -1;
		num = -num;
	}
	if (num < 0) num = -num;
	do
	{
		_v.push_back(num % BASE);
		num /= BASE;
	} while (num);
}

Num::Num(const string & st)
{
	_v.clear();
	_sign = 1;
	int be = 0, en = st.size(), a;
	if (st[0] == '-')
	{
		be++;
		_sign = -1;
	}
	while ((en -= Num::WID) >= be)
	{
		SS ss(st.substr(en, Num::WID));
		ss >> a;
		_v.push_back(a);
	}
	if ((en += Num::WID) > be)
	{
		SS ss(st.substr(be, en - be));
		ss >> a;
		_v.push_back(a);
	}
	delzero();
}

// protected methods

LL Num::toBuildInTypeLL() const
{
	LL u = 0;
	for (int i = _v.size() - 1; i >= 0; i--)
	{
		u *= Num::BASE;
		u += _v[i];
	}
	return _sign == 1 ? u : -u;
}

int Num::toBuildInTypeInt() const
{
	int u = 0;
	for (int i = _v.size() - 1; i >= 0; i--)
	{
		u *= Num::BASE;
		u += _v[i];
	}
	return _sign == 1 ? u : -u;
}

int cmp(const Num & a, const Num & b)
{
	if (a._sign < b._sign) return 1;
	if (a._sign > b._sign) return -1;
	if (a._v == b._v) return 0;
	int mark = a._sign;
	if (a._v.size() < b._v.size())
		return mark == 1 ? 1 : -1;
	else if (a._v.size() > b._v.size())
		return mark == 1 ? -1 : 1;
	for (int i = a._v.size() - 1; i >= 0; i--)
		if (a._v[i] < b._v[i])
			return mark == 1 ? 1 : -1;
		else if (a._v[i] > b._v[i])
			return mark == 1 ? -1 : 1;
	return 0;
}

Num add(const Num & a, const Num & b)
{
	if (!a) return b;
	else if (!b) return a;
	else if (a._sign == b._sign)
	{
		Num c;
		c._v.clear();
		c._sign = a._sign;
		const vector<int> & va = a._v, &vb = b._v;
		for (int i = 0, bit = 0; i < va.size() || i < vb.size() || bit; i++)
		{
			int tot = bit;
			if (i < va.size()) tot += va[i];
			if (i < vb.size()) tot += vb[i];
			bit = tot / Num::BASE;
			c._v.push_back(tot - bit * Num::BASE);
		}
		return c;
	}
	else
	{
		const Num * plus, *minus;
		if (a._sign == 1) plus = &a, minus = &b;
		else plus = &b, minus = &a;
		Num c;
		if (*plus == static_cast<Num>(-*minus)) return Num(0);
		else if (*plus > static_cast<Num>(-*minus)) c._sign = 1;
		else
		{
			c._sign = -1;
			std::swap(plus, minus);
		}
		const vector<int> & va = plus->_v, &vb = minus->_v;
		vector<int> & vc = c._v;
		vc = va;
		for (int i = 0; i < vc.size(); i++)
		{
			if (i < vb.size()) vc[i] -= vb[i];
			if (vc[i] < 0)
			{
				vc[i] += Num::BASE;
				vc[i + 1]--;
			}
		}
		c.delzero();
		return c;
	}
}

Num multiply(const Num & a, const Num & b)
{
	if (!a || !b) return 0;
	Num c;
	c._sign = a._sign * b._sign;
	const vector<int> & va = a._v, &vb = b._v;
	vector<int> & vc = c._v;
	vc.resize(va.size() + vb.size());
	for (int i = 0; i < va.size(); i++)
		for (int j = 0; j < vb.size(); j++)
		{
			int p = i + j;
			vc[p] += va[i] * vb[j];
			int bit = vc[p] / Num::BASE;
			vc[p] -= bit * Num::BASE;
			vc[++p] += bit;
		}
	c.delzero();
	return c;
}

Num divise(const Num & a, const Num & b, Num & m)
{
	if (!a) return 0;
	if (!b) exit(1);
	Num c;
	c._sign = a._sign * b._sign;
	Num bb = b;
	if (b._sign == -1) bb = -bb;
	const vector<int> & va = a._v;
	vector<int> & vc = c._v;
	vc.resize(va.size());
	for (int i = va.size() - 1; i >= 0; i--)
	{
		m *= Num::BASE;
		m += va[i];
		Num x = 0;
		int j = 0;
		while ((x += bb) <= m) j++;
		m -= x -= bb;
		vc[i] = j;
	}
	c.delzero();
	return c;
}

void Num::delzero()
{
	while (_v.size() > 1 && _v[_v.size() - 1] == 0)
		_v.pop_back();
	if (_v.size() == 1 && _v[0] == 0) _sign = 0;
}

// conversions funtions

uLL Num::toUnsignedLongLong() const
{
	static const Num ULL = static_cast<Num>(LLONG_MAX) * 2 + 2;
	if (_sign == -1) exit(2);
	else if (_sign == 0) return 0;
	else return (*this % ULL).toBuildInTypeLL();
}

unsigned int Num::toUnsignedInt() const
{
	static const Num UINT = static_cast<Num>(UINT_MAX) + 1;
	if (_sign == -1) exit(2);
	else if (_sign == 0) return 0;
	else return (*this % UINT).toBuildInTypeInt();
}

LL Num::toLongLong() const
{
	static const Num ULL = static_cast<Num>(LLONG_MAX) * 2 + 2;
	static const Num LLMax = LLONG_MAX;
	static const Num LLMin = LLONG_MIN;
	if (_sign == 0) return 0;
	Num u = *this % ULL;
	if (u > LLMax) return (u - ULL).toBuildInTypeLL();
	if (u < LLMin) return (u + ULL).toBuildInTypeLL();
	return u.toBuildInTypeLL();
}

int Num::toInt() const
{
	static const Num UINT = static_cast<Num>(UINT_MAX) + 1;
	static const Num INTMax = INT_MAX;
	static const Num INTMin = INT_MIN;
	if (_sign == 0) return 0;
	Num u = *this % UINT;
	if (u > INTMax) return (u - UINT).toBuildInTypeInt();
	if (u < INTMin) return (u + UINT).toBuildInTypeInt();
	return u.toBuildInTypeInt();
}

// overload operator friends

istream & operator >> (istream & is, Num & x)
{
	string s;
	if (is >> s) x = s;
	return is;
}

ostream & operator << (ostream & os, const Num & x)
{
	using std::setw;
	using std::setfill;
	if (x._sign == -1) os << '-';
	os << x._v.back();
	for (int i = x._v.size() - 2; i >= 0; i--)
		os << setw(Num::WID) << setfill('0') << x._v[i];
	return os;
}
