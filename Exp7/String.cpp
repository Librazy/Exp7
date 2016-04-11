#include "String.h"

bool String::operator==(const String& rhs) const
{
	return rhs.str == str;
}

bool String::is_substring(const char* sub_str) const
{
	String str_is_or_not;
	str_is_or_not.str = sub_str;
	return(str.find(str_is_or_not.str, 0) != std::string::npos);
}

bool String::is_substring(const String& sub_str) const
{
	return(str.find(sub_str.str, 0) != std::string::npos);
}

String String::substring(int start, int len) const
{
	String str1;
	str1.str = (str.substr(start, len));
	return str1;
}

int String::find_replace_str(const char* find_str, const char* replace_str)
{
	int num = 0;
	int i;
	int len_find = strlen(find_str);
	int length = str.size();
	i = 0;
	while (i <= length - len_find)
	{
		int k = 0, j = i, temp = 0;
		while (str[j] == *(find_str + k) && k < len_find) { temp++; j++; k++; }
		if (temp == len_find)
		{
			num++;
			str = str.replace(i, len_find, replace_str);
			length = str.size();
			i += strlen(replace_str);
		}
		else i++;
	}
	return num;
}

void String::remove_spaces()
{
	for (int i = 0; str[i]; i++)
		while (str[i] == ' ')str.erase(i, 1);
}

int String::to_int()
{
	for (int i = 0; str[i]; i++)str[i] = str[i] - '0';
	int x = 0;
	for (int i = 0; str[i]; i++) { x = 10 * x + str[i]; }
	return x;
}

void String::to_lower_case()
{
	for (int i = 0; str[i]; i++)
		if ('A' <= str[i] && str[i] <= 'Z')str[i] += 32;
}