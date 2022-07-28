#include <map>//
#if 0 //1 = original 0 = perso
	# include <map>
	namespace ft = std;
#else
	# include <map.hpp>
#endif
#include <iostream>

void test_map(){
	// ft::map<int, int> m1;
	std::map<int, int> tm;

		tm[1] = 1;
		tm[2] = 2;
		tm[3] = 3;
		tm[4] = 4;
		tm[5] = 5;
		tm[6] = 6;
		tm[7] = 7;

	ft::map<int, int> mm(tm.begin(), tm.end(), tm.key_comp());
	// m1['a'] = 1;
	// m1['b'] = 2;
	// m1['c'] = 3;
	// m1['d'] = 4;

	// ft::map<char, int> m2;
	// m2 = m1;

	// std::cout << "a = " << m2['a'] << std::endl;
	// std::cout << "b = " << m2['b'] << std::endl;
	// std::cout << "c = " << m2['c'] << std::endl;
	// std::cout << "d = " << m2['d'] << std::endl;
	
}