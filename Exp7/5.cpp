#include "Polynomial.h"
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>

Polynomial::Polynomial()
{
	std::cout << "Polynomial()" << std::endl;
	poly.clear();
}
Polynomial::Polynomial(double coefs[], int exps[], int size)
{
	std::cout << "Polynomial(double coefs[], int exps[], int size)" << std::endl;
	poly.clear();
	for (int i = 0; i != size; ++i) {
		poly.push_back(nomial(coefs[i],exps[i]));
	}
	ord();
}
Polynomial::Polynomial(std::vector<double> c, std::vector<int> e)
{
	std::cout << "Polynomial(std::vector<double> c, std::vector<int> e)" << std::endl;
	poly.clear();
	for (int i = 0; i != std::size(c) && i != std::size(e); ++i) {
		poly.push_back(nomial(c[i], e[i]));
	}
	ord();
}
Polynomial::Polynomial(const Polynomial& p)
{
	std::cout << "Polynomial(const Polynomial& p)" << std::endl;
	poly = p.poly;
}
Polynomial::Polynomial(const Polynomial&& p)
{
	std::cout << "Polynomial(const Polynomial&& p)" << std::endl;
	*this = std::move(p);
}
Polynomial::~Polynomial()
{
	std::cout << "~Polynomial()" << std::endl;
	poly.clear();
}

void Polynomial::ord()
{
	std::cout << "ord" << std::endl;

	std::sort(poly.begin(), poly.end(), [](nomial a, nomial b)->bool {return a.second < b.second; });
	terms p;
	nomial cur = { 0,0 };
	for (auto i : poly) {
		if (i.first == 0)continue;
		if (cur.second == i.second) {
			cur.first += i.first;
		}
		else {
			if (i != poly.front())p.push_back(cur);
			cur.first = i.first;
			cur.second = i.second;
		}
	}p.push_back(cur);
	poly = p;
}
std::istream& operator>> (std::istream& in, Polynomial& t) {
	std::cout << "operator>>" << std::endl;
	std::string l1, l2;
	std::getline(in, l1);
	std::getline(in, l2);
	std::stringstream s1(l1);
	std::stringstream s2(l2);
	double c; int e;
	std::vector<double>cv;
	std::vector<int>ev;
	while(s1>>c&&s2>>e) {
		cv.push_back(c);
		ev.push_back(e);
	}
	t = Polynomial(cv, ev);
	return in;
}
std::ostream& operator << (std::ostream& out, const Polynomial& t) {
	std::cout << "operator<<&" << std::endl;
	out << t + Polynomial();
	return out;
}
std::ostream& operator << (std::ostream& out, Polynomial&& t) {
	std::cout << "operator<<&&" << std::endl;
	for(auto i:t.poly) {
		if(i==t.poly.front()) {
			out << i.first << "^" << i.second;
		}else {
			out <<" + "<< i.first << "^" << i.second;
		}
	}
	return out;
}
Polynomial& Polynomial::operator=(const Polynomial& p )
{
	std::cout << "operator=&" << std::endl;
	poly = p.poly;
	return *this;
}
Polynomial& Polynomial::operator=(const Polynomial&& p)
{
	std::cout << "operator=&&" << std::endl;
	poly = std::move(p.poly);
	return *this;
}
Polynomial Polynomial::operator*(const Polynomial& p) const &
{
	std::cout << "operator*" << std::endl;
	Polynomial q(*this);
	return q *= p;
}
Polynomial Polynomial::operator+(const Polynomial& p) const &
{
	std::cout << "operator+" << std::endl;
	Polynomial q(*this);
	return q += p;
}
Polynomial Polynomial::operator-(const Polynomial& p) const &
{
	std::cout << "operator-" << std::endl;
	Polynomial q(*this);
	return q -= p;
}
Polynomial Polynomial::operator*(const Polynomial& p) const &&
{
	std::cout << "operator*&&" << std::endl;
	Polynomial q(*this);
	return q *= p;
}
Polynomial Polynomial::operator+(const Polynomial& p) const &&
{
	std::cout << "operator+&&" << std::endl;
	//Polynomial q(std::forward<Polynomial>( * const_cast<Polynomial*>(this) ));
	Polynomial q(*this);
	return q += p;
}
Polynomial Polynomial::operator-(const Polynomial& p) const &&
{
	std::cout << "operator-&&" << std::endl;
	Polynomial q(*this);
	return q -= p;
}
bool Polynomial::operator==(const Polynomial& p) const
{
	std::cout << "operator==" << std::endl;
	if (std::size(p.poly) != std::size(poly)) { return false; }
	for (auto i = poly.begin(), j = p.poly.begin(); i != poly.cend() && j != p.poly.cend();) {
		if(i!=j) {
			return false;
		}
	}
	return true;
}
bool Polynomial::operator!=(const Polynomial& p) const
{
	std::cout << "operator!=" << std::endl;
	return !(*this == p);
}

