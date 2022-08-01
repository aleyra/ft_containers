#include "../common.hpp"

int main()
{
	curr::vector< curr::pair<int, int> > vec;
	
	for (int i = 0; i < 500; ++i) {
		vec.push_back(curr::make_pair(1000 + i, i));
	}
	
	curr::map<int, int> map;

	std::cout << map.size() << std::endl;
	std::cout << map.max_size() << std::endl;
	
	for (int i = 0; i < 1000; ++i) {
		map[i] = i * 3 + 1 + (i % 7);
	}
	
	map.insert(vec.begin(), vec.end());
	
	std::cout << map.size() << std::endl;
	
	for (curr::map<int, int>::const_iterator it = map.begin(); it != map.end(); ++it) {
		std::cout << "{ " << it->first << ", " << it->second << " }" << std::endl;
	}

	return 0;
}
