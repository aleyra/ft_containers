#include <map>//
#if 0 //1 = original 0 = perso
	# include <map>
	namespace ft = std;
#else
	# include <map.hpp>
#endif
#include <iostream>

void test_map(){
	std::cout << "\ttests constructeurs, operateur [], begin, end et keycomp()\n";
	{std::cout << "\t\tconstructeur par default et operateur []\n";
		ft::map<int, char> m1;
		m1[1] = 'a';
		m1[2] = 'b';
		m1[3] = 'c';
		m1[4] = 'd';

		std::cout << "m1[1] = " << m1[1] << std::endl;
		std::cout << "m1[2] = " << m1[2] << std::endl; 
		std::cout << "m1[3] = " << m1[3] << std::endl; 
		std::cout << "m1[4] = " << m1[4] << std::endl; 
	}

	// ft::map<char, int> m2;
	// m2 = m1;

	// std::cout << "a = " << m2['a'] << std::endl;
	// std::cout << "b = " << m2['b'] << std::endl;
	// std::cout << "c = " << m2['c'] << std::endl;
	// std::cout << "d = " << m2['d'] << std::endl;
	
}