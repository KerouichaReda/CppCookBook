#include<iostream>
#include<string>
#include<unordered_set>
#include"vectorTkit.h"


int main(void)
{
	std::unordered_set<std::string> hsString;
	std::string s = "Bravo";
	hsString.insert(s);
	
	s = "Alpha";
	hsString.insert(s);

	s = "Charlie";
	hsString.insert(s);
	for (std::unordered_set<std::string>::const_iterator p = hsString.begin(); p !=hsString.end(); p++)
	{
		std::cout << *p << std::endl;
	}
	getchar();
	return 0;
}