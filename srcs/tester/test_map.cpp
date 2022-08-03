#include <map>//
#if 1 //1 = original 0 = perso
	# include <map>
	namespace ft = std;
#else
	# include <map.hpp>
#endif
#include <iostream>

void test_map(){
	// std::cout << "\ttests constructeurs, empty, operateur [], begin et end\n";
	// std::cout << "\t\tconstructeur par default, empty et operateur [] pour l'assignation\n";
	ft::map<int, char> m1;
	// if (m1.empty() == true)
	// 	std::cout << "m1 est vide\n";
	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';
	m1[4] = 'd';
	// if (m1.empty() == false)
	// 	std::cout << "m1 n'est plus vide\n";

	// std::cout << "\t\tbegin() et end()\n";
	// for (ft::map<int, char>::iterator it = m1.begin(); it != m1.end(); it++){
	// 	std::cout << "m1[" << it->first << "] = " << it->second << std::endl;
	// }
	{
		// std::cout << "\t\toperateur [] pour la recuperation de la value\n";
		// std::cout << "m1[1] = " << m1[1] << std::endl;
		// std::cout << "m1[2] = " << m1[2] << std::endl; 
		// std::cout << "m1[3] = " << m1[3] << std::endl; 
		// std::cout << "m1[4] = " << m1[4] << std::endl; 

		// std::cout << "\t\tassignation par copie\n";
		// ft::map<int, char> m2;
		// m2 = m1;
		// for (ft::map<int, char>::iterator it = m2.begin(); it != m2.end(); it++){
		// 	std::cout << "m2[" << it->first << "] = " << it->second << std::endl;
		// }

		// std::cout << "\t\tconstructeur par copie\n";
		// ft::map<int, char> m3(m1);
		// for (ft::map<int, char>::iterator it = m3.begin(); it != m3.end(); it++){
		// 	std::cout << "m3[" << it->first << "] = " << it->second << std::endl;
		// }

		// std::cout << "\t\tconstructeur par range\n";
		// ft::map<int, char> m4(m1.begin(), m1.end());
		// for (ft::map<int, char>::iterator it = m4.begin(); it != m4.end(); it++){
		// 	std::cout << "m4[" << it->first << "] = " << it->second << std::endl;
		// }
	}
	{//pb
		// std::cout << "\n\ttests de rbegin, rend, const begin\n";
		// // std::cout << "\t\trbegin et rend\n";
		// // ft::map<int, char>::reverse_iterator it = m1.rbegin();//pb
		// // std::cout << "m[" << it->first << "] = " << it->second << std::endl;// -> m[3] = c au lieu de m[4] = d
		// // it++;
		// // std::cout << "m[" << it->first << "] = " << it->second << std::endl;

		// // for (ft::map<int, char>::reverse_iterator it = m1.rbegin(); it != m1.rend(); it++){
		// // 	std::cout << "m[" << it->first << "] = " << it->second << std::endl;
		// // }
		// std::cout << "\t\tversion const de begin\t";
		// ft::map<int, char>::const_iterator citb = m1.begin();
		// std::cout << "m[" << citb->first << "] = " << citb->second << std::endl;
	}
	{
		// std::cout << "\n\ttests de size et max_size\n";
		// std::cout << "size = " << m1.size() << "\tmax_size = " << m1.max_size() << std::endl;
	}
	{
		// std::cout << "\n\ttest des inserts\n";
		ft::map<int, char> m5;
		// std::cout << "\t\tinsert de val dans m5 (vide)\n";
		ft::pair<ft::map<int, char>::iterator, bool> p = m5.insert(ft::make_pair(0, 'z'));
		// if (p.second == true)
		// 	std::cout << "insert de (0, z) reussi\n";
		// std::cout << "m5[" << p.first->first << "] = " << p.first->second << std::endl;
		p = m5.insert(ft::make_pair(0, 'A'));
		// if (p.second == false)
		// 	std::cout << "insert de (0, A) echec\n";
		// std::cout << "m5[" << p.first->first << "] = " << p.first->second << std::endl;
		m5[5] = 'e';
		m5[7] = 'g';
		ft::map<int, char>::iterator it = m5.begin();
		it++;
		// std::cout << "\t\tinsert depuis une position\n";
		// std::cout << "selection d'un iterator\n";
		// std::cout << "m5[" << it->first << "] = " << it->second << std::endl;
		it = m5.insert(it, ft::make_pair(6, 'f'));
		// std::cout << "nouvel elem : ";
		// std::cout << "m5[" << it->first << "] = " << it->second << std::endl;
		// std::cout << "\t\tinsert par range de m5 dans m1\n";
		m1.insert(m5.begin(), m5.end());
		for (ft::map<int, char>::iterator it = m1.begin(); it != m1.end(); it++){
			std::cout << "m1[" << it->first << "] = " << it->second << std::endl;
		}
	}
	{//pb
		std::cout << "\n\ttests des erases\n";
		std::cout << "\t\terase par position\n";
		std::cout << "choix d'une position\n";
		ft::map<int, char>::iterator it = m1.begin();
		it++;
		std::cout << "m1[" << it->first << "] = " << it->second << std::endl;
		m1.erase(it);
		std::cout << "contenu de m1 apres erase : \n";
		// std::cout << "m1[" << it->first << "] = " << it->second << std::endl;
		for (ft::map<int, char>::iterator it2 = m1.begin(); it2 != m1.end(); it2++){
			std::cout << "m1[" << it2->first << "] = " << it2->second << std::endl;
		}
		if (m1.erase(2) == 1)
			std::cout << "erase fait\n";
		std::cout << "contenu de m1 apres erase de 2 : \n";
		for (ft::map<int, char>::iterator it2 = m1.begin(); it2 != m1.end(); it2++){
			std::cout << "m1[" << it2->first << "] = " << it2->second << std::endl;
		}
		ft::map<int, char>::iterator e = m1.begin();
		e++;
		e++;
		// ft::map<int, char>::iterator b = e;
		// std::cout << "m1[" << b->first << "] = " << b->second << std::endl;//
		e++;
		e++;
		// std::cout << "m1[" << e->first << "] = " << e->second << std::endl;//
		// m1.erase(b, e);//pb
		// std::cout << "contenu de m1 apres erase de 4(inclu) à 6(exclu) : \n";
		// b = m1.begin();
		// std::cout << "m1[" << b->first << "] = " << b->second << std::endl;//
		// for (ft::map<int, char>::iterator it3 = m1.begin(); it3 != m1.end(); it3++){
		// 	std::cout << "m1[" << it3->first << "] = " << it3->second << std::endl;
		// }
		// ft::print_node(m1.root());
	}
	{
		// std::cout << "\ttest de swap et clear\n";
		// ft::map<int, char> m6 = m1;
		// for (ft::map<int, char>::iterator it3 = m1.begin(); it3 != m1.end(); it3++){
		// 	std::cout << "m1[" << it3->first << "] = " << it3->second << std::endl;
		// }
		// m6.erase(6);
		// m6.erase(3);
		// std::cout << std::endl;
		// for (ft::map<int, char>::iterator it4 = m6.begin(); it4 != m6.end(); it4++){
		// 	std::cout << "m6[" << it4->first << "] = " << it4->second << std::endl;
		// }
		// std::cout << "\t\tswap interne\n";
		// m1.swap(m6);
		// for (ft::map<int, char>::iterator it3 = m1.begin(); it3 != m1.end(); it3++){
		// 	std::cout << "m1[" << it3->first << "] = " << it3->second << std::endl;
		// }
		// std::cout << std::endl;
		// for (ft::map<int, char>::iterator it4 = m6.begin(); it4 != m6.end(); it4++){
		// 	std::cout << "m6[" << it4->first << "] = " << it4->second << std::endl;
		// }
		// std::cout << "\t\tswap externe\n";
		// swap(m1, m6);
		// for (ft::map<int, char>::iterator it3 = m1.begin(); it3 != m1.end(); it3++){
		// 	std::cout << "m1[" << it3->first << "] = " << it3->second << std::endl;
		// }
		// std::cout << std::endl;
		// for (ft::map<int, char>::iterator it4 = m6.begin(); it4 != m6.end(); it4++){
		// 	std::cout << "m6[" << it4->first << "] = " << it4->second << std::endl;
		// }
		// std::cout << "\t\tclear\n";
		// m6.clear();
		// if (m6.empty() == true)
		// 	std::cout << "m6 est vide\n";
	}
	{
		std::cout << "\ttests de find, count, lower et upper bound et equal_range\n";
	}
	{
		// std::cout << "\ttest de get_allocator\n";
	}
	{
		// std::cout << "\ttests des comparatifs == , !=, <, <=, > et >=\n";
	}
}