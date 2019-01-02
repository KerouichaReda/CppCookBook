#include<iostream>
#include<vector>
#include<string>

using namespace std;
int main(void)
{
	vector<int> intVect;
	vector<string> strVect;
	string s;

	intVect.push_back(1);
	intVect.push_back(5);
	intVect.push_back(6);

	s = "sasha";
	strVect.push_back(s);
	s = "reda";
	strVect.push_back(s);
	s = "steven";
	strVect.push_back(s);

	for (vector<int>::size_type i = 0; i < intVect.size(); ++i)
	{
		cout << "intVec[" << i << "] = " << intVect[i] << '\n';
	}

	for (vector<string>::iterator p = strVect.begin(); p < strVect.end(); p++)
	{
		cout << *p << endl;
	}
	try
	{
		intVect.at(300) = 2;
	}
	catch (out_of_range& e)
	{
		cerr << "Out of range " << e.what() << endl;
	}
	getchar();
	return 0;
}