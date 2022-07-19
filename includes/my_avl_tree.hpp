#ifndef MY_AVL_TREE_H
# define MY_AVL_TREE_H

# include "pair.hpp"
# include "make_pair.hpp"
# include "iterators_traits.hpp"
# include <algorithm>

namespace ft{
	template <class P>
	struct node{
		public:
		//attributs
			typedef node<P>*	pointer;
			pointer lchild;//pointeur enfant gauche à remplir avant enfant droite
			pointer rchild;//pointeur enfant droite
			pointer	parent;//pointeur parent
			P 		data;//clé de map
			int		depth;//profondeur = nombre de node entre celui la et le descendant le plus loin

		//member function
			node():lchild(nullptr), rchild(nullptr), parent(nullptr), data(), depth(1){}
			node(node const &src){
				*this = src;
			}
			// node(P const &p){}//a faire ?
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

	template <class P>
	void	swap_nodes_data(ft::node<P>* n1, ft::node<P>* n2){
		ft::node<P>*	tmp;
		tmp->data = n1->data;
		n1->data = n2->data;
		n2->data = tmp->data;
	}

	template<class P>
	struct avl_iterator{
		public:
			typedef P*															iterator_type;
			typedef typename std::bidirectionnal_iterator::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<P*>::value_type				value_type;
			typedef typename ft::iterator_traits<P*>::difference_type			difference_type;
			typedef typename ft::iterator_traits<P*>::pointer					pointer;
			typedef typename ft::iterator_traits<P*>::reference					reference;

		protected:
			typedef	ft::node<P>*	node;
			node					current;

			avl_iterator(const avl_iterator &src){this = src;}
			~avl_iterator(){}
			avl_iterator & operator=(const avl_iterator &src){
				current = src.current;
				return (*this);
			}
			
			avl_iterator	&operator++(){
				if (current->rchild != nullptr){
					current = current->rchild;
					while (current->lchild != nullptr)
						current = current->lchild;
						return (*this);
				}
				node	tmp = current;
				current = current->parent;
				while (current->rchild == tmp){
					tmp = current;
					current = current->parent;
				}
				return (*this);
			}//a verif
			avl_iterator	operator++(int){
				avl_iterator	tmp = *this;
				++(*this);
				return (tmp);
			}

			bool		operator==(avl_iterator &other){
				return (current == other.current);
			};
			bool		operator!=(avl_iterator &other){
				return (current != other.current);
			};

			value_type		&operator*(){return current->data;}
			pointer			operator->(){return &(this->operator*())}
			
			avl_iterator(){}

			avl_iterator &	operator--(){
				if (current->lchild != nullptr){
					current = current->lchild;
					while (current->lchild != nullptr)
						current = current->rchild;
						return (*this);
				}
				node	tmp = current;
				current = current->parent;
				while (current->lchild == tmp){
					tmp = current;
					current = current->parent;
				}
				return (*this);
			}//a verif
			avl_iterator	operator--(int){
				avl_iterator	tmp = *this;
				++(*this);
				return (tmp);
			}
	};

	template <class Key, class T, class Compare, class Alloc = std::allocator<T>>
	struct my_avl_tree
	{
		typedef typename Alloc::template rebind<node<pair<Key, T> > >::other	node_alloc;//pour avoir une allocator qui genere lq plce pour une node plutot que la place pour pair.-

		public:
		//attributs
			typedef Key														key_type;
			typedef T														mapped_type;
			typedef ft::pair<key_type, mapped_type>							value_type;
			typedef ft::pair<const key_type, mapped_type>					iter_value_type;//sert quand on cree les iterator pour pourvoir generer des version const
			typedef typename ft::node<value_type>							node;
		 	typedef node*													pointer;
			typedef const node*												const_pointer;
			typedef node&													reference;
			typedef const node&												const_reference;
			typedef size_t													size_type;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef Alloc													allocator_type;
			typedef avl_iterator<iter_value_type>							iterator;
			typedef avl_iterator<const iter_value_type>						const_iterator;
			typedef ft::reverse_iterator<iterator>							reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;

		
		private:
			node*				root;
			node*				begin;
			node*				end;
			allocator_type		alloc;//au cas où
			node_alloc			nalloc;
			size_type			size;//nb d'elem
			Compare				comp;


