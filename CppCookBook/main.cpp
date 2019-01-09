#include<iostream>
#include<map>
#include<string>
#include"vectorTkit.h"


int main(void)
{
	std::map < std::string, std::string > strMap;
	strMap["Monday"] = "Montag";
	strMap["Tuesday"] = "Dienstag";
	strMap["Wednesday"] = "Mittwoch";
	strMap["Thursday"] = "Donnerstag";
	strMap["Friday"] = "Freitag";
	strMap["Saturday"] = "Samstag";
	strMap.insert(std::pair< std::string, std::string>("Sunday", "Sonntag"));

	for (std::map<std::string,std::string>::iterator p = strMap.begin(); p !=strMap.end(); p++)
	{
		std::cout << "English: " << p->first << " German: " << p->second << std::endl;
	}
	std::cout << std::endl;

	//strMap.erase("Thursday");
	strMap.erase(strMap.find("Thursday"));

	for (std::map<std::string, std::string>::iterator p = strMap.begin(); p != strMap.end(); p++)
	{
		std::cout << "English: " << p->first << " German: " << p->second << std::endl;
	}
	getchar();
	return 0;
}