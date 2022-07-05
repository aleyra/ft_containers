#ifndef MY_AVL_TREE_H
# define MY_AVL_TREE_H

# include "pair.hpp"
# include "make_pair.hpp"

namespace ft{
	template <class P>
	struct node{
		//attributs
		typedef node<P>*	pointer;
		P 		data;//clé de map
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
			this->data = src.data;
			this->lchild = src.lchild;
			this->rchild = src.rchild;
			this->parent = src.parent;
			this->depth = src.depth;
		}
	};

	template <class P>
	struct my_avl_tree
	{
		//attributs
		typedef typename ft::node<P>	_node;
		_node*	root;
		_node*	begin;
		_node*	end;

		int		size;//nb d'elem

		my_avl_tree(P data){//utiliser l'allocator...
			_node	r;
			r.data = data;
			this->root = &r;
			this->size = 1;
		}
		~my_avl_tree(){}

		_node* getFirst() const{
			_node* tmp = root;
			while (tmp->lchild != nullptr)
				tmp = tmp->lchild;
			return (tmp);
		}

		_node*	getLast() const{
			_node* tmp = root;
			while (tmp->rchild != nullptr)
				tmp = tmp->rchild;
			return (tmp);
		}

		_node*	newNode(P data){
			_node	n;
			n.data = data;
			return (n);
		}

		bool	isBalanced(){
			//pour tous les nodes
			//check si la diff entre la depth les deux enfants est compris entre -1 et 1
			//si c'est pas le cas return (false);

			//la question c'est comment naviguer...
			//en recursif ?
			return (true);
		}//?

		void	makeBalanced(){}//?
	};
	

}

#endif