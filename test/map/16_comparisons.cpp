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
	
	std::cout << (map == map2) << std::endl;
	std::cout << (map != map2) << std::endl;
	std::cout << (map < map2) << std::endl;
	std::cout << (map <= map2) << std::endl;
	std::cout << (map > map2) << std::endl;
	std::cout << (map >= map2) << std::endl;
	
	map2 = map;
	
	std::cout << (map == map2) << std::endl;
	std::cout << (map != map2) << std::endl;
	std::cout << (map < map2) << std::endl;
	std::cout << (map <= map2) << std::endl;
	std::cout << (map > map2) << std::endl;
	std::cout << (map >= map2) << std::endl;
	
	map2.erase(400);
	
	std::cout << (map == map2) << std::endl;
	std::cout << (map != map2) << std::endl;
	std::cout << (map < map2) << std::endl;
	std::cout << (map <= map2) << std::endl;
	std::cout << (map > map2) << std::endl;
	std::cout << (map >= map2) << std::endl;
	
	map.erase(700);
	map.erase(400);
	map.erase(470);
	
	std::cout << (map == map2) << std::endl;
	std::cout << (map != map2) << std::endl;
	std::cout << (map < map2) << std::endl;
	std::cout << (map <= map2) << std::endl;
	std::cout << (map > map2) << std::endl;
	std::cout << (map >= map2) << std::endl;
	
	return 0;
}
