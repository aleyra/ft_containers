#include "../common.hpp"
#include <cstdlib>

int main()
{
	srand(42); // Same seed for reproducable results
	std::cout << "first: " << rand() << std::endl;

	for (int i = 0; i < 150; ++i) {
		curr::vector<int> vec1(rand() % 100, 0);
		for (curr::vector<int>::iterator it = vec1.begin(); it != vec1.end(); ++it) {
			*it = rand();
		}

		curr::vector<int> vec2(rand() % 100, 0);
		for (curr::vector<int>::iterator it = vec2.begin(); it != vec2.end(); ++it) {
			*it = rand();
		}

		std::cout << "inferior " << (vec1 < vec2) << std::endl;
		std::cout << "inferior or equal " << (vec1 <= vec2) << std::endl;
		std::cout << "superior " << (vec1 > vec2) << std::endl;
		std::cout << "superior or equal" << (vec1 >= vec2) << std::endl;
		std::cout << "equal " << (vec1 == vec2) << std::endl;
		std::cout << "different from " << (vec1 != vec2) << std::endl;
	}

	return 0;
}
