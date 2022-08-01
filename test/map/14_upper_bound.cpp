#include "../common.hpp"

int main()
{
	curr::map<int, int> map;

	std::cout << map.size() << std::endl;
	std::cout << map.max_size() << std::endl;
	
	for (int i = 0; i < 1000; ++i) {
		map[i] = i * 3 + 1 + (i % 7);
	}
	
	for (int i = 200; i < 800; ++i) {
		std::cout << map.upper_bound(i)->first << " " << map.upper_bound(i)->second << std::endl;
	}
	
	return 0;
}
