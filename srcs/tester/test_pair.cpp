#if 1 //1 = original 0 = perso
	# include <utility>
	namespace ft = std;
#else
	# include <pair.hpp>
	# include <make_pair.hpp>
#endif
#include <iostream>

void	display_pair_char_int(ft::pair<char, int> p){
	std::cout << "(" << p.first << ", " << p.second << ")" << std::endl;
}

void	display_pair_int_char(ft::pair<int, char> p){
	std::cout << "(" << p.first << ", " << p.second << ")" << std::endl;
}

void	test_pair(){
	ft::pair<char, int> p1('a', 1);
	ft::pair<char, int> p2(p1);
	ft::pair<char, int> p3;
	ft::pair<char, int> p4('b', 2);

	std::cout << "p1 = ";
	display_pair_char_int(p1);
	std::cout << "p2 = ";
	display_pair_char_int(p2);
	p3 = p2;
	std::cout << "p3 = ";
	display_pair_char_int(p3);

	p3 = ft::make_pair('a', 2);
	std::cout << "p3 = ";
	display_pair_char_int(p3);

	p2 = ft::make_pair(p4.first, p1.second);

	std::cout << "\np1 = ";
	display_pair_char_int(p1);
	std::cout << "p2 = ";
	display_pair_char_int(p2);
	std::cout << "p3 = ";
	display_pair_char_int(p3);
	std::cout << "p4 = ";
	display_pair_char_int(p4);

	std::cout << "\ttest de ==\n";
	std::cout << "p1 et p1 : " << (p1 == p1) << "\tp1 et p2 : " << (p1 == p2);
	std::cout << "\np1 et p3 : " << (p1 == p3) << "\tp1 et p4 : " << (p1 == p4) << std::endl;
	std::cout << "\ttest de !=\n";
	std::cout << "p1 et p1 : " << (p1 != p1) << "\tp1 et p2 : " << (p1 != p2);
	std::cout << "\np1 et p3 : " << (p1 != p3) << "\tp1 et p4 : " << (p1 != p4) << std::endl;
	std::cout << "\ttest de <\n";
	std::cout << "p1 et p1 : " << (p1 < p1);
	std::cout << "\np1 et p2 : " << (p1 < p2) << "\tp2 et p1 : " << (p2 < p1);
	std::cout << "\np1 et p3 : " << (p1 < p3) << "\tp3 et p1 : " << (p3 < p1);
	std::cout << "\np1 et p4 : " << (p1 < p4) << "\tp4 et p1 : " << (p4 < p1);
	std::cout << "\np2 et p3 : " << (p2 < p3) << "\tp3 et p2 : " << (p3 < p2);
	std::cout << "\np2 et p4 : " << (p2 < p4) << "\tp4 et p2 : " << (p4 < p2);
	std::cout << "\np3 et p4 : " << (p3 < p4) << "\tp4 et p3 : " << (p4 < p3) << std::endl;
	std::cout << "\ttest de <=\n";
	std::cout << "p1 et p1 : " << (p1 <= p1);
	std::cout << "\np1 et p2 : " << (p1 <= p2) << "\tp2 et p1 : " << (p2 <= p1);
	std::cout << "\np1 et p3 : " << (p1 <= p3) << "\tp3 et p1 : " << (p3 <= p1);
	std::cout << "\np1 et p4 : " << (p1 <= p4) << "\tp4 et p1 : " << (p4 <= p1);
	std::cout << "\np2 et p3 : " << (p2 <= p3) << "\tp3 et p2 : " << (p3 <= p2);
	std::cout << "\np2 et p4 : " << (p2 <= p4) << "\tp4 et p2 : " << (p4 <= p2);
	std::cout << "\np3 et p4 : " << (p3 <= p4) << "\tp4 et p3 : " << (p4 <= p3) << std::endl;
	std::cout << "\ttest de >\n";
	std::cout << "p1 et p1 : " << (p1 > p1);
	std::cout << "\np1 et p2 : " << (p1 > p2) << "\tp2 et p1 : " << (p2 > p1);
	std::cout << "\np1 et p3 : " << (p1 > p3) << "\tp3 et p1 : " << (p3 > p1);
	std::cout << "\np1 et p4 : " << (p1 > p4) << "\tp4 et p1 : " << (p4 > p1);
	std::cout << "\np2 et p3 : " << (p2 > p3) << "\tp3 et p2 : " << (p3 > p2);
	std::cout << "\np2 et p4 : " << (p2 > p4) << "\tp4 et p2 : " << (p4 > p2);
	std::cout << "\np3 et p4 : " << (p3 > p4) << "\tp4 et p3 : " << (p4 > p3) << std::endl;
	std::cout << "\ttest de >=\n";
	std::cout << "p1 et p1 : " << (p1 >= p1);
	std::cout << "\np1 et p2 : " << (p1 >= p2) << "\tp2 et p1 : " << (p2 >= p1);
	std::cout << "\np1 et p3 : " << (p1 >= p3) << "\tp3 et p1 : " << (p3 >= p1);
	std::cout << "\np1 et p4 : " << (p1 >= p4) << "\tp4 et p1 : " << (p4 >= p1);
	std::cout << "\np2 et p3 : " << (p2 >= p3) << "\tp3 et p2 : " << (p3 >= p2);
	std::cout << "\np2 et p4 : " << (p2 >= p4) << "\tp4 et p2 : " << (p4 >= p2);
	std::cout << "\np3 et p4 : " << (p3 >= p4) << "\tp4 et p3 : " << (p4 >= p3) << std::endl;

}