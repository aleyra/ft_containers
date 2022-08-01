#include "../common.hpp"
#include <cstdlib>

int main()
{
	srand(42); // Fixed seed

	curr::vector<int> int_vec(rand() % 100, 0);
	for (curr::vector<int>::iterator it = int_vec.begin(); it != int_vec.end(); ++it) {
		*it = rand();
	}

	for (unsigned int i = 0; i < int_vec.size(); ++i) {
		std::cout << int_vec[i] << std::endl;
	}

	return 0;
}
