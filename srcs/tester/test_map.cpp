#if 0 //1 = original 0 = perso
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

}