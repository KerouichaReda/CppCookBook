#include<iostream>
#include<vector>
#include<string>
#include"vectorTkit.h"

int main(void)
{
	std::string defString = "initialization";
	std::vector<std::string> vec(50, defString);
	vecPrint(vec);
	getchar();
	return 0;
}