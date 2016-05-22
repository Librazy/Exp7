#pragma once
#include <numeric>
#include <string>

struct Student
{

	std::string name;
	unsigned int id;
	unsigned int score[8];
	friend std::istream& operator >> (std::istream& in, Student& a);
	friend std::ostream& operator << (std::ostream& out, Student& a);
	bool operator<(const Student& b) const;
	unsigned int aver() const
	{
		return std::accumulate(score, score + 8, 0U) / 8;
	}
};
