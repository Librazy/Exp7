#include <memory>
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

int main()
{
	//+Singlethon
	{
		auto i = Singleton::get_instance();
		auto j = Singleton::get_instance();
		auto k = Singleton::get_instance();
		i->res = 9;
		assert(i->res == 9 && j->res == 9 && k->res == 9 && "Singleton test failed");
		j->res++;
		assert(i->res == 10 && j->res == 10 && k->res == 10 && "Singleton test failed");
	}
	//+End Singlethon
	//+LinearList
	{
		LinearList i;
		assert(i.insert(1, 0)&&"LinearList test failed");
		assert(i.insert(2, 0)&&"LinearList test failed");
		assert(i.insert(5, 0)&&"LinearList test failed");
		assert(i.element(2) == 1&&"LinearList test failed");
		assert(i.length() == 3&&"LinearList test failed");
		assert(i.search(5) == 0&&"LinearList test failed");
	}
	//+End LinearList
	//+Date
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
	//+End Date
	//+Time
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
	//+End Time
	//+Polynominal
	{
		Polynomial p1,p2;
		std::string s1 = 
R"(1 2 4 6 7
1 2 3 4 6
1 1
0 1
)";
		std::stringstream ss1(s1),ss2;
		double ds[5]= { 1,2,4,6,7 };
		int is[5]= { 1,2,3,4,6 };
		Polynomial p(ds, is, 5);
		ss1 >> p1 >> p2;
		assert(p1 == p&&"Polynominal test failed");
		ss1.clear();
		
		ss2 << p2*p2 << std::endl;
		assert(ss2.str()=="1^0 + 2^1 + 1^2\n"&&"Polynominal test failed");
	}
	//+End Polynominal
	//+IntSet
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
	//+End IntSet
	//+String
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
	//+End String
	return 0;
}
