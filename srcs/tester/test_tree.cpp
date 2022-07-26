#include <iostream>
#include "my_avl_tree.hpp"
#include "my_tests.hpp"

void	display_pair_int_char(ft::pair<int, char> p){
	std::cout << "(" << p.first << ", " << p.second << ")" << std::endl;
}

void	print_node(ft::node<ft::pair<int,char> > *n){
	std::cout << "data de la node : ";
	display_pair_int_char(n->data);
	std::cout << "\tadresse de la node : " << n
		<< "\n\tdepth de la node : " << n->depth
		<< "\n\tadresse du parent : " << n->parent
		<< "\n\tadresse de rchild : " << n->rchild
		<< "\n\tadresse de lchild : " << n->lchild << std::endl;
}

void test_tree(){
	ft::my_avl_tree<int, char, std::less<int> >	t(ft::make_pair(10, 'a'));

	// print_node(t.root);
	t.insert(ft::make_pair(12, 'b'));
	// {print_node(t.root);
	// print_node(t.root->rchild);}
	t.insert(ft::make_pair(9, 'c'));
	// {print_node(t.root);
	// print_node(t.root->rchild);
	// print_node(t.root->lchild);}
	std::cout << "ajout de 7 et 12\n";
	t.insert(ft::make_pair(7, 'd'));
	t.insert(ft::make_pair(14, 'e'));
	// {print_node(t.root);
	// print_node(t.root->lchild);
	// print_node(t.root->lchild->lchild);
	// print_node(t.root->rchild);
	// print_node(t.root->rchild->rchild);}
	std::cout << "ajout de 6\n";
	t.insert(ft::make_pair(6, 'f'));
	// {print_node(t.root);
	// std::cout << "\nlchild de root\n";
	// print_node(t.root->lchild);
	// std::cout << "\nlchild de lchild de root\n";
	// print_node(t.root->lchild->lchild);
	// std::cout << "\nrchild de lchild de root\n";
	// print_node(t.root->lchild->rchild);
	// std::cout << "\nrchild de root\n";
	// print_node(t.root->rchild);
	// print_node(t.root->rchild->rchild);}
	std::cout << "ajout de 8\n";
	t.insert(ft::make_pair(8, 'g'));
	// {print_node(t.root);
	// std::cout << "\nlchild de root\n";
	// print_node(t.root->lchild);
	// std::cout << "\nlchild de lchild de root\n";
	// print_node(t.root->lchild->lchild);
	// std::cout << "\nrchild de lchild de root\n";
	// print_node(t.root->lchild->rchild);
	// std::cout << "\nlchild de rchild de lchild de root\n";
	// print_node(t.root->lchild->rchild->lchild);}
	// {std::cout << "suppression de 8\n";
	// t.erase(ft::make_pair(8, 'h'));
	// print_node(t.root);
	// std::cout << "\nlchild de root\n";
	// print_node(t.root->lchild);
	// std::cout << "\nlchild de lchild de root\n";
	// print_node(t.root->lchild->lchild);
	// std::cout << "\nrchild de lchild de root\n";
	// print_node(t.root->lchild->rchild);}
	// {std::cout << "suppression de 9\n";
	// t.erase(ft::make_pair(9, 'i'));
	// print_node(t.root);
	// std::cout << "\nlchild de root\n";
	// print_node(t.root->lchild);
	// std::cout << "\nlchild de lchild de root\n";
	// print_node(t.root->lchild->lchild);
	// std::cout << "\nrchild de lchild de root\n";
	// print_node(t.root->lchild->rchild);}
	std::cout << "ajout de 5\n";
	t.insert(ft::make_pair(5, 'j'));
	// {print_node(t.root->lchild->lchild);
	// print_node(t.root->lchild->lchild->lchild);}
	// {std::cout << "suppression de 7\n";
	// t.erase(ft::make_pair(7, 'k'));
	// print_node(t.root);
	// std::cout << "\nlchild de root\n";
	// print_node(t.root->lchild);
	// std::cout << "\nrchild de lchild de root\n";
	// print_node(t.root->lchild->rchild);
	// std::cout << "\nlchild de rchild de lchild de root\n";
	// print_node(t.root->lchild->rchild->lchild);
	// std::cout << "\nlchild de lchild de root\n";
	// print_node(t.root->lchild->lchild);
	// std::cout << "\nrchild de root\n";
	// print_node(t.root->rchild);
	// std::cout << "\nrchild de rchild de root\n";
	// print_node(t.root->rchild->rchild);}
	std::cout << "ajout de 11, 13 et 15\n";
	t.insert(ft::make_pair(11, 'l'));
	t.insert(ft::make_pair(13, 'm'));
	t.insert(ft::make_pair(15, 'n'));
	// {print_node(t.root);
	// std::cout << "\nrchild de root\n";
	// print_node(t.root->rchild);
	// std::cout << "\nlchild de rchild de root\n";
	// print_node(t.root->rchild->lchild);
	// std::cout << "\nrchild de rchild de root\n";
	// print_node(t.root->rchild->rchild);
	// std::cout << "\nlchild de rchild de rchild de root\n";
	// print_node(t.root->rchild->rchild->lchild);
	// std::cout << "\nrchild de rchild de rchild de root\n";
	// print_node(t.root->rchild->rchild->rchild);}
	// {std::cout << "suppression de 13\n";
	// t.erase(ft::make_pair(13, 'o'));
	// print_node(t.root);
	// std::cout << "\nrchild de root\n";
	// print_node(t.root->rchild);
	// std::cout << "\nrchild de rchild de root\n";
	// print_node(t.root->rchild->rchild);}
	{std::cout << "suppression de 13\n";
	t.erase(ft::make_pair(15, 'p'));
	print_node(t.root);
	std::cout << "\nrchild de root\n";
	print_node(t.root->rchild);
	std::cout << "\nrchild de rchild de root\n";
	print_node(t.root->rchild->rchild);}



	// if (t.isBalanced() == true) std::cout << "true" <<std::endl;
}