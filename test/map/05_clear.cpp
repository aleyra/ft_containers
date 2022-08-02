#include "../common.hpp"

int main()
{
	curr::vector< curr::pair<int, int> > vec;
	
	for (int i = 0; i < 500; ++i) {
		vec.push_back(curr::make_pair(1000 + i, i));
	}
	
	curr::map<int, int> map;

	std::cout <<"map.size = " << map.size() << std::endl;//ajout de txt
	std::cout /*<<"map.max_size = " */<< map.max_size() << std::endl;//ajout de txt
	
	for (int i = 0; i < 1000; ++i) {
		map[i] = i * 3 + 1 + (i % 7);
	}
	
	map.insert(vec.begin(), vec.end());
	
	std::cout /*<<"map.size = " */<< map.size() << std::endl;//ajout de txt
	
	map.clear();
	std::cout /*<<"map.size = " */<< map.size() << std::endl;//ajout de txt
	
	// std::cout << "je teste des trucs\n";//
	// map.begin();//
	// std::cout << "je continue\n";//
	// map.end();//
	// std::cout << "je termine\n";//

	// curr::map<int, int>::const_iterator it = map.begin();//
	// std::cout << "je teste des trucs\n";//

	
	/*for (;it != map.end(); ++it){*/for (curr::map<int, int>::const_iterator it = map.begin(); it != map.end(); ++it) {
		// std::cout << "dans le for\n";//
		std::cout << "{ " << it->first << ", " << it->second << " }" << std::endl;
	}

	return 0;
}
