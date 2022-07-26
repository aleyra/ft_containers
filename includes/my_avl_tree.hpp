#ifndef MY_AVL_TREE_H
# define MY_AVL_TREE_H

# include "pair.hpp"
# include "make_pair.hpp"
# include "iterators_traits.hpp"
# include "reverse_iterator.hpp"
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
			P 		data;//sera un ft::pair dans avl_tree
			int		depth;//profondeur = nombre de node entre celui la et le descendant le plus loin

		//member function
			node():lchild(NULL), rchild(NULL), parent(NULL), data(), depth(1){}
			node(node const &src){
				*this = src;
			}
			node(P const &p):lchild(NULL), rchild(NULL), parent(NULL), data(p), depth(1){}
			~node(){}
		
		private:
			node &	operator=(node const &src){
				this->data = src.data;
				this->lchild = src.lchild;
				this->rchild = src.rchild;
				this->parent = src.parent;
				this->depth = src.depth;
				return (*this);
			}
	};
	template <class P>
	void	swap_nodes_data(ft::node<P>* n1, ft::node<P>* n2){
		ft::node<P>	tmp;
		tmp.data = n1->data;
		n1->data = n2->data;
		n2->data = tmp.data;
	}

	template<class P>
	struct avl_iterator{
		public:
			typedef P*															iterator_type;
			typedef typename std::bidirectional_iterator_tag	iterator_category;
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
				if (current->rchild != NULL){
					current = current->rchild;
					while (current->lchild != NULL)
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
			pointer			operator->(){return &(this->operator*());}
			
			avl_iterator(){}

			avl_iterator &	operator--(){
				if (current->lchild != NULL){
					current = current->lchild;
					while (current->lchild != NULL)
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

	template <class Key, class T, class Compare, class Alloc = std::allocator<T> >
	struct my_avl_tree
	{
		typedef typename Alloc::template rebind<node<pair<Key, T> > >::other	node_alloc;//pour avoir une allocator qui genere la place pour une node plutot que la place pour pair.-

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
			typedef avl_iterator<iter_value_type>							iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef Alloc													allocator_type;
			typedef avl_iterator<const iter_value_type>						const_iterator;
			typedef ft::reverse_iterator<iterator>							reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;

	
			node*				root;//a remettre en private
		private:
			node*				begin;
			node*				end;
			allocator_type		alloc;//au cas où
			node_alloc			nalloc;
			size_type			size;//nb d'elem
			Compare				comp;


		public:
		//member function
			my_avl_tree(value_type data){
				this->root = this->nalloc.allocate(1);
				this->nalloc.construct(this->root, data);
				this->root->depth = 1;
				this->root->parent = NULL;
				this->root->lchild = NULL;
				this->root->rchild = NULL;
				this->size = 1;
			}

			~my_avl_tree(){
				// std::cout << "in destructor\n";//
				// std::cout << "size = " << this->size << std::endl;//
				this->clear();
			}

			node* getFirst() const{//a mettre en private ?
				if (this->size == 0)
					return NULL;
				node*	tmp = root;
				while (tmp->lchild != NULL)
					tmp--;
				return (tmp);
			}

			node*	getLast() const{//a mettre en private ?
				if (this->size == 0)
					return NULL;
				node*	tmp = root;
				while (tmp->rchild != NULL)
					tmp++;
				return (tmp);
			}

			void	insert(value_type data){
				node*	tmp = root;
				bool	b = false;
				node*	n = NULL;//will be new node pointer
				int	rcd, lcd, max;
				while (b == false){
					if (comp(data.first, tmp->data.first)){//data < tmp.data
						if (tmp->lchild == NULL){
							tmp->lchild = this->nalloc.allocate(1);
							this->nalloc.construct(tmp->lchild, data);
							tmp->lchild->depth = 1;
							tmp->lchild->parent = tmp;
							tmp->lchild->lchild = NULL;
							tmp->lchild->rchild = NULL;
							this->size++;
							n = tmp->lchild;
							while (tmp != NULL){//pour adapter la depth
								rcd = (tmp->rchild != NULL) ? tmp->rchild->depth : 0;
								lcd = (tmp->lchild != NULL) ? tmp->lchild->depth : 0;
								max = std::max(rcd, lcd);
								// std::cout << "max = "<< max << "et parent.depth = " << tmp->depth << std::endl;
								if (tmp->depth == max + 1)
									break ;
								tmp->depth = max + 1;
								tmp = tmp->parent;
							}
							b = true;
						}
						else
							tmp = tmp->lchild;
					}
					else if (comp(tmp->data.first, data.first)){//tmp.data < data
						if (tmp->rchild == NULL){
							tmp->rchild = this->nalloc.allocate(1);
							this->nalloc.construct(tmp->rchild, data);
							tmp->rchild->depth = 1;
							tmp->rchild->parent = tmp;
							tmp->rchild->lchild = NULL;
							tmp->rchild->rchild = NULL;
							this->size++;
							n = tmp->rchild;
						while (tmp != NULL){//pour adapter la depth
								rcd = (tmp->rchild != NULL) ? tmp->rchild->depth : 0;
								lcd = (tmp->lchild != NULL) ? tmp->lchild->depth : 0;
								max = std::max(rcd, lcd);
								// std::cout << "max = "<< max << "et parent.depth = " << tmp->depth << std::endl;
								if (tmp->depth == max + 1)
									break ;
								tmp->depth = max + 1;
								tmp = tmp->parent;
							}
							b = true;
						}
						else
							tmp = tmp->rchild;
					}
					else{// n == tmp
						node* t = this->nalloc.allocate(1);
						this->nalloc.construct(t, data);
						swap_nodes_data(t, tmp);
						this->nalloc.destroy(t);
						this->nalloc.deallocate(t, 1);
						b = true;
					}
				}
				// bool isBal = isBalanced();
				// std::cout << isBal
				// if (!isBal && this->root->depth)
				// 	makeBalancedFromRoot();
				// else if (n != NULL && !isBal)
				// 	makeBalanced(n);
				node*	isBalN = isBalanced(n);
				// std::cout << "ds insert\n";//
				makeBalanced(isBalN);
			}//?

			void	erase(value_type data){//pas complet
				node*	tmp = root;
				bool	b = false;
				node*	x = NULL;//will be parent of deallocate node.
				int	rcd, lcd, max;
				while (b == false && tmp != NULL){
					if (comp(data.first, tmp->data.first) && (tmp->lchild != NULL)){//data < tmp.data
						tmp = tmp->lchild;
					}
					else if (comp(tmp->data.first, data.first) && (tmp->rchild != NULL)){//tmp.data < data
						tmp = tmp->rchild;
					}
					else{// data = tmp.data //tmp est la node a erase
						if (tmp->lchild != NULL && tmp->lchild->depth == 1){//tmp.lc existe et n'a pas d'enfant
							swap_nodes_data(tmp, tmp->lchild);
							tmp->lchild = NULL;
							this->nalloc.destroy(tmp->lchild);
							this->nalloc.deallocate(tmp->lchild, 1);
							x = tmp;
							while (tmp != NULL){//pour adapter la depth
								rcd = (tmp->rchild != NULL) ? tmp->rchild->depth : 0;
								lcd = (tmp->lchild != NULL) ? tmp->lchild->depth : 0;
								max = std::max(rcd, lcd);
								// std::cout << "max = "<< max << "et parent.depth = " << tmp->depth << std::endl;
								if (tmp->depth == max + 1)
									break ;
								tmp->depth = max + 1;
								tmp = tmp->parent;
							}
						}
						else if (tmp->depth == 1){//si tmp n'a pas d'enfants
							node*	x = tmp->parent;
							if (x->rchild == tmp)
								x->rchild = NULL;
							if (x->lchild == tmp)
								x->lchild = NULL;
							this->clear(tmp);
							tmp = x;
							while (tmp != NULL){//pour adapter la depth
								rcd = (tmp->rchild != NULL) ? tmp->rchild->depth : 0;
								lcd = (tmp->lchild != NULL) ? tmp->lchild->depth : 0;
								max = std::max(rcd, lcd);
								// std::cout << "max = "<< max << "et parent.depth = " << tmp->depth << std::endl;
								if (tmp->depth == max + 1)
									break ;
								tmp->depth = max + 1;
								tmp = tmp->parent;
							}
						}
						else {//tmp n'a pas de lc ou il a un lc qui a lui meme une descendance
							// std::cout << "\ttmp = " << tmp << " et tmp.data.first = " << tmp->data.first << std::endl;//
							node*	t = tmp->lchild;
							// std::cout << "\tt = " << t << " et t.data.first = " << t->data.first << std::endl;//
							while (t != NULL && t->rchild != NULL){
								t = t->rchild;
								// std::cout << "\tt = " << t << std::endl;//
							}
							if (t != NULL){//petite secu avant les manip
				// std::cout << "ds erase\n";//
								x = t;
								while (t != NULL){
									// std::cout << "t = " << t << "\tt.data.f = " << t->data.first << std::endl;//
									swap_nodes_data(t->parent, t);
									x = t;
									t = t->lchild;
								}
								// std::cout << "x = " << x << " et x.data.first = " << x->data.first << std::endl;//
								x = x->parent;
								// std::cout << "x = " << x << " et x.data.first = " << x->data.first << std::endl;//
								clear(x->lchild);
								// std::cout << "x.lc = " << x->lchild << std::endl;//
								tmp = x;
								while (tmp != NULL){//pour adapter la depth
									rcd = (tmp->rchild != NULL) ? tmp->rchild->depth : 0;
									lcd = (tmp->lchild != NULL) ? tmp->lchild->depth : 0;
									max = std::max(rcd, lcd);
									// std::cout << "max = "<< max << "et parent.depth = " << tmp->depth << std::endl;
									if (tmp->depth == max + 1)
										break ;
									tmp->depth = max + 1;
									tmp = tmp->parent;
								}
							}
						}
						b = true;
					}
				}
				this->size--;
				//a revoir a partir d'ici
				bool isBal = isBalanced();
				
				if (!isBal && this->root->depth == 3){
					makeBalancedFromRoot();
				}
				else{
				// 	while (x != NULL && x->depth < 4)//search for nephew or cousin or brother of deallocate node
				// 		x = x->parent;
				// 	while (x != NULL && x->depth != 1){
				// 		if (x->rchild != NULL && x->rchild->depth == x->depth - 1)
				// 			x = x->rchild;
				// 		else
				// 			x = x->lchild;
				// 	}//found it
				// 	if (x != NULL && !isBal)
				// 		makeBalanced(x);
					makeBalanced(isBalanced(x));//a verif
				}
			}

			bool	isBalanced(){
				if (this->size <= 2)
					return true;
				node*	tmp = getFirst();
				node*	last = getLast();
				node*	p;
				node*	rc;
				node*	lc;
				while (tmp != last){
					if (tmp != this->root){
						p = tmp->parent;
					// std::cout << "in isBalanced" << std::endl;
						rc = tmp->rchild;
						lc = tmp->lchild;
						if ((rc != NULL && lc != NULL) && (lc->depth - rc->depth > 1 || lc->depth - rc->depth < -1))
							return (false);
					}
					tmp++;
				}
				return (true);
			}//?

			node*	isBalanced(node* n){//from (new node) or (nephew or cousin or brother of deallocate node)
				int		rcd, lcd;

				// std::cout << "in isBalanced(node *)\n";//
				while (n != NULL && n != this->root){
					rcd = (n->rchild != NULL) ? n->rchild->depth : 0;
					lcd = (n->lchild != NULL) ? n->lchild->depth : 0;
					if (rcd - lcd > 1 || rcd - lcd < -1)
						return (n);
					n = n->parent;
				}
				return NULL;
			}
		private:

			void clear(){
				// std::cout << "in clear()\n";//
				this->clear(this->root);
				this->size = 0;
			}

			void clear(node* n){
				// std::cout << "in clear(node *)\n";//
				// std::cout << "n = " << n << " n.lc = " << n->lchild << " n.rc = " << n->rchild << std::endl;//
				if (n->lchild != NULL)
					clear(n->lchild);
				if (n->rchild != NULL)
					clear(n->rchild);
				node*	p = n->parent;
				if (p != NULL){
					if (p->lchild == n)
						p->lchild = NULL;
					if (p->rchild == n)
						p->rchild = NULL;
				}
				this->nalloc.destroy(n);
				this->nalloc.deallocate(n, 1);
				n = NULL;
				// std::cout << "clear(node *) fini\n";//
			}

			void	rightRotate(node* z){//see Left Left Case example in https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
				// std::cout << "z = " << z << std::endl;//
				node*	y = z->lchild;
				// std::cout << "y = " << y << std::endl;//
				node*	t3 = y->rchild;
				// std::cout << "t3 = " << t3 << std::endl;//
				node*	p = z->parent;
				// std::cout << "p = " << p << std::endl;//
				bool	isroot = (z == this->root) ? true : false;
				// {if (isroot)//affichage du res de isroot
				// 	std::cout << "z is root\n";//
				// else//
				// 	std::cout << "z is not root\n";}//
				y->rchild = z;
				z->lchild = t3;
				if (p != NULL){//gerer le parent de z et l'enfant du parent (anciennement z)
					if (p->lchild == z)
						p->lchild = y;
					else
						p->rchild = y;
				}
				y->parent = z->parent;
				z->parent = y;
				if (isroot){
					this->root = y;
				}
				if (t3 != NULL)
					t3->parent = z;
				// std::cout << "in rightRotate\n";//
				int	rcd, lcd, max;
				while (z != NULL){//pour adapter la depth
					rcd = (z->rchild != NULL) ? z->rchild->depth : 0;
					lcd = (z->lchild != NULL) ? z->lchild->depth : 0;
					max = std::max(rcd, lcd);
					// if (z->depth == max + 1)
					// 	break ;
					z->depth = max + 1;
					z = z->parent;
				}
			}

			void	leftRotate(node* z){//see Right Right Case example in https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
				node*	y = z->rchild;
				node*	t2 = y->lchild;
				node*	p = z->parent;
				bool	isroot = (z == this->root) ? true : false;
				y->lchild = z;
				z->rchild = t2;
				if (p != NULL){//gerer le parent de z et l'enfant du parent (anciennement z)
					if (p->lchild == z)
						p->lchild = y;
					else
						p->rchild = y;
				}
				y->parent = z->parent;
				z->parent = y;
				if (isroot){
					this->root = y;
				}
				if (t2 != NULL)
					t2->parent = z;
				int	rcd, lcd, max;
				while (z != NULL){//pour adapter la depth
					rcd = (z->rchild != NULL) ? z->rchild->depth : 0;
					lcd = (z->lchild != NULL) ? z->lchild->depth : 0;
					max = std::max(rcd, lcd);
					// if (z->depth == max + 1)
					// 	break ;
					z->depth = max + 1;
					z = z->parent;
				}
			}

			void	leftRightRotate(node* z){//see Left Right Case example in https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
				node*	y = z->lchild;
				leftRotate(y);
				rightRotate(z);
			}

			void	rightLeftRotate(node* z){//see Right Left Case example in https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
				node*	y = z->rchild;
				rightRotate(y);
				leftRotate(z);
			}

			// void	makeBalanced(node* n){//from (new node) or (nephew or cousin or brother of deallocate node)
			// 	node*	x = n->parent;
			// 	if (x == NULL)
			// 		return ;
			// 	node*	y = x->parent;
			// 	if (y == NULL)
			// 		return ;
			// 	node*	z = y->parent;
			// 	if (z == NULL)
			// 		return ;
			// 	if (z->lchild == y && y->lchild == x)//Left Left Case
			// 		rightRotate(z);
			// 	if (z->lchild == y && y->rchild == x)//Left Right Case
			// 		leftRightRotate(z);
			// 	if (z->rchild == y && y->rchild == x)//Right Right Case
			// 		leftRotate(z);
			// 	if (z->rchild == y && y->lchild == x)//Right Left Case
			// 		rightLeftRotate(z);
			// }

			void	makeBalanced(node* z){
				if (z == NULL || this->size <= 2)
					return ;
				node*	y;
				if (z->lchild == NULL || z->lchild->depth == 1){//case c or d
					y = z->rchild;
					if (y->lchild == NULL || y->lchild->depth == 1){//case c
						if (y->rchild != NULL)
							leftRotate(z);
					}
					else if (y->rchild == NULL || y->rchild->depth == 1){//case d
						if (y->lchild != NULL)
							rightLeftRotate(z);
					}
				}
				else if (z->rchild == NULL || z->rchild->depth == 1){//case a or b
					y = z->lchild;
					if (y->rchild == NULL || y->rchild->depth == 1){//case a
						if (y->lchild != NULL)
				// std::cout << "in makeBalanced(node *)\n";//
							rightRotate(z);
					}
					else if (y->lchild == NULL || y->lchild->depth == 1){//case b
						if (y->rchild != NULL)
							leftRightRotate(z);
					}
				}
			}

			void	makeBalancedFromRoot(){//fonction degueu
				if (this->root->depth != 3)
					return ;
				node*	z = this->root;
				node*	y = NULL;
				if (z->lchild != NULL){
					y = z->lchild;
					if (y->rchild == NULL)
						rightRotate(z);
					else if (y->lchild == NULL){
						node*	x = y->rchild;
						x->lchild = y;
						y->parent = x;
						x->rchild = z;
						z->parent = x;
						x->parent = NULL;
						this->root = x;
						z->lchild = NULL;
						y->rchild = NULL;
						x->depth = 2;
						y->depth = 1;
						z->depth = 1;
					}
					else {//y a deux enfants
						node*	x = y->rchild;
						node*	t = y->lchild;
						this->root = y;
						y->parent = NULL;
						y->lchild = t;
						y->rchild = z;
						y->depth = 3;
						t->parent = y;
						t->depth = 1;
						z->parent = y;
						z->lchild = x;
						z->depth = 2;
						x->parent = x;
					}
				}
				else{
					y = z->rchild;
					if (y->lchild == NULL)
						leftRotate(z);
					else if (y->rchild == NULL){
						node*	x = y->lchild;
						x->lchild = z;
						z->parent = x;
						x->rchild = y;
						y->parent = x;
						x->parent = NULL;
						this->root = x;
						z->rchild = NULL;
						y->lchild = NULL;
						x->depth = 2;
						z->depth = 1;
						y->depth = 1;
					}
					else {//y a deux enfants
						node*	x = y->lchild;
						node*	t = y->rchild;
						y = this->root;
						y->parent = NULL;
						y->depth = 3;
						y->lchild = z;
						y->rchild = t;
						t->parent = y;
						t->depth = 1;
						z->parent = y;
						z->rchild = x;
						z->depth = 2;
						x->parent = z;
					}
				}
			}
	};
}

#endif
