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
	bool is_empty() const; //�ж��Ƿ�Ϊ�ռ���
	int size() const; //��ȡԪ�ظ�����
	bool is_element(int e) const; //�ж�e�Ƿ����ڼ��ϡ�
	bool is_subset(const IntSet& s) const; //�ж�s�Ƿ�����ڼ��ϡ�
	bool is_equal(const IntSet& s) const; //�жϼ����Ƿ���ȡ�
	void display() const; //��ʾ�����е�����Ԫ�ء�
	IntSet& insert(int e); //��e���뵽�����С�
	IntSet& remove(int e); //��e�Ӽ�����ɾ����
	IntSet union2(const IntSet& s) const; //���㼯�ϵĲ�����
	IntSet intersection2(const IntSet& s) const; //���㼯�ϵĽ�����
	IntSet difference2(const IntSet& s) const; //���㼯�ϵĲ
};