Polynomial& Polynomial::operator+=(const Polynomial&p) &
{
	std::cout << "operator+=" << std::endl;
	terms rst;
	auto i = poly.begin();
	auto j = p.poly.begin();
	for (; i != poly.cend() && j != p.poly.cend();) {
		if (i->second < j->second) {
			rst.push_back(nomial(i->first, i->second));
			++i;
		}
		else if (i->second > j->second) {
			rst.push_back(nomial(j->first, j->second));
			++j;
		}
		else {
			rst.push_back(nomial(i->first + j->first, i->second));
			++i; ++j;
		}
	}
	for (; i != poly.cend();) {
		rst.push_back(nomial(i->first, i->second));
		++i;
	}
	for (; j != p.poly.cend();) {
		rst.push_back(nomial(j->first, j->second));
		++j;
	}
	poly = std::move(rst);
	ord();
	return *this;
}
Polynomial& Polynomial::operator-=(const Polynomial&p) &
{
	std::cout << "operator-=" << std::endl;
	terms rst;
	auto i = poly.begin();
	auto j = p.poly.begin();
	for (; i != poly.cend() && j != p.poly.cend();) {
		if (i->second < j->second) {
			rst.push_back(nomial(i->first, i->second));
			++i;
		}
		else if (i->second > j->second) {
			rst.push_back(nomial(-j->first, j->second));
			++j;
		}
		else {
			rst.push_back(nomial(i->first - j->first, i->second));
			++i; ++j;
		}
	}
	for (; i != poly.cend();) {
		rst.push_back(nomial(i->first, i->second));
		++i;
	}
	for (; j != p.poly.cend();) {
		rst.push_back(nomial(j->first, j->second));
		++j;
	}
	this->poly = std::move(rst);
	ord();
	return *this;

}
Polynomial& Polynomial::operator*=(const Polynomial&p) &
{
	std::cout << "operator*=" << std::endl;
	terms rst;
	for (auto i : poly) for (auto j : p.poly) {
		rst.push_back(nomial(i.first*j.first, i.second + j.second));
	}
	poly = std::move(rst);
	ord();
	return *this;
}
int Polynomial::degree() const
{
	return poly.back().second;
}
double Polynomial::evaluate(double x) const
{
	double val = 0;
	for (auto i:poly) {
		val += pow(i.first, i.second);
	}
	return val;
}

int main()
{

	Polynomial p,q,r;
	std::cin >> p >> q>> r;
	std::cout << p << std::endl;
	std::cout << p + q << std::endl;
	std::cout << p - q << std::endl;
	std::cout << p * q << std::endl;
	std::cout << (p *= q) << std::endl;
	std::cout << (p -= q) << std::endl;
	std::cout << p*q - q * r + r << std::endl;
	std::cout << p.evaluate(10) << std::endl;
	return 0;
}

