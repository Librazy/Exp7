#pragma once
// Num.h -- _Int class definition
#ifndef _NUM_H_
#define _NUM_H_

#include <vector>

typedef long long LL;
typedef unsigned long long uLL;

class Num
{
private:
	int _sign;
	std::vector<int> _v;
	static const int WID = 4;
	static const int BASE = (int)1e4;
protected:
	Num(int sign, const std::vector<int> & v) : _sign(sign), _v(v) {}
	LL toBuildInTypeLL() const;
	int toBuildInTypeInt() const;
	friend int cmp(const Num &, const Num &);
	friend Num add(const Num &, const Num &);
	friend Num multiply(const Num &, const Num &);
	friend Num divise(const Num &, const Num &, Num &);
	void delzero();
public:
	// constructor methods
	Num() : _sign(0) { _v.push_back(0); }
	Num(const Num & o) : _sign(o._sign), _v(o._v) {}
	Num(const std::string &);
	Num(LL);
	// destructor method
	virtual ~Num() {}
	// conversions funtions
	operator bool() const { return _sign; }
	// overload operator methods
	Num & operator = (const Num & o) { _sign = o._sign; _v = o._v; return *this; }
	Num & operator = (const LL & o) { *this = Num(o); return *this; }
	Num & operator = (const std::string & o) { *this = Num(o); return *this; }
	Num operator + (const Num & o) const { return add(*this, o); }
	Num operator - (const Num & o) const { return add(*this, -o); }
	Num operator * (const Num & o) const { return multiply(*this, o); }
	Num operator / (const Num & o) const { Num m; return divise(*this, o, m); }
	Num operator % (const Num & o) const { Num m; divise(*this, o, m); return m; }
	Num operator + (const int & o) const { return *this + o; }
	Num operator - (const int & o) const { return *this - o; }
	Num operator * (const int & o) const { return *this * o; }
	Num operator / (const int & o) const { return *this / o; }
	Num operator % (const int & o) const { return *this % o; }
	Num & operator += (const Num & o) { *this = *this + o; return *this; }
	Num & operator -= (const Num & o) { *this = *this - o; return *this; }
	Num & operator *= (const Num & o) { *this = *this * o; return *this; }
	Num & operator /= (const Num & o) { *this = *this / o; return *this; }
	Num & operator %= (const Num & o) { *this = *this % o; return *this; }
	Num & operator ++() { return *this += 1; }
	Num & operator --() { return *this -= 1; }
	Num operator ++(int) { Num o = *this; ++*this; return o; }
	Num operator --(int) { Num o = *this; --*this; return o; }
	Num operator -() const { return Num(-1 * _sign, _v); }
	uLL toUnsignedLongLong() const;
	unsigned int toUnsignedInt() const;
	LL toLongLong() const;
	int toInt() const;
	// overload operator friends
	friend std::istream & operator >> (std::istream &, Num &);
	friend std::ostream & operator << (std::ostream &, const Num &);
	friend bool operator < (const Num & a, const Num & b) { return cmp(a, b) == 1; }
	friend bool operator > (const Num & a, const Num & b) { return cmp(a, b) == -1; }
	friend bool operator <= (const Num & a, const Num & b) { return cmp(a, b) != -1; }
	friend bool operator >= (const Num & a, const Num & b) { return cmp(a, b) != 1; }
	friend bool operator == (const Num & a, const Num & b) { return cmp(a, b) == 0; }
	friend bool operator != (const Num & a, const Num & b) { return cmp(a, b) != 0; }
	friend Num operator + (const int & a, const Num & b) { return a + b; }
	friend Num operator - (const int & a, const Num & b) { return a - b; }
	friend Num operator * (const int & a, const Num & b) { return a * b; }
	friend Num operator / (const int & a, const Num & b) { return a / b; }
	friend Num operator % (const int & a, const Num & b) { return a % b; }
};

#endif
