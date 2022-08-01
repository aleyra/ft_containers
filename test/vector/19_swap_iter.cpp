#include "../common.hpp"

int main()
{
	curr::vector<int> vec42(30, 42);
	curr::vector<int> vec90(20, 90);

	curr::vector<int>::const_iterator begin42 = vec42.begin();
	curr::vector<int>::const_iterator end42 = vec42.end();
	curr::vector<int>::const_iterator begin90 = vec90.begin();
	curr::vector<int>::const_iterator end90 = vec90.end();

	curr::swap(vec42, vec90);

	std::cout << "First element of vec42: " << vec42[0] << std::endl;
	std::cout << "First element of vec90: " << vec90[1] << std::endl;

	for (curr::vector<int>::const_iterator it = begin42; it != end42; ++it) {
		std::cout << *it << std::endl;
	}
	for (curr::vector<int>::const_iterator it = begin90; it != end90; ++it) {
		std::cout << *it << std::endl;
	}

	return 0;
}
