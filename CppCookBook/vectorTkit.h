#include<iostream>
#include<vector>
template<typename T>
void vecPrint(const std::vector<T>& vec) {
	std::cout << "{"<< std::endl;
	for (typename std::vector<T>::const_iterator p = vec.begin();
		p != vec.end(); ++p) {
		std::cout << "{" << *p << "} "<<std::endl;
	}
	std::cout << "}" << std::endl;
}