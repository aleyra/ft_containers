#include <iostream>
#include "my_avl_tree.hpp"
#include "my_tests.hpp"

void	print_node(ft::node<ft::pair<int,char>> *n){
	std::cout << "adresse de la node : " << n
		<< "/ndata de la node : ";
	display_pair_int_char(n->data);
	std::cout << "adresse de rchild : " << n->rchild
		<<"\nadresse de lchild : " << n->lchild << std::endl;
}

void test_tree(){
	ft::my_avl_tree<int, char>	t(10, 'a');

	print_node(t->root);
	t->insert(11, 'b');
	print_node(t->root);
	
}