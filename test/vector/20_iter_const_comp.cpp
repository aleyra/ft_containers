#include "../common.hpp"

int main()
{
	curr::vector<int> vec42(30, 42);

	curr::vector<int>::iterator mutbegin = vec42.begin();
	curr::vector<int>::const_iterator constbegin = vec42.begin();
	
	std::cout << (mutbegin == constbegin) << std::endl;

	return 0;
}
