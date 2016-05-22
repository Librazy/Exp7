#include <memory>
#include <iostream>
#include "Singleton.h"
#include "Date.h"
#include "IntSet.h"
#include "LinearList.h"
#include "Polynomial.h"
#include "Time.h"
#include "String.h"
#include <cassert>
#include <string>
#include <sstream>

#include "DateWithTime.h"
#include "ExtTime.h"
#include "Stack.h"
#include "Point.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "Templates.h"
#include "Student.h"
#include <map>
#include <locale>
#include <iterator>

int main()
{
	//++Singlethon
	{
		auto i = Singleton::get_instance();
		auto j = Singleton::get_instance();
		auto k = Singleton::get_instance();
		i->res = 9;
		assert(i->res == 9 && j->res == 9 && k->res == 9 && "Singleton test failed");
		j->res++;
		assert(i->res == 10 && j->res == 10 && k->res == 10 && "Singleton test failed");
	}
	//++End Singlethon
	//++LinearList
	{
		LinearList i;
		assert(i.insert(1, 0)&&"LinearList test failed");
		assert(i.insert(2, 0)&&"LinearList test failed");
		assert(i.insert(5, 0)&&"LinearList test failed");
		int x;
		assert(i.remove(x, 1)&&"LinearList test failed");
		assert(x == 2 && "LinearList test failed");
		assert(i.insert(2, 1) && "LinearList test failed");
		assert(i.element(2) == 1&&"LinearList test failed");
		assert(i.length() == 3&&"LinearList test failed");
		assert(i.search(5) == 0&&"LinearList test failed");
	}
	//++End LinearList
	//++Date
	{
		std::stringstream ss;
		Date i(1999, 12, 31);
		i.increment();
		ss << i << std::endl;
		Date j(2000, 2, 28);
		j.increment();
		ss << j << std::endl;
		assert(ss.str() == "2000 1 1\n2000 2 29\n" && "Date test failed");
	}
	//++End Date
	//++Time
	{
		Time t1(1,2,3);
		Time t2(2,2,3);
		assert(t2-t1==3600 && "Time test failed");
		Time t3(1, 5, 3);
		Time t4(2, 2, 3);
		assert(t4 > t3 && "Time test failed");
		Time t(1,1,1);
		t.set(0, 0, 0);
		t += 10;
		assert(t == Time(0,0,10) && "Time test failed");
	}
	//++End Time
	//++Polynominal
	{
		Polynomial p1,p2;
		std::string s1 = 
R"qwe(1 2 4 6 7
1 2 3 4 6
1 1
0 1
)qwe";
		std::stringstream ss1(s1);
		std::stringstream ss2;
		double ds[5]= { 1,2,4,6,7 };
		int is[5]= { 1,2,3,4,6 };
		Polynomial p(ds, is, 5);
		ss1 >> p1 >> p2;
		assert(p1 == p&&"Polynominal test failed");
		ss1.clear();
		ss2 << p2*p2 << std::endl;
		auto i = ss2.str();
		assert(i =="1^0 + 2^1 + 1^2\n"&&"Polynominal test failed");
	}
	//++End Polynominal
	//++IntSet
	{
		IntSet s1, s2;
		s1.insert(1).insert(6).insert(7).insert(9).insert(2);
		s2.insert(4).insert(6).insert(6).insert(8).insert(2).insert(5);
		assert(s1.size() == 5 && s2.size() == 5 && "IntSet test failed");
		assert(s1.intersection2(s2).size() == 2 && "IntSet test failed");
		IntSet s3 = s1.difference2(s2);
		IntSet s4 = s1.union2(s2);
		assert(s3.size() == 6 && s4.size() == 8 && "IntSet test failed");
		assert(s3.union2(s1.intersection2(s2)).is_equal(s1.union2(s2)) && "IntSet test failed");
	}
	//++End IntSet
	//++String
	{
		String s1("qwertyqwe1 6 9"),s2("qwert");
		assert(s1.is_substring(s2) && "String test failed");
		assert(s1.substring(1,3) == String("wer") && "String test failed");
		s1.remove_spaces();
		assert(s1 == String("qwertyqwe169") && "String test failed");
		
		assert(s1.find_replace_str("qwe", "eee")  == 2&& "String test failed");
		assert(s2.find_replace_str("qwe", "eeeee")  == 1&& "String test failed");
		assert(s1 == String("eeertyeee169") && "String test failed");
		assert(s2 == String("eeeeert") && "String test failed");
	}
	//++End String

	//++Start DateWithTime
	{
		DateWithTime t1(2016, 4, 16, 0, 0, 1);
		DateWithTime t2(2016, 4, 17, 0, 0, 0);
		assert(t2 - t1 == 86399 && "DateWithTime test failed");
		assert(t2 > t1 && "DateWithTime test failed");
		t1 = t1 + 10;
	}
	//++End DateWithTime
	//++Start ExtTime
	{
		ExtTime t1(0,1,0,0);
		ExtTime t2(0,0,0,5);
		assert(t1 - t2 == 3600*5+60 && "ExtTime test failed");
		t1.set(0, 2, 0, 0);
		assert(t1 - t2 == 3600*5+60*2 && "ExtTime test failed");
	}
	//++End ExtTime
	//++Start Stack
	{
		Stack s;
		assert(s.push(1) && "Stack test failed");
		assert(s.push(2) && "Stack test failed");
		assert(s.push(4) && "Stack test failed");
		assert(s.pop() == 4 && "Stack test failed");
		assert(s.pop() == 2 && "Stack test failed");
		assert(s.pop() == 1 && "Stack test failed");
	}
	//++End Stack

	//++Start Point
	{
		Point x(1,2);
		Circle c(1, 2, 3);
		Rectangle r(2, 3, 3, 5, 0);
		assert(c.area() == 3 * 3 * M_PI && "Point test failed");
		assert(r.area() == 3 * 5 && "Point test failed");
	}
	//++End Point

	//++Start Template_Select_Sort
	{
		int i[] = { 0,4,2,3,5,8,6,7,9,1 };
		double j[] = { 0,1,2,4,3,6,5,9,8,7 };
		int sorted_i[] = { 0,1,2,3,4,5,6,7,8,9 };
		double sorted_d[] = { 0,1,2,3,4,5,6,7,8,9 };
		template_select_sort(i, 10);
		template_select_sort(j, 10);
		assert(std::equal(i, i + 10, sorted_i));
		assert(std::equal(j, j + 10, sorted_d));
	}
	//++End Template_Select_Sort

	//++Start Template_Queue
	{
		template_queue<int> q;
		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);
		q.push(5);
		assert(q.pop() == 1);
		assert(q.pop() == 2);
		assert(q.pop() == 3);
		assert(q.pop() == 4);
		q.push(6);
		q.push(7);
		q.push(8);
		assert(q.pop() == 5);
		assert(q.pop() == 6);
		q.push(9);
		assert(q.pop() == 7);
		assert(q.pop() == 8);
		assert(q.pop() == 9);
	}
	//++End Template_queue

	//++Start Template_min
	{
		double a = 3, b = 4;
		assert(3 == template_min(a, b));
		int e = 5, f = 7;
		assert(5 == template_min(e, f));
	}
	//++End Template_min

	//++Start Template_Array
	{
		template_Array<int> arr(5);
		arr[0] = 10;
		arr[2] = 10;
		arr[1] = 5;
		arr[3] = -1;
		assert(!arr.has(3));
		assert(arr.has(5));
		arr.sum();
	}
	//++End Template_Array

	//++Start Template_Sorted_LinkedList
	{
		template_Sorted_LinkedList<double> list;
		list.insert(1.1);
		list.insert(3.3);
		list.insert(1.2);
		list.insert(1.0);
		assert(1.1 == list.at(1));
		assert(1.0 == list.at(0));
		assert(3.3 == list.at(3));
		list.remove(2);
		assert(3.3 == list.at(2));
		auto list2(list);
		auto list3 = list2;
		assert(3.3 == list2.at(2));
		list3.insert(2);
		assert(3.3 == list3.at(3));
	}
	//++End Template_Sorted_LinkedList

	//++Start Template_Quick_Sort
	{
		std::vector<int> i{ 0,4,2,3,5,8,6,7,9,1 };
		std::vector<double> j{ 0,1,2,4,3,6,5,9,8,7 };
		std::vector<int> sorted_i { 0,1,2,3,4,5,6,7,8,9 };
		std::vector<double> sorted_d { 0,1,2,3,4,5,6,7,8,9 };
		template_quick_sort<int>(i.begin(),i.end());
		template_quick_sort<double>(j.begin(), j.end());
		assert(i == sorted_i);
		assert(j == sorted_d);
	}
	//++End Template_Quick_Sort

	//++Start Student
	{
		std::vector<Student> students;
		std::string s1 =
			R"qwe(
2757 A 99 99 99 99 99 99 99 98 
2333 B 23 34 45 56 67 78 89 90
2456 C 66 66 66 66 66 66 66 66
2444 D 34 99 77 66 99 99 66 99
)qwe";
		std::string s2 =
			R"qwe(2757 A 99 99 99 99 99 99 99 98 
