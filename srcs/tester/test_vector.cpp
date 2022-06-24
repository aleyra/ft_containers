#if 0 //1 = original 0 = perso
	# include <vector>
	namespace ft = std;
#else
	# include <vector.hpp>
#endif
#include <iostream>

void	display_int(ft::vector<int> v){
				for (ft::vector<int>::iterator it = v.begin(); it < v.end(); it++){
					std::cout << *it;
					if (it != v.end() - 1)
					std::cout << " - ";
				}
				std::cout << std::endl;
}

void test_vector(){
		//constructors, iterators and begin, end fct
	ft::vector<int> v1();
	ft::vector<int> v2(5, 12);
	int tab[]={1,2,3,4,5};
	ft::vector<int> v3(tab, tab + 5);
	ft::vector<int> v4(v2);
	ft::vector<int> v5(100);

	// {std::cout << "\ttest de iterator, reverse_iterator, begin, end, rbegin et rend\n";
	// display_int(v2);
	// display_int(v3);
	// display_int(v4);
	// for (ft::vector<int>::reverse_iterator it = v3.rbegin(); it != v3.rend(); it++)
	// 	std::cout << *it << " - ";
	// std::cout << std::endl;}

	std::cout << "size = " << v2.size() << std::endl;
	
	std::cout << "max_size = " << v2.max_size() << std::endl;
	
	std::cout << "capacite = " << v2.capacity() << std::endl;
	std::cout << "capacite de v5 = " << v5.capacity() << std::endl;

	// {std::cout << "\ttest de resize et reserve\n";
	// v2.resize(4);
	// display_int(v2);
	// v2.resize(6, 10);
	// display_int(v2);
	// v2.resize(9);
	// display_int(v2);}
	
	// {std::cout << "\tclear et empty\n";
	// display_int(v4);
	// std::cout << "empty = " << v4.empty() << std::endl;
	// v4.clear();
	// std::cout << "empty = " << v4.empty() << std::endl;}
	
	// {std::cout << "\ttest des fonctions \"element access\"\n";
	// display_int(v3);
	// std::cout << "v3[2] = " << v3[2] << "\tv3.at(2) = " << v3.at(2) << std::endl;
	// std::cout << "v3.front() = " << v3.front() << "\tv3.back() = " << v3.back() << std::endl;
	// int *data = v3.data();
	// std::cout << "data[2] = " << data[2] << std::endl;}

	
}