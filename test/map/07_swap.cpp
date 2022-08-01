#include "../common.hpp"

int main()
{
	curr::map<int, int> map;

	std::cout << map.size() << std::endl;
	std::cout << map.max_size() << std::endl;
	
	for (int i = 0; i < 1000; ++i) {
		map[i] = i * 3 + 1 + (i % 7);
	}
	
	std::cout << map.size() << std::endl;
	std::cout << map.max_size() << std::endl;
	
	curr::map<int, int> map2;
	curr::swap(map, map2);
	
	std::cout << map.size() << std::endl;
	std::cout << map.max_size() << std::endl;
	
	std::cout << map2.size() << std::endl;
	std::cout << map2.max_size() << std::endl;

	return 0;
}
