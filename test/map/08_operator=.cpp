#include "../common.hpp"

int main()
{
	curr::map<int, int> map;

	std::cout << map.size() << std::endl;
	std::cout << map.max_size() << std::endl;
	
	for (int i = 0; i < 1000; ++i) {
		map[i] = i * 3 + 1 + (i % 7);
	}
	
	curr::map<int, int> map2 = map;
	
	for (curr::map<int, int>::const_iterator it = map.begin(); it != map.end(); ++it) {
		std::cout << "{ " << it->first << ", " << it->second << " }" << std::endl;
	}
	
	for (curr::map<int, int>::const_iterator it = map2.begin(); it != map2.end(); ++it) {
		std::cout << "{ " << it->first << ", " << it->second << " }" << std::endl;
	}
	
	return 0;
}
