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

	curr::vector<int> int_vec(40, -6);
	curr::vector<ComplexType> ct_vec(40, ComplexType());

	int_vec.insert(int_vec.end(), list.begin(), list.end());
	ct_vec.insert(ct_vec.end(), clist.begin(), clist.end());

	std::cout << "int vector size: " << int_vec.size() << std::endl;
	std::cout << "complex type size: " << ct_vec.size() << std::endl;

	for (curr::vector<int>::iterator it = int_vec.begin(); it != int_vec.end(); ++it) {
		std::cout << *it << std::endl;
	}

	curr::vector<int> new_int(10, 42);
	curr::vector<ComplexType> new_ct(10, ComplexType());


	curr::swap(new_int, int_vec);
	curr::swap(new_ct, ct_vec);

	return 0;
	std::cout << "int vector size: " << int_vec.size() << std::endl;
	std::cout << "complex type size: " << ct_vec.size() << std::endl;

	std::cout << "new int vector size: " << new_int.size() << std::endl;
	std::cout << "new complex type size: " << new_ct.size() << std::endl;

	for (curr::vector<int>::iterator it = int_vec.begin(); it != int_vec.end(); ++it) {
		std::cout << *it << std::endl;
	}

	for (curr::vector<int>::iterator it = new_int.begin(); it != new_int.end(); ++it) {
		std::cout << *it << std::endl;
	}

	return 0;
}
