#include "../common.hpp"

int main()
{
	curr::map<int, int> map;

	std::cout << map.size() << std::endl;
	std::cout << map.max_size() << std::endl;
	
	for (int i = 0; i < 1000; ++i) {
		map[i] = i * 3 + 1 + (i % 7);
	}
	
	curr::map<int, int> map2;
	
	std::cout << map.empty() << std::endl;
	std::cout << map2.empty() << std::endl;
	
	map2 = map;
	
	std::cout << map.empty() << std::endl;
	std::cout << map2.empty() << std::endl;
	return 0;
}
