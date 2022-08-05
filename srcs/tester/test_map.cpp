#include <map>//
#if 0 //1 = original 0 = perso
	# include <map>
	namespace ft = std;
#else
	# include <map.hpp>
#endif
#include <iostream>

void test_map(){
	{
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
		for (ft::map<int, char>::iterator it = m1.begin(); it != m1.end(); it++){
			std::cout << "m1[" << it->first << "] = " << it->second << std::endl;
		}
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
			////tester (begin--)++ et end--//
		}
		{//pb
			std::cout << "\n\ttests de rbegin, rend, const begin et end\n";
			std::cout << "\t\trbegin et rend\n";
			ft::map<int, char>::reverse_iterator it = m1.rbegin();//pb
			std::cout << "m[" << it->first << "] = " << it->second << std::endl;// -> m[3] = c au lieu de m[4] = d
			it++;
			std::cout << "m[" << it->first << "] = " << it->second << std::endl;

			for (ft::map<int, char>::reverse_iterator it = m1.rbegin(); it != m1.rend(); it++){
				std::cout << "m[" << it->first << "] = " << it->second << std::endl;
			}
			std::cout << "\t\tversion const de begin\t";
			ft::map<int, char>::const_iterator citb = m1.begin();
			std::cout << "m[" << citb->first << "] = " << citb->second << std::endl;
			std::cout << "\t\tversion const de --end\t" << std::flush;
			ft::map<int, char>::const_iterator cite = m1.end();
			--cite;
			std::cout << "m[" << cite->first << "] = " << cite->second << std::endl;
			std::cout << "\t\tversion const de rbegin\t";
			ft::map<int, char>::const_iterator critb = m1.begin();
			std::cout << "m[" << critb->first << "] = " << critb->second << std::endl;
			std::cout << "\t\tversion const de end--\t";
			ft::map<int, char>::const_iterator crite = m1.end();
			cite--;
			std::cout << "m[" << crite->first << "] = " << crite->second << std::endl;
		}
		{
			// std::cout << "\n\ttests de size et max_size\n";
			// std::cout << "size = " << m1.size() << "\tmax_size = " << m1.max_size() << std::endl;
		}
		{
			// std::cout << "\n\ttest des inserts\n";
			// ft::map<int, char> m5;
			// std::cout << "\t\tinsert de val dans m5 (vide)\n";
			// ft::pair<ft::map<int, char>::iterator, bool> p = m5.insert(ft::make_pair(0, 'z'));
			// if (p.second == true)
			// 	std::cout << "insert de (0, z) reussi\n";
			// std::cout << "m5[" << p.first->first << "] = " << p.first->second << std::endl;
			// p = m5.insert(ft::make_pair(0, 'A'));
			// if (p.second == false)
			// 	std::cout << "insert de (0, A) echec\n";
			// std::cout << "m5[" << p.first->first << "] = " << p.first->second << std::endl;
			// m5[5] = 'e';
			// m5[7] = 'g';
			// ft::map<int, char>::iterator it = m5.begin();
			// it++;
			// std::cout << "\t\tinsert depuis une position\n";
			// std::cout << "selection d'un iterator\n";
			// std::cout << "m5[" << it->first << "] = " << it->second << std::endl;
			// it = m5.insert(it, ft::make_pair(6, 'f'));
			// std::cout << "nouvel elem : ";
			// std::cout << "m5[" << it->first << "] = " << it->second << std::endl;
			// std::cout << "\t\tinsert par range de m5 dans m1\n";
			// m1.insert(m5.begin(), m5.end());
			// for (ft::map<int, char>::iterator it = m1.begin(); it != m1.end(); it++){
			// 	std::cout << "m1[" << it->first << "] = " << it->second << std::endl;
			// }
		}
		{
			// std::cout << "\n\ttests des erases\n";
			// std::cout << "\t\terase par position\n";
			// std::cout << "choix d'une position\n";
			// ft::map<int, char>::iterator it = m1.begin();
			// it++;
			// std::cout << "m1[" << it->first << "] = " << it->second << std::endl;
			// m1.erase(it);
			// std::cout << "contenu de m1 apres erase : \n";
			// std::cout << "m1[" << it->first << "] = " << it->second << std::endl;
			// for (ft::map<int, char>::iterator it2 = m1.begin(); it2 != m1.end(); it2++){
			// 	std::cout << "m1[" << it2->first << "] = " << it2->second << std::endl;
			// }
			// if (m1.erase(2) == 1)
			// 	std::cout << "erase fait\n";
			// std::cout << "contenu de m1 apres erase de 2 : \n";
			// for (ft::map<int, char>::iterator it2 = m1.begin(); it2 != m1.end(); it2++){
			// 	std::cout << "m1[" << it2->first << "] = " << it2->second << std::endl;
			// }
			// ft::map<int, char>::iterator e = m1.begin();
			// e++;
			// e++;
			// ft::map<int, char>::iterator b = e;
			// std::cout << "m1[" << b->first << "] = " << b->second << std::endl;//
			// e++;
			// e++;
			// std::cout << "m1[" << e->first << "] = " << e->second << std::endl;//
			// m1.erase(b, e);
			// std::cout << "contenu de m1 apres erase de 4(inclu) à 6(exclu) : \n";
			// b = m1.begin();
			// // std::cout << "m1[" << b->first << "] = " << b->second << std::endl;//
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
	}
	{
		// std::cout << "\ttests de find, count, lower et upper bound et equal_range\n";
		// ft::map<int, char>m7;
		// m7[1] = 'a';
		// m7[2] = 'b';
		// m7[4] = 'd';
		// m7[5] = 'e';
		// for (ft::map<int, char>::iterator it5 = m7.begin(); it5 != m7.end(); it5++){
		// 	std::cout << "m7[" << it5->first << "] = " << it5->second << std::endl;
		// }
		// std::cout << "\t\tfind\n";
		// ft::map<int, char>::iterator it;
		// it = m7.find(0);
		// if (it == m7.end())
		// 	std::cout << "pas de clé == 0\n";
		// it = m7.find(1);
		// std::cout << "m7[" << it->first << "] = " << it->second << std::endl;

		// {//pb avec find donc ver const aussi
		// 	std::cout << "\t\tfind version const_iterator\n";
		// 	ft::map<int, char>::const_iterator cit = m7.find(0);
		// 	if (cit == m7.end())
		// 		std::cout << "pas de clé == 0\n";
		// }
		// {
		// 	ft::map<int, char>::const_iterator cit = m7.find(1);
		// 	std::cout << "m7[" << cit->first << "] = " << cit->second << std::endl;
		// }

		// std::cout << "\t\tcount\n";
		// std::cout << "il y a " << m7.count(0) << " element avec la clé 0\n";
		// std::cout << "il y a " << m7.count(1) << " element avec la clé 1\n";
	// }
	// {
		// std::cout << "\t\tlower_bound, upper_bound et equal_range\n";
		// ft::map<int, char>::iterator low;
		// ft::map<int, char>::iterator up;
		// ft::pair<ft::map<int, char>::iterator, ft::map<int, char>::iterator> p;
		// low = m7.lower_bound(6);
		// if (low == m7.end())
		// 	std::cout << "pas de lower_bound pour 6\n";
		// up = m7.upper_bound(6);
		// if (up == m7.end())
		// 	std::cout << "pas de upper_bound pour 6\n";
		// p = m7.equal_range(6);
		// if (p.first == low && p.second == up)
		// 	std::cout << "equal_range fonctionne comme prevu\n";

		// low = m7.lower_bound(1);
		// std::cout << "lower_bound de 1 : "<< "m7[" << low->first << "] = " << low->second << std::endl;
		// up = m7.upper_bound(1);
		// std::cout << "upper_bound de 1 : "<< "m7[" << up->first << "] = " << up->second << std::endl;
		// p = m7.equal_range(1);
		// if (p.first == low && p.second == up)
		// 	std::cout << "equal_range fonctionne comme prevu\n";

		// low = m7.lower_bound(3);
		// std::cout << "lower_bound de 3 : "<< "m7[" << low->first << "] = " << low->second << std::endl;
		// up = m7.upper_bound(3);
		// std::cout << "upper_bound de 3 : "<< "m7[" << up->first << "] = " << up->second << std::endl;
		// p = m7.equal_range(3);
		// if (p.first == low && p.second == up)
		// 	std::cout << "equal_range fonctionne comme prevu\n";

		// low = m7.lower_bound(0);
		// std::cout << "lower_bound de 0 : "<< "m7[" << low->first << "] = " << low->second << std::endl;
		// up = m7.upper_bound(0);
		// std::cout << "upper_bound de 0 : "<< "m7[" << up->first << "] = " << up->second << std::endl;
		// p = m7.equal_range(0);
		// if (p.first == low && p.second == up)
		// 	std::cout << "equal_range fonctionne comme prevu\n";

		// std::cout << "\t\tlower_bound, upper_bound et equal_range version const\n";
		// {
		// 	ft::map<int, char>::const_iterator ce = m7.end();
		// 	ft::map<int, char>::const_iterator low = m7.lower_bound(6);
		// 	ft::map<int, char>::const_iterator up = m7.upper_bound(6);
		// 	ft::pair<ft::map<int, char>::const_iterator, ft::map<int, char>::const_iterator> p = m7.equal_range(6);
		// 	if (low == ce)
		// 		std::cout << "pas de lower_bound pour 6\n";
		// 	if (up == m7.end())
		// 		std::cout << "pas de upper_bound pour 6\n";
		// 	if (p.first == low && p.second == up)
		// 		std::cout << "equal_range fonctionne comme prevu\n";
		// }
		// {
		// 	ft::map<int, char>::const_iterator low = m7.lower_bound(1);
		// 	ft::map<int, char>::const_iterator up = m7.upper_bound(1);
		// 	ft::pair<ft::map<int, char>::const_iterator, ft::map<int, char>::const_iterator> p = m7.equal_range(1);
		// 	std::cout << "lower_bound de 1 : "<< "m7[" << low->first << "] = " << low->second << std::endl;
		// 	std::cout << "upper_bound de 1 : "<< "m7[" << up->first << "] = " << up->second << std::endl;
		// 	if (p.first == low && p.second == up)
		// 		std::cout << "equal_range fonctionne comme prevu\n";
		// }
		// {
		// 	ft::map<int, char>::const_iterator low = m7.lower_bound(3);
		// 	ft::map<int, char>::const_iterator up = m7.upper_bound(3);
		// 	ft::pair<ft::map<int, char>::const_iterator, ft::map<int, char>::const_iterator> p = m7.equal_range(3);
		// 	std::cout << "lower_bound de 3 : "<< "m7[" << low->first << "] = " << low->second << std::endl;
		// 	std::cout << "upper_bound de 3 : "<< "m7[" << up->first << "] = " << up->second << std::endl;
		// 	if (p.first == low && p.second == up)
		// 		std::cout << "equal_range fonctionne comme prevu\n";
		// }
		// {
		// 	// ft::map<int, char>::const_iterator ce = m7.end();
		// 	ft::map<int, char>::const_iterator low = m7.lower_bound(0);
		// 	ft::map<int, char>::const_iterator up = m7.upper_bound(0);
		// 	ft::pair<ft::map<int, char>::const_iterator, ft::map<int, char>::const_iterator> p = m7.equal_range(0);
		// 	std::cout << "lower_bound de 0 : "<< "m7[" << low->first << "] = " << low->second << std::endl;
		// 	std::cout << "upper_bound de 0 : "<< "m7[" << up->first << "] = " << up->second << std::endl;
		// 	if (p.first == low && p.second == up)
		// 		std::cout << "equal_range fonctionne comme prevu\n";
		// }
	}

	{
		// std::cout << "\ttest de get_allocator\n";
		// int psize;
		// ft::map<int,char> m8;
		// ft::pair<const int,char>* p;
		// p=m8.get_allocator().allocate(5);
		// psize = sizeof(std::map<char,int>::value_type)*5;
		// std::cout << "on a reussi une allocation de taille " << psize << " bytes.\n";
		// m8.get_allocator().deallocate(p,5);
	}

	{
		// std::cout << "\ttests des comparatifs == , !=, <, <=, > et >=\n";
		// ft::map<int, char>m1;
		// m1[1] = 'a';
		// m1[2] = 'b';
		// ft::map<int, char>m2 = m1;
		// m2[3] = 'c';
		// ft::map<int, char>m3;
		// m3[2] = 'b';
		// m3[3] = 'c';
		// ft::map<int, char>m4;
		// m4[3] = 'c';
		// m4[4] = 'd';
		// for(ft::map<int, char>::iterator it = m1.begin(); it != m1.end(); it++){
		// 	std::cout << "m1[" << it->first << "] = " << it->second << "\t";
		// }
		// std::cout << std::endl;
		// for(ft::map<int, char>::iterator it = m2.begin(); it != m2.end(); it++){
		// 	std::cout << "m2[" << it->first << "] = " << it->second << "\t";
		// }
		// std::cout << std::endl << "\t\t";
		// for(ft::map<int, char>::iterator it = m3.begin(); it != m1.end(); it++){
		// 	std::cout << "m3[" << it->first << "] = " << it->second << "\t";
		// }
		// std::cout << std::endl << "\t\t\t\t";
		// for(ft::map<int, char>::iterator it = m4.begin(); it != m1.end(); it++){
		// 	std::cout << "m4[" << it->first << "] = " << it->second << "\t";
		// }
		// std::cout << std::endl;

		// std::cout << "\t\ttests de ==\n";
		// std::cout << "m1 et m1 : " << (m1 == m1) << "\tm1 et m2 : " << (m1 == m2) << "\tm1 et m3 : " << (m1 == m3) << "\tm1 et m4 : " << (m1 == m4) << std::endl;

		// std::cout << "\t\ttests de !=\n";
		// std::cout << "m1 et m1 : " << (m1 != m1) << "\tm1 et m2 : " << (m1 != m2) << "\tm1 et m3 : " << (m1 != m3) << "\tm1 et m4 : " << (m1 != m4) << std::endl;

		// std::cout << "\t\ttest de < :\n";
		// std::cout << "m1 et m1 : " << (m1 < m1) << "\tm1 et m2 : " << (m1 < m2) << "\tm1 et m3 : " << (m1 < m3) << "\tm1 et m4 : " << (m1 < m4) << std::endl;
		// std::cout << "m2 et m2 : " << (m2 < m2) << "\tm2 et m3 : " << (m2 < m3) << "\tm2 et m4 : " << (m2 < m4) << std::endl;

	}
}
