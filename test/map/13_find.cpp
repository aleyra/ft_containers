#include "../common.hpp"

int main()
{
	curr::map<int, int> map;

	std::cout << map.size() << std::endl;
	std::cout << map.max_size() << std::endl;
	
	for (int i = 0; i < 1000; ++i) {
		map[i] = i * 3 + 1 + (i % 7);
	}
	
	std::cout << map.find(60)->first << " " << map.find(60)->second << std::endl;
	
	if (map.find(-10000) == map.end()) {
		std::cout << "OK" << std::endl;
	}
	
	return 0;
}
