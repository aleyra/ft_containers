#include "../common.hpp"

int main()
{
	curr::map<int, int> map;

	std::cout << map.size() << std::endl;
	std::cout << map.max_size() << std::endl;
	
	for (int i = 0; i < 1000; ++i) {
		map[i] = i * 3 + 1 + (i % 7);
	}
	
	std::cout << map.at(5) << std::endl;
	
	try {
		map.at(50000);
		std::cout << "This should not print" << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception thrown (correct behaviour)" << std::endl;
	}
	
	return 0;
}