2444 D 34 99 77 66 99 99 66 99 
2456 C 66 66 66 66 66 66 66 66 
2333 B 23 34 45 56 67 78 89 90 
)qwe";
		std::stringstream ss1(s1);
		std::stringstream ss2;
	
		for (Student i; ss1 >> i; students.push_back(i));
		std::sort(students.begin(), students.end(), [](auto a, auto b) {return !(a < b); });
		for(Student& i:students) {
			ss2<< i << std::endl;
		}
		assert(ss2.str() == s2);
	}
	//++End Student

	//++Start nametable
	{
		std::map<std::string, int> nametable;
		nametable.insert(std::make_pair("A", 99));
		nametable.insert(std::make_pair("C", 96));
		nametable.insert(std::make_pair("B", 97));
		nametable.insert(std::make_pair("D", 77));
		std::string name="A";
		auto res = std::find_if(nametable.begin(), nametable.end(), [name](const auto& i)
		{
			return i.first == name;
		});
		assert(res->second == 99);
	}
	//++End nametable

	//++Start filtered_sum
	{
		std::vector<int> i{ 1,4,7,9,10,43,35,67 };
		auto res0 = std::for_each(i.begin(), i.end(), funtor_filtered_fold(10));
		auto res1 = std::for_each(i.begin(), i.end(), funtor_filtered_fold(10, -10));
		auto res2 = std::for_each(i.begin(), i.end(), funtor_filtered_fold(10, 0
			, std::equal_to<int>()));
		auto res3 = std::for_each(i.begin(), i.end(), funtor_filtered_fold(10, 0
			, std::equal_to<int>()
			, std::minus<int>()));
		auto res4 = std::for_each(i.begin(), i.end(), funtor_filtered_fold(10, 0
			, [](auto a, auto b) {return a <= b; }
			, std::minus<int>()));

		assert(res0.val == 43 + 35 + 67);
		assert(res1.val == 43 + 35 + 67 - 10);
		assert(res2.val == 10);
		assert(res3.val == -10);
		assert(res4.val == -(43 + 35 + 67 + 10));

	}
	//++End filtered_sum

	//++Start Reverse_Str
	{
		std::string str= "AlphaBet";
		std::string res;
		std::locale loc("English_United States.1251");
		std::transform(str.cbegin(), str.cend(),std::back_inserter(res), [&loc](char i)
		{
			if (std::isupper(i, loc)) {
				i = std::tolower(i, loc);
			}
			else if (std::islower(i, loc)) {
				i = std::toupper(i, loc);
			}
			return i;
		});
		std::reverse(res.begin(), res.end());
		assert(res == "TEbAHPLa");
	}
	//++End Reverse_Str

	//++Start Rot13
	{
		std::string str= "AlphaBet";
		std::string res;
		std::locale loc("English_United States.1251");
		std::transform(str.cbegin(), str.cend(),std::back_inserter(res), [&loc](char i)
		{
			if (std::isupper(i, loc)) {
				i += 13;
				if (i > 'Z')i -= 26;
			}
			else if (std::islower(i, loc)) {
				i += 13;
				if (i > 'z')i -= 26;
			}
			return static_cast<char>(i);
		});
		assert(res == "NycunOrg");
	}
	//++End Rot13
	return 0;
}