		public:
		//member function
			my_avl_tree(P data){
				this->root = this->nalloc.allocate(1);
				this->nalloc.construct(&this->root->data, data);
				this->root->depth = 1;
				this->root->parent = nullptr;
				this->root->lchild = nullptr;
				this->root->rchild = nullptr;
				this->size = 1;
			}

			~my_avl_tree(){
				this->clear();
			}

			node* getFirst() const{
				node*	tmp = root;
				while (tmp->lchild != nullptr)
					tmp--;
				return (tmp);
			}

			node*	getLast() const{
				node*	tmp = root;
				while (tmp->rchild != nullptr)
					tmp++;
				return (tmp);
			}

			void	insert(P data){
				node*	tmp = root;
				bool	b = false;
				node*	n = nullptr;//will be new node pointer
				while (b == false){
					if (comp(data, tmp->data)){//data < tmp.data
						if (tmp->lchild == nullptr){
							tmp->lchild = this->nalloc.allocate(1);
							this->nalloc.construct(&tmp->lchild->data, data);
							tmp->lchild->depth = 1;
							tmp->lchild->parent = tmp;
							tmp->lchild->lchild = nullptr;
							tmp->lchild->rchild = nullptr;
							this->size++;
							n = tmp->lchild;
							while (tmp != nullptr){//pour adapter depth
								if (tmp->depth == tmp->rchild->depth || tmp->depth == tmp->lchild->depth)
									tmp->depth++;
								tmp = tmp->parent;
							}
							b = true;
						}
						else
							tmp = tmp->lchild;
					}
					else if (comp(tmp->data, data)){//tmp.data < data
						if (tmp->rchild == nullptr){
							tmp->rchild = this->nalloc.allocate(1);
							this->nalloc.construct(&tmp->rchild->data, data);
							tmp->rchild->depth = 1;
							tmp->rchild->parent = tmp;
							tmp->rchild->lchild = nullptr;
							tmp->rchild->rchild = nullptr;
							this->size++;
							n = tmp->rchild;
							while (tmp != nullptr){//pour adapter depth
								if (tmp->depth == tmp->rchild->depth || tmp->depth == tmp->lchild->depth)
									tmp->depth++;
								tmp = tmp->parent;
							}
							b = true;
						}
						else
							tmp = tmp->rchild;
					}
					else{// n == tmp
						this->nalloc.destroy(&(tmp->data));
						this->nalloc.construct(&(tmp->data), data);
						b = true;
					}
				}
				if (n!= nullptr && !isBalanced())
					makeBalanced(n);
			}//?

			void	erase(P data){//revoir les cas ou l'arbre est moins profond : root->depth <= 3
				node*	tmp = root;
				bool	b = false;
				node*	x = nullptr;//will be parent of deallocate node.
				int	rcd, lcd, max;
				while (b == false && tmp != nullptr){
					if (comp(data, tmp->data) && (tmp->lchild != nullptr)){//data < tmp.data
						tmp = tmp->lchild;
					}
					else if (comp(tmp->data, data) && (tmp->rchild != nullptr)){//tmp.data < data
						tmp = tmp->rchild;
					}
					else{// data = tmp.data
						if (tmp->lchild != nullptr && tmp->lchild->depth == 1){//lc existe et n'a pas d'enfant
							this->nalloc.destroy(&(tmp->data));
							this->nalloc.construct(&(tmp->data), tmp->lchild->data);
							this->nalloc.destroy(&(tmp->lchild->data));
							this->nalloc.deallocate(tmp->lchild, 1);
							tmp->lchild = nullptr;
							x = tmp;
							while (tmp != nullptr){//pour adapter la depth
								rcd = (tmp->rchild != nullptr) ? tmp->rchild->depth : 0;
								lcd = (tmp->lchild != nullptr) ? tmp->lchild->depth : 0;
								max = std::max(rcd, lcd);
								if (tmp->depth == max + 1)
									break ;
								tmp->depth = max + 1;
							}
							b = true;
						}
						else {
							node*	t = tmp->lchild;
							while (t != nullptr && t->rchild != nullptr){
								t = t->rchild;
							}
							if (t != nullptr){//petite secu avant les manip
								this->nalloc.destroy(&(tmp->data));
								this->nalloc.construct(&(tmp->data), t->data);
								this->nalloc.destroy(&(t->data));
								x = t->parent;
								this->nalloc.deallocate(t, 1);
								x->rchild = nullptr;
								t = x;
								while (t != nullptr){//pour adapter la depth
									rcd = (t->rchild != nullptr) ? t->rchild->depth : 0;
									lcd = (t->lchild != nullptr) ? t->lchild->depth : 0;
									max = std::max(rcd, lcd);
									if (t->depth == max + 1)
										break ;
									t->depth = max + 1;
								}
								b = true;
							}
						}
					}
				}
				this->size--;
				while (x != nullptr && x->depth < 4)//search for nephew or cousin or brother of deallocate node
					x = x->parent;
				while (x != nullptr && x->depth != 1){
					if (x->rchild->depth == x->depth - 1)
						x = x->rchild;
					else
						x = x->lchild;
				}//found it
				if (x != nullptr && !isBalanced())
					makeBalanced(x);
			}

