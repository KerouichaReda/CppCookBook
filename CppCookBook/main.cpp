#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include"vectorTkit.h"

int main(void)
{
	std::vector<std::string> vec(5);
	std::string fool[] = { "My","way","or","the","highway" };
		vec[0] = "Today";
		vec[1] = "is ";
		vec[2] = "a";
		vec[3] = "new";
		vec[4] = "day";

		std::vector<std::string> vec2(vec);
		vecPrint(vec2);

		vec.at(0) = "Tommorow";

		vec2.assign(vec.begin(), vec.end());
		vecPrint(vec2);

		std::vector<std::string>::iterator p;
		p = std::find(vec.begin(), vec.end(), "end");
		vec2.assign(vec.begin(), p);

	getchar();
	return 0;
}