#include<iostream>
#include<string>
#include<set>
#include"vectorTkit.h"


int main(void)
{
	std::set<std::string> setStr;
	std::string s = "Bill";
	setStr.insert(s);
	s = "Steve";
	setStr.insert(s);
	s = "Randy";
	setStr.insert(s);
	s = "Howard";
	setStr.insert(s);

	for (std::set<std::string>::const_iterator p = setStr.begin(); p !=setStr.end(); p++)
	{
		std::cout << *p << std::endl;
	}
	getchar();
	return 0;
}