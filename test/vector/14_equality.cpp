#include "../common.hpp"

int main()
{
	curr::vector<int> int_vec1(30, 42);
	curr::vector<int> int_vec2(30, 42);
	curr::vector<int> int_vec3(29, 42);
	curr::vector<int> int_vec4(31, 42);
	curr::vector<int> int_vec5(30, 41);

	std::cout << (int_vec1 == int_vec2) << std::endl;
	std::cout << (int_vec1 == int_vec3) << std::endl;
	std::cout << (int_vec1 == int_vec4) << std::endl;
	std::cout << (int_vec1 == int_vec5) << std::endl;

	return 0;
}
