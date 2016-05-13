#pragma once
#include "LinearList.h"

class Stack:private LinearList
{
public:

	int pop();

	bool push(const int val);
};
