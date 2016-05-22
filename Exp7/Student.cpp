#include "Student.h"
#include <iostream>

std::istream& operator>> (std::istream& in, Student& a)
{
	in >> a.id >> a.name;
	for (int i = 0; i != 8; ++i) {
		in >> a.score[i];
	}
	return in;
}
std::ostream& operator<< (std::ostream& out, Student& a)
{
	out << a.id << " " << a.name << " ";
	for (int i = 0; i != 8;++i) {
		out << a.score[i] << " ";
	}
	return out;
}
bool Student::operator<(const Student& b) const{
	return aver() < b.aver();
}
