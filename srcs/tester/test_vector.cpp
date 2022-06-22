#if 1 //CREATE A REAL STL EXAMPLE
	#include <vector>
	namespace ft = std;
#else
	#include <vector.hpp>
#endif
#include "iostream"

void test_vector(){
		//constructors, iterators and begin, end fct
	ft::vector<int> v1();
	ft::vector<int> v2(5, 12);
	int tab[]={1,2,3,4,5};
	ft::vector<int> v3(tab, tab + 4);
	ft::vector<int> v4(v2);

	for (ft::vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		std::cout << *it << " - ";
	std::cout << std::endl;
	for (ft::vector<int>::iterator it = v2.begin(); it != v3.end(); it++)
		std::cout << *it << " - ";
	std::cout << std::endl;
	for (ft::vector<int>::iterator it = v2.begin(); it != v4.end(); it++)
		std::cout << *it << " - ";
	std::cout << std::endl;

}