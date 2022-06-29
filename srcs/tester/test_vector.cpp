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
	ft::vector<int> v1;
	ft::vector<int> v2(5, 12);
	int tab[]={1,2,3,4,5};
	ft::vector<int> v3(tab, tab + 5);
	ft::vector<int> v4(v2);
	ft::vector<int> v5(100);
{
	{std::cout << "\ttest de iterator, reverse_iterator, begin, end, rbegin et rend et leurs const\n";
		std::cout << "v2 = ";
		display_int(v2);
		std::cout << "v3 = ";
		display_int(v3);
		std::cout << "v4 = ";
		display_int(v4);
		std::cout << "v3 à l'envers = ";
		for (ft::vector<int>::reverse_iterator it = v3.rbegin(); it != v3.rend(); it++)
			std::cout << *it << " - ";
		std::cout << std::endl;
		ft::vector<int>::const_iterator citb = v3.begin();
		ft::vector<int>::const_iterator cite = v3.end();
		ft::vector<int>::const_reverse_iterator critb = v3.rbegin();
		ft::vector<int>::const_reverse_iterator crite = v3.rend();
		std::cout << "versions const :\n";
		std::cout << "v3.begin() = " << *citb << "\tv3.end() = " << *(cite - 1);
		std::cout << "\nv3.rbegin() = " << *critb << "\tv3.rend() = " << *(crite - 1) << std::endl;
	}

	// std::cout << "size = " << v2.size() << std::endl;
	
	// std::cout << "max_size = " << v2.max_size() << std::endl;
	
	// std::cout << "capacite = " << v2.capacity() << std::endl;
	// std::cout << "capacite de v5 = " << v5.capacity() << std::endl;

	// {std::cout << "\ttest de resize et reserve\n";//change v2
	// 	v2.resize(4);
	// 	display_int(v2);
	// 	v2.resize(6, 10);
	// 	display_int(v2);
	// 	v2.resize(9);
	// 	display_int(v2);
	// }
	
	// {std::cout << "\tclear et empty\n";//vide v4
	// 	display_int(v4);
	// 	std::cout << "empty = " << v4.empty() << std::endl;
	// 	v4.clear();
	// 	std::cout << "empty = " << v4.empty() << std::endl;
	// }
	
	// {std::cout << "\ttest des fonctions \"element access\"\n";//pas de modif
	// 	display_int(v3);
	// 	std::cout << "v3[2] = " << v3[2] << "\tv3.at(2) = " << v3.at(2) << std::endl;
	// 	std::cout << "v3.front() = " << v3.front() << "\tv3.back() = " << v3.back() << std::endl;
	// 	int *data = v3.data();
	// 	std::cout << "data[2] = " << data[2] << std::endl;
	// }

	// {std::cout << "\ttest de assign et erase\n";//modif v2
	// 	ft::vector<int> v6(v3);
	// 	std::cout << "v6 = ";
	// 	display_int(v6);
	// 	std::cout << "v6.begin() + 1 = " << *(v6.begin() + 1);	
	// 	std::cout << "\tv6.erase(v6.begin() + 1) = " << *(v6.erase(v6.begin() + 1)) << std::endl;
	// 	std::cout << "v6 = ";
	// 	display_int(v6);
	// 	v6 = v3;
	// 	std::cout << "v6 reset = ";
	// 	display_int(v6);
	// 	std::cout << "v6.begin() + 1 = " << *(v6.begin() + 1);	
	// 	std::cout << "\tv6.erase(v2.begin() + 1, v6.begin() + 3) = " << *(v6.erase(v6.begin() + 1, v6.begin() + 3)) << std::endl;
	// 	// std::cout << "v6 = ";
	// 	display_int(v6);
	// 	std::cout << "v2 = ";
	// 	display_int(v2);
	// 	v2.assign(3, 5);
	// 	std::cout << "v2 = ";
	// 	display_int(v2);
	// 	v2.assign(v3.begin() + 1, v3.begin() + 5);
	// 	std::cout << "v2 = ";
	// 	display_int(v2);
	// 	std::cout << std::endl;
	// }

	// {std::cout << "\ttest de push_back et pop_back\n";//sur v3 mais retour à l'original
	// 	std::cout << "v3 = ";
	// 	display_int(v3);
	// 	v3.push_back(6);
	// 	std::cout << "v3 = ";
	// 	display_int(v3);
	// 	v3.pop_back();
	// 	std::cout << "v3 = ";
	// 	display_int(v3);
	// 	std::cout << endl;
	// }

	// {std::cout << "\ttest de swap\n";//sur v7 et v8 crees pour
	// 	ft::vector<int> v7(5,10);
	// 	ft::vector<int> v8(8,12);
	// 	std::cout << "v7 = ";
	// 	display_int(v7);
	// 	std::cout << "v8 = ";
	// 	display_int(v8);
	// 	v7.swap(v8);
	// 	std::cout << "v7 = ";
	// 	display_int(v7);
	// 	std::cout << "v8 = ";
	// 	display_int(v8);
	// 	std::cout << std::endl;
	// }

	// {std::cout << "\ttest de insert\n";//modifie v3
	// 	std::cout << "v3 = ";
	// 	display_int(v3);
	// 	std::cout << *(v3.insert(v3.begin() + 2, 0)) << std::endl;
	// 	std::cout << "v3 = ";
	// 	display_int(v3);
	// 	v3.insert(v3.begin() + 4, 2, 1);
	// 	std::cout << "v3 = ";
	// 	display_int(v3);
	// 	v3.insert(v3.begin() + 3, tab, tab + 4);
	// 	std::cout << "v3 = ";
	// 	display_int(v3);
	// 	std::cout << std::endl;
	// }

	// {std::cout << "\ttest de get_allocator\n";
	// 	int * p;
	// 	unsigned int i;
	// 	p = v1.get_allocator().allocate(5);
	// 	for (i=0; i<5; i++)
	// 		v1.get_allocator().construct(&p[i],i);
	// 	for (i=0; i<5; i++)
	// 		std::cout << ' ' << p[i];
	// 	std::cout << '\n';
	// 	for (i=0; i<5; i++)
	// 		v1.get_allocator().destroy(&p[i]);
	// 	v1.get_allocator().deallocate(p,5);
	// 	std::cout << std::endl;
	// }
}
	{std::cout << "\ttest des fonctions non membres\n";
		std::cout << "v2 = ";
		display_int(v2);
		std::cout << "v3 = ";
		display_int(v3);
		v4 = v2;
		v4.push_back(12);
		std::cout << "v4 = ";
		display_int(v4);

		std::cout << "\t\ttest de == :\n";
		std::cout << "v2 et v2 : " << (v2 == v2) << "\tv2 et v3 : " << (v2 == v3) << std::endl;

		std::cout << "\t\ttest de != :\n";
		std::cout << "v2 et v2 : " << (v2 != v2) << "\tv2 et v3 : " << (v2 != v3) << std::endl;

		std::cout << "\t\ttest de < :\n";
		std::cout << "v2 et v2 : " << (v2 < v2) << "\tv2 et v3 : " << (v2 < v3) << std::endl;
		std::cout << "v3 et v2 : " << (v3 < v2) << std::endl;

		std::cout << "\t\ttest de <= :\n";
		std::cout << "v2 et v2 : " << (v2 <= v2) << "\tv2 et v3 : " << (v2 <= v3) << std::endl;
		std::cout << "v3 et v2 : " << (v3 <= v2) << std::endl;

		std::cout << "\t\ttest de > :\n";
		std::cout << "v2 et v2 : " << (v2 > v2) << "\tv2 et v3 : " << (v2 > v3) << std::endl;
		std::cout << "v3 et v2 : " << (v3 > v2) << std::endl;

		std::cout << "\t\ttest de >= :\n";
		std::cout << "v2 et v2 : " << (v2 >= v2) << "\tv2 et v3 : " << (v2 >= v3) << std::endl;
		std::cout << "v3 et v2 : " << (v3 >= v2) << std::endl;

		std::cout << "\t\ttest de ft::equal avec v2 et v4 :\n";
		std::cout << (ft::equal(v2.begin(), v2.end(), v4.begin())) << std::endl;
		
		swap(v2, v3);
		std::cout << "v2 = ";
		display_int(v2);
		std::cout << "v3 = ";
		display_int(v3);

		
	}
}