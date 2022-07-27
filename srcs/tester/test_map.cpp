#if 1 //1 = original 0 = perso
	# include <map>
	namespace ft = std;
#else
	# include <map.hpp>
#endif
#include <iostream>

void test_map(){
	ft::map<char, int> m1;

	m1['a'] = 1;
	m1['b'] = 2;
	m1['c'] = 3;
	m1['d'] = 4;

	ft::map<char, int> m2;
	m2 = m1;

	std::cout << "a = " << m2['a'] << std::endl;
	std::cout << "b = " << m2['b'] << std::endl;
	std::cout << "c = " << m2['c'] << std::endl;
	std::cout << "d = " << m2['d'] << std::endl;

	
}