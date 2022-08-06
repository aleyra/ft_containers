#include <iostream>
# include <map>//
#include "avl_tree.hpp"
#include "my_tests.hpp"

void	display_pair_int_char(const ft::pair<int, char> & p){
	std::cout << "(" << p.first << ", " << p.second << ")" << std::endl;
}

// void	print_node(ft::node<ft::pair<int,char> > *n){
// 	std::cout << "data de la node : ";
// 	display_pair_int_char(n->data);
// 	std::cout << "\tadresse de la node : " << n
// 		<< "\n\tdepth de la node : " << n->depth
// 		<< "\n\tadresse du parent : " << n->parent
// 		<< "\n\tadresse de lchild : " << n->lchild 
// 		<< "\n\tadresse de rchild : " << n->rchild << std::endl;
// }

void test_tree(){
	// {ft::avl_tree<int, char, std::less<int> >	t(ft::make_pair(10, 'a'));

	// // // t.erase(10);
	// // // std::cout << "root = " << t.root << std::endl;
	// // // t.insert(ft::make_pair(10, 'a'));
	// // // print_node(t.root);
	// t.insert(ft::make_pair(12, 'b'));
	// // {print_node(t.root);
	// // print_node(t.root->rchild);}
	// t.insert(ft::make_pair(9, 'c'));
	// // {print_node(t.root);
	// // print_node(t.root->rchild);
	// // print_node(t.root->lchild);}
	// std::cout << "ajout de 7 et 14\n";
	// t.insert(ft::make_pair(7, 'd'));
	// t.insert(ft::make_pair(14, 'e'));
	// // {print_node(t.root);
	// // print_node(t.root->lchild);
	// // print_node(t.root->lchild->lchild);
	// // print_node(t.root->rchild);
	// // print_node(t.root->rchild->rchild);}
	// std::cout << "ajout de 6\n";
	// t.insert(ft::make_pair(6, 'f'));
	// // {print_node(t.root);
	// // std::cout << "\nlchild de root\n";
	// // print_node(t.root->lchild);
	// // std::cout << "\nlchild de lchild de root\n";
	// // print_node(t.root->lchild->lchild);
	// // std::cout << "\nrchild de lchild de root\n";
	// // print_node(t.root->lchild->rchild);
	// // std::cout << "\nrchild de root\n";
	// // print_node(t.root->rchild);
	// // print_node(t.root->rchild->rchild);}
	// std::cout << "ajout de 8\n";
	// t.insert(ft::make_pair(8, 'g'));
	// // {print_node(t.root);
	// // std::cout << "\nlchild de root\n";
	// // print_node(t.root->lchild);
	// // std::cout << "\nlchild de lchild de root\n";
	// // print_node(t.root->lchild->lchild);
	// // std::cout << "\nrchild de lchild de root\n";
	// // print_node(t.root->lchild->rchild);
	// // std::cout << "\nlchild de rchild de lchild de root\n";
	// // print_node(t.root->lchild->rchild->lchild);}
	// // {std::cout << "suppression de 8\n";
	// // t.erase(8);
	// // print_node(t.root);
	// // std::cout << "\nlchild de root\n";
	// // print_node(t.root->lchild);
	// // std::cout << "\nlchild de lchild de root\n";
	// // print_node(t.root->lchild->lchild);
	// // std::cout << "\nrchild de lchild de root\n";
	// // print_node(t.root->lchild->rchild);}
	// // {std::cout << "suppression de 9\n";
	// // t.erase(9);
	// // print_node(t.root);
	// // std::cout << "\nlchild de root\n";
	// // print_node(t.root->lchild);
	// // std::cout << "\nlchild de lchild de root\n";
	// // print_node(t.root->lchild->lchild);
	// // std::cout << "\nrchild de lchild de root\n";
	// // print_node(t.root->lchild->rchild);}
	// std::cout << "ajout de 5\n";
	// t.insert(ft::make_pair(5, 'j'));
	// // {print_node(t.root->lchild->lchild);
	// // print_node(t.root->lchild->lchild->lchild);}
	// // {std::cout << "suppression de 7\n";
	// // t.erase(7);
	// // print_node(t.root);
	// // std::cout << "\nlchild de root\n";
	// // print_node(t.root->lchild);
	// // std::cout << "\nrchild de lchild de root\n";
	// // print_node(t.root->lchild->rchild);
	// // std::cout << "\nlchild de rchild de lchild de root\n";
	// // print_node(t.root->lchild->rchild->lchild);
	// // std::cout << "\nlchild de lchild de root\n";
	// // print_node(t.root->lchild->lchild);
	// // std::cout << "\nrchild de root\n";
	// // print_node(t.root->rchild);
	// // std::cout << "\nrchild de rchild de root\n";
	// // print_node(t.root->rchild->rchild);}
	// std::cout << "ajout de 11, 13 et 15\n";
	// t.insert(ft::make_pair(11, 'l'));
	// t.insert(ft::make_pair(13, 'm'));
	// t.insert(ft::make_pair(15, 'n'));
	// // {print_node(t.root);
	// // std::cout << "\nrchild de root\n";
	// // print_node(t.root->rchild);
	// // std::cout << "\nlchild de rchild de root\n";
	// // print_node(t.root->rchild->lchild);
	// // std::cout << "\nrchild de rchild de root\n";
	// // print_node(t.root->rchild->rchild);
	// // std::cout << "\nlchild de rchild de rchild de root\n";
	// // print_node(t.root->rchild->rchild->lchild);
	// // std::cout << "\nrchild de rchild de rchild de root\n";
	// // print_node(t.root->rchild->rchild->rchild);}
	// // {std::cout << "suppression de 13\n";
	// // t.erase(13);
	// // print_node(t.root);
	// // std::cout << "\nrchild de root\n";
	// // print_node(t.root->rchild);
	// // std::cout << "\nrchild de rchild de root\n";
	// // print_node(t.root->rchild->rchild);}
	// // {std::cout << "suppression de 15\n";
	// // t.erase(15);
	// // print_node(t.root);
	// // std::cout << "\nrchild de root\n";
	// // print_node(t.root->rchild);
	// // std::cout << "\nrchild de rchild de root\n";
	// // print_node(t.root->rchild->rchild);}
	// // {std::cout << "suppression de 14\n";
	// // t.erase(14);
	// // print_node(t.root);
	// // std::cout << "\nrchild de root\n";
	// // print_node(t.root->rchild);
	// // std::cout << "\nrchild de rchild de root\n";
	// // print_node(t.root->rchild->rchild);
	// // std::cout << "\nrchild de rchild de rchild de root\n";
	// // print_node(t.root->rchild->rchild->rchild);}
	// // {std::cout << "suppression de 12\n";
	// // t.erase(12);
	// // print_node(t.root);
	// // std::cout << "\nrchild de root\n";
	// // print_node(t.root->rchild);
	// // std::cout << "\nrchild de rchild de root\n";
	// // print_node(t.root->rchild->rchild);
	// // std::cout << "\nlchild de rchild de root\n";
	// // print_node(t.root->rchild->lchild);
	// // std::cout << "\nrchild de lchild de rchild de root\n";
	// // print_node(t.root->rchild->lchild->rchild);}
	// }

	// {std::cout << "creation d'un arbre avec 15 nodes allant de 1 à 15\n";
	// 	ft::avl_tree<int, char, std::less<int> >	t(ft::make_pair(10, 'a'));
	// 	t.insert(ft::make_pair(20, 'b'));
	// 	t.insert(ft::make_pair(30, 'c'));
	// 	t.insert(ft::make_pair(40, 'd'));
	// 	t.insert(ft::make_pair(50, 'e'));
	// 	t.insert(ft::make_pair(60, 'f'));
	// 	t.insert(ft::make_pair(70, 'g'));
	// 	// std::cout << "\nca va casser\n";
	// 	t.insert(ft::make_pair(80, 'h'));
	// 	t.insert(ft::make_pair(90, 'i'));
	// 	t.insert(ft::make_pair(100, 'j'));
	// 	t.insert(ft::make_pair(110, 'k'));
	// 	t.insert(ft::make_pair(120, 'l'));
	// 	t.insert(ft::make_pair(130, 'm'));
	// 	t.insert(ft::make_pair(140, 'n'));
	// 	t.insert(ft::make_pair(150, 'o'));
	// 	// {
	// 	// 	t.insert(ft::make_pair(66, 'o'));
	// 	// 	t.insert(ft::make_pair(65, 'o'));
	// 	// }
	// 	t.insert(ft::make_pair(55, 'o'));
	// 	t.insert(ft::make_pair(54, 'o'));
	// 	// std::cout << "node\n";
	// 	// print_node(t.root->lchild->rchild->rchild);
	// 	// std::cout << "son lc\n";
	// 	// print_node(t.root->lchild->rchild->rchild->lchild);
	// 	// std::cout << "son rc\n";
	// 	// print_node(t.root->lchild->rchild->rchild->rchild);
	// }

	// {std::cout << "test du constructeur par copie et celui avec une range\n";
	// 	ft::avl_tree<int, char, std::less<int> >	t1(ft::make_pair(1, 'a'));
	// 	t1.insert(ft::make_pair(2, 'b'));
	// 	t1.insert(ft::make_pair(3, 'c'));
	// 	t1.insert(ft::make_pair(4, 'd'));
	// 	t1.insert(ft::make_pair(5, 'e'));
	// 	t1.insert(ft::make_pair(6, 'f'));
	// 	t1.insert(ft::make_pair(7, 'g'));
	// 	print_node(t1.root);
	// 	print_node(t1.root->lchild);
	// 	print_node(t1.root->lchild->lchild);
	// 	print_node(t1.root->lchild->rchild);
	// 	print_node(t1.root->rchild);
	// 	print_node(t1.root->rchild->lchild);
	// 	print_node(t1.root->rchild->rchild);
		
		// {std::cout << "test du constructeur par copie\n";
		// ft::avl_tree<int, char, std::less<int> >	t2(t1);
		// print_node(t2.root);
		// print_node(t2.root->lchild);
		// print_node(t2.root->lchild->lchild);
		// print_node(t2.root->lchild->rchild);
		// print_node(t2.root->rchild);
		// print_node(t2.root->rchild->lchild);
		// print_node(t2.root->rchild->rchild);}
		
		// {std::cout << "test de l'assignateur par copie\n";
		// ft::avl_tree<int, char, std::less<int> >	t3(ft::make_pair(1, 'a'));
		// print_node(t3.root);
		// t3 = t1;
		// print_node(t3.root);
		// print_node(t3.root->rchild->rchild);}
	
		// {std::cout << "test du constructeur par range\n";
		// ft::avl_tree<int, char, std::less<int> >	t4(t1.begin(), t1.end(), t1.getComp());
		// print_node(t4.root);
		// print_node(t4.root->lchild);
		// print_node(t4.root->lchild->lchild);
		// print_node(t4.root->lchild->rchild);
		// print_node(t4.root->rchild);
		// print_node(t4.root->rchild->lchild);
		// print_node(t4.root->rchild->rchild);}
	// }

	// {
	// 	ft::avl_tree<int, char, std::less<int> >	t1(ft::make_pair(1, 'a'));
	// 	t1.insert(ft::make_pair(2, 'b'));
	// 	t1.insert(ft::make_pair(3, 'c'));
	// 	t1.insert(ft::make_pair(4, 'd'));
	// 	t1.insert(ft::make_pair(5, 'e'));
	// 	t1.insert(ft::make_pair(6, 'f'));
	// 	t1.insert(ft::make_pair(7, 'g'));

		 
	// }

}