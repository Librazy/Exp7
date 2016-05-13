#include "Stack.h"

int Stack::pop()
{
	int ret;
	remove(ret, length() - 1);
	return ret;
}

bool Stack::push(const int val)
{
	return insert(val, length());
}
