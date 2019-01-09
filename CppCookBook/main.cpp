#include<iostream>
#include<list>
#include<string>
#include<algorithm>
#include <functional>
#include"vectorTkit.h"

//printing function
template<typename T>
struct printer
{
	void operator()(const T& s)
	{
		std::cout << s << std::endl;
	}
};
bool inline even(int n)
{
	return(n % 2 == 0);
}
printer<std::string> strPrinter;
printer<int> intPrinter;

int main(void)
{
	std::list < std::string > lstOne;
	std::list < std::string > lstTwo;
	lstOne.push_back("Green");
	lstOne.push_back("Red");
	lstOne.push_back("Bleu");

	lstTwo.push_front("Cian");
	lstTwo.push_front("Magenta");
	lstTwo.push_front("Yellow");

	std::for_each(lstOne.begin(), lstOne.end(), strPrinter);
	
	lstOne.sort();
	lstTwo.sort();

	lstOne.merge(lstTwo);
	std::for_each(lstOne.begin(), lstOne.end(), strPrinter);

	std::list<int> intLst;
	for (int i = 0; i < 50; i++)
	{
		intLst.push_back(i);
	}

	std::for_each(intLst.begin(), intLst.end(), intPrinter);

	intLst.remove_if(std::bind2nd(std::greater<int>(), 25));
	std::for_each(intLst.begin(), intLst.end(), intPrinter);
	intLst.remove_if(even);
	std::for_each(intLst.begin(), intLst.end(), intPrinter);
	getchar();
	return 0;
}