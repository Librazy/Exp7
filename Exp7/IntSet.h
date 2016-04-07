#pragma once

#include <set>
#include <algorithm>
#include <iostream>

class IntSet
{
std::set<int> iset;
public:
	IntSet();
	IntSet(const IntSet& s);
	~IntSet();
	bool is_empty() const; //判断是否为空集。
	int size() const; //获取元素个数。
	bool is_element(int e) const; //判断e是否属于集合。
	bool is_subset(const IntSet& s) const; //判断s是否包含于集合。
	bool is_equal(const IntSet& s) const; //判断集合是否相等。
	void display() const; //显示集合中的所有元素。
	IntSet& insert(int e); //将e加入到集合中。
	IntSet& remove(int e); //把e从集合中删除。
	IntSet union2(const IntSet& s) const; //计算集合的并集。
	IntSet intersection2(const IntSet& s) const; //计算集合的交集。
	IntSet difference2(const IntSet& s) const; //计算集合的差。
};

