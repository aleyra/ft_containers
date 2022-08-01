#include "../common.hpp"

int main()
{
	curr::map<int, int> map;

	curr::map<int, int>::iterator mutbegin = map.begin();
	curr::map<int, int>::const_iterator constbegin = map.begin();
	
	std::cout << (mutbegin == constbegin) << std::endl;

	return 0;
}
