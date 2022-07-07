#ifndef MY_AVL_TREE_H
# define MY_AVL_TREE_H

# include "pair.hpp"
# include "make_pair.hpp"

namespace ft{
	template <class P>
	struct node{
		public:
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
		
		private:
			node &	operator=(node const &src){
				this->data = src.data;
				this->lchild = src.lchild;
				this->rchild = src.rchild;
				this->parent = src.parent;
				this->depth = src.depth;
			}
	};

	template<class P>
	struct avl_iterator{
		public:
			typedef	ft::node<P>						node;
			typedef	P								value_type;
			typedef	value_type*						pointer;//?
			typedef value_type&						reference;//?
			typedef ptrdiff_t						difference_type;
			typedef std::avl_iterator	iterator_category;//?

			avl_iterator(const avl_iterator &src){this = src;}
			~avl_iterator(){}
			avl_iterator & operator=(const avl_iterator &src){

				return (*this);
			}//?
			
			avl_iterator	&operator++(){
				//?
				return (*this);
			}//?
			avl_iterator	operator++(int){
				avl_iterator tmp = *this;
				++(*this);
				return (tmp);
			}//?

			bool		operator==(avl_iterator &other){};//?
			bool		operator!=(avl_iterator &other){};//?

			value_type		&operator*(){return node.data;}
			pointer			&operator->(){return &(this->operator*())}
			
			avl_iterator(){}

			avl_iterator &	operator--(){
				// --current;
				return (*this);
			}//?
			avl_iterator	operator--(int){
				avl_iterator tmp = *this;
				++(*this);
				return (tmp);
			}//?

	};

	template <class T, class Key, class Compare, class Alloc>
	struct my_avl_tree
	{
		public:
		//attributs
			typedef	Key														key_type;
			typedef Compare													key_compare;
			typedef Alloc													allocator_type;
			typedef typename ft::node<T>									node;
			typedef Alloc													allocator_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
		
		private:
			node*				root;
			node*				begin;
			node*				end;
			allocator_type		alloc;

			int		size;//nb d'elem

		public:
			my_avl_tree(P data){//utiliser l'allocator...
				this->root = 
				r.data = data;
				this->root = &r;
				this->size = 1;
			}
			~my_avl_tree(){}

			node* getFirst() const{
				node* tmp = root;
				while (tmp->lchild != nullptr)
					tmp = tmp->lchild;
				return (tmp);
			}

			node*	getLast() const{
				node* tmp = root;
				while (tmp->rchild != nullptr)
					tmp = tmp->rchild;
				return (tmp);
			}

			node*	newNode(P data){
				node	n;
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