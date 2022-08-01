#include "../common.hpp"

int main()
{
	curr::vector<int> empty_int_vec;
	curr::vector<ComplexType> empty_ct_vec;

	std::cout << "int vector size: " << empty_int_vec.size() << std::endl;
	std::cout << "int vector capacity: " << empty_int_vec.capacity() << std::endl;
	std::cout << "complex type size: " << empty_ct_vec.size() << std::endl;
	std::cout << "complex type capacity: " << empty_ct_vec.capacity() << std::endl;

	return 0;
}
