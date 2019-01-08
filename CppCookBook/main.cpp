#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include"vectorTkit.h"

static const int NUM_OBJECTS = 10;
class MyClass
{
public:
	MyClass();
	~MyClass();

private:

};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}
int main(void)
{
	std::vector<MyClass*> vec;
	MyClass* p = NULL;
	for (int i = 0; i < NUM_OBJECTS; i++)
	{
		p = new MyClass();
		vec.push_back(p);
	}
	for (std::vector<MyClass*>::iterator pObj = vec.begin(); pObj != vec.end(); pObj++)
	{
		delete* pObj;
	}
	vec.clear();
	getchar();
	return 0;
}