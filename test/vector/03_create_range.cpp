#include "../common.hpp"

#include <list>

int main()
{
	std::list<int> list;
	std::list<ComplexType> clist;

	for (int i = 0; i < 100; i += 3) {
		list.push_back(i);
	}

	for (int i = 0; i < 100; i += 3) {
		clist.push_back(ComplexType());
	}

	curr::vector<int> int_vec(list.begin(), list.end());
	curr::vector<ComplexType> ct_vec(clist.begin(), clist.end());

	std::cout << "int vector size: " << int_vec.size() << std::endl;
	std::cout << "complex type size: " << ct_vec.size() << std::endl;

	for (curr::vector<int>::iterator it = int_vec.begin(); it != int_vec.end(); ++it) {
		std::cout << *it << std::endl;
	}

	return 0;
}
