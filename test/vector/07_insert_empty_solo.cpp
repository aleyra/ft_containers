#include "../common.hpp"

int main()
{
	curr::vector<int> int_vec;
	curr::vector<ComplexType> ct_vec;

	int_vec.insert(int_vec.begin(), -10);
	ct_vec.insert(ct_vec.begin(), ComplexType());

	std::cout << "int vector size: " << int_vec.size() << std::endl;
	std::cout << "complex type size: " << ct_vec.size() << std::endl;

	for (curr::vector<int>::iterator it = int_vec.begin(); it != int_vec.end(); ++it) {
		std::cout << *it << std::endl;
	}

	return 0;
}
