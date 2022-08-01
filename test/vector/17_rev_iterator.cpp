#include "../common.hpp"

int main()
{
	curr::vector<int> int_vec1(30, 42);

	for (curr::vector<int>::reverse_iterator it = int_vec1.rbegin(); it != int_vec1.rend(); ++it) {
		std::cout << *it << std::endl;
	}

	return 0;
}
