#pragma once

#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>

class String
{
	std::string str;
public:
	explicit String(const std::string s):str(s){}

	explicit String(const char* s):str(s){}
	explicit String():str(""){}
	bool operator==(const String& rhs) const;
	bool is_substring(const char* sub_str) const;
	bool is_substring(const String& sub_str) const;
	String substring(int start, int len) const;
	int find_replace_str(const char* find_str, const char* replace_str);
	void remove_spaces();
	int to_int();
	void to_lower_case();
};