		private:
			bool	isBalanced(){
				node*	tmp = getFirst();
				node*	last = getLast();
				node*	p;
				node*	rc;
				node*	lc;
				while (tmp != last){
					p = tmp->parent;
					rc = p->rchild;
					lc = p->lchild;
					if ((rc != nullptr && lc != nullptr) && (lc->depth - rc->depth > 1 || lc->depth - rc->depth < -1))
						return (false);
					tmp++;
				}
				return (true);
			}//?

			void clear(){
				this->clear(this->root);
				this->size = 0;
			}

			void clear(node* n){
				if (n->lchild != nullptr)
					clear(n->lchild);
				if (n->rchild != nullptr)
					clear(n->rchild);
				this->nalloc.destroy(&(n->data));
				this->nalloc.deallocate(n, 1);
				n = nullptr;
			}

			void rightRotate(node* z){//see Left Left Case example in https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
				node*	y = z->lchild;
				node*	t3 = y->rchild;
				node*	p = z->parent;
				y->rchild = z;
				z->lchild = t3;
				if (p != nullptr){//gerer le parent de z et l'enfant du parent (anciennement z)
					if (p->lchild == z)
						p->lchild = y;
					else
						p->rchild = y;
				}
				y->parent = z->parent;
				z->parent = y;
				t3->parent = z;
				int	rcd, lcd, max;
				while (z != nullptr){//pour adapter la depth
					rcd = (z->rchild != nullptr) ? z->rchild->depth : 0;
					lcd = (t->lchild != nullptr) ? z->lchild->depth : 0;
					max = std::max(rcd, lcd);
					if (z->depth == max + 1)
						break ;
					z->depth = max + 1;
				}
			}

			void leftRotate(node* z){//see Right Right Case example in https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
				node*	y = z->rchild;
				node*	t2 = y->lchild;
				node*	p = z->parent;
				y->lchild = z;
				z->rchild = t2;
				if (p != nullptr){//gerer le parent de z et l'enfant du parent (anciennement z)
					if (p->lchild == z)
						p->lchild = y;
					else
						p->rchild = y;
				}
				y->parent = z->parent;
				z->parent = y;
				t2->parent = z;
				int	rcd, lcd, max;
				while (z != nullptr){//pour adapter la depth
					rcd = (z->rchild != nullptr) ? z->rchild->depth : 0;
					lcd = (t->lchild != nullptr) ? z->lchild->depth : 0;
					max = std::max(rcd, lcd);
					if (z->depth == max + 1)
						break ;
					z->depth = max + 1;
				}
			}

			void leftRightRotate(node* z){//see Left Right Case  example in https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
				node*	y = z->lchild;
				leftRotate(y);
				rightRotate(z);
			}

			void rightLeftRotate(node* z){//see Right Left Case example in https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
				node*	y = z->rchild;
				rightRotate(y);
				leftRotate(z);
			}

			void	makeBalanced(node* n){//from (new node) or (nephew or cousin or brother of deallocate node)
				node*	x = n->parent;
				if (x == nullptr)
					return ;
				node*	y = x->parent;
				if (y == nullptr)
					return ;
				node*	z = y->parent;
				if (z == nullptr)
					return ;
				if (z->lchild == y && y->lchild == x)//Left Left Case
					rightRotate(z);
				if (z->lchild == y && y->rchild == x)//Left Right Case
					leftRightRotate(z);
				if (z->rchild == y && y->rchild == x)//Right Right Case
					leftRotate(z);
				if (z->rchild == y && y->lchild == x)//Right Left Case
					rightLeftRotate(z);
			}
	};
}

#endif
