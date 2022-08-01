#include "../common.hpp"

int main()
{
	curr::map<std::string, std::string> empty_map;

	std::cout << empty_map.size() << std::endl;
	std::cout << empty_map.max_size() << std::endl;
	
	for (curr::map<std::string, std::string>::const_iterator it = empty_map.begin(); it != empty_map.end(); ++it) {
		std::cout << "{ " << it->first << ", " << it->second << " }" << std::endl;
	}

	return 0;
}
