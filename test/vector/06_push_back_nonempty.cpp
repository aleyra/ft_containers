#include "../common.hpp"

int main()
{
	curr::vector<int> int_vec(30, 42);
	curr::vector<ComplexType> ct_vec(30, ComplexType());

	int_vec.push_back(90);
	ct_vec.push_back(ComplexType());

	std::cout << "int vector size: " << int_vec.size() << std::endl;
	std::cout << "complex type size: " << ct_vec.size() << std::endl;

	for (curr::vector<int>::iterator it = int_vec.begin(); it != int_vec.end(); ++it) {
		std::cout << *it << std::endl;
	}

	return 0;
}
