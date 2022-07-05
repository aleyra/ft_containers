#ifndef MY_AVL_TREE_H
# define MY_AVL_TREE_H

# include "pair.hpp"
# include "make_pair.hpp"

namespace ft{
	template <class T1>
	struct node{
		//attributs
		typedef typename node<T1>*	pointer;
		T1 		data;//clé de map
		pointer lchild;//pointeur enfant gauche à remplir avant enfant droite
		pointer rchild;//pointeur enfant droite
		pointer	parent;//pointeur parent
		int		depth;//profondeur = nombre de node entre celui la et le descendant le plus loin

		//member function
		node():lchild(nullptr), rchild(nullptr), parent(nullptr){}
		node(node const &src){
			*this = src;
		}
		~node(){}

		node &	operator=(node const &src){
			this->lchild = src.lchild;
			this->rchild = src.rchild;
			this->parent = src.parent;
			this->depth = src.depth;
			this->data = src.data;
		}
	};

	
	

}

#endif