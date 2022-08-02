#ifndef MY_AVL_TREE_H
# define MY_AVL_TREE_H

# include "pair.hpp"
# include "make_pair.hpp"
# include "iterators_traits.hpp"
# include "reverse_iterator.hpp"
# include <algorithm>
# include "enable_if.hpp"
# include "is_integral.hpp"

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
			node(P const &p){
				this->lchild = NULL;
				this->rchild = NULL;
				this->parent = NULL;
				this->data = p;
				this->depth = 1;
			}//:lchild(NULL), rchild(NULL), parent(NULL), data(p), depth(1){} je sais pas pourquoi mais ça marchait pas...
			~node(){}//virtual enlevé

			void	swap(node & n){
				node	tmp = n;
				n = this;
				this = n;
			}
		
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

	template<class P, class cont>//class cont pour le tour de magie et renvoyer le bon type pour avl_tree::begin et avl_tree::end
	struct avl_iterator{
		public:
			typedef P													iterator_type;
			typedef typename std::bidirectional_iterator_tag			iterator_category;
			typedef typename ft::iterator_traits<P>::value_type			value_type;
			typedef typename ft::iterator_traits<P>::difference_type	difference_type;
			typedef typename ft::iterator_traits<P>::pointer			pointer;
			typedef typename ft::iterator_traits<P>::reference			reference;

		protected:
			typedef	ft::node<P>*						node;
			typedef	ft::node<typename cont::value_type>	node_type;//pour le tour de magie et renvoyer le bon type pour avl_tree::begin et avl_tree::end
			typedef ft::node<value_type>				node_grr;//creation de ca parce que conflit de type avec current pour operator*
			node_type*									current;

		public:
			avl_iterator(const avl_iterator &src){*this = src;}
			virtual ~avl_iterator(){}
			avl_iterator & operator=(const avl_iterator &src){
				current = src.current;
				return (*this);
			}
			
			avl_iterator	&operator++(){
				if (current->rchild != NULL){
					current = current->rchild;
					while (current && current->lchild != NULL)
						current = current->lchild;
					return (*this);
				}
				node_type*	tmp = current;
				current = current->parent;
				while (current && current->rchild == tmp){//merci hébriel
					tmp = current;
					current = current->parent;
				}
				return (*this);
			}
			avl_iterator	operator++(int){
				avl_iterator	tmp = *this;
				++(*this);
				return (tmp);
			}

			bool		operator==(const avl_iterator &other){
				return (current == other.current);
			};
			bool		operator!=(const avl_iterator &other){
				return (current != other.current);
			};

			value_type		&operator*(){return ((node_grr *)current)->data;}//j'ai du cast en node_grr et creer ce type expres !
			pointer			operator->(){return &(this->operator*());}
			
			avl_iterator(){}

			avl_iterator &	operator--(){
				if (current->lchild != NULL){
					current = current->lchild;
					while (current && current->lchild != NULL)
						current = current->rchild;
					return (*this);
				}
				node_type*	tmp = current;
				current = current->parent;
				while (current && current->lchild == tmp){//merci hébriel
					tmp = current;
					current = current->parent;
				}
				return (*this);
			}
			avl_iterator	operator--(int){
				avl_iterator	tmp = *this;
				--(*this);
				return (tmp);
			}
			//ajouté pour le besoin
			avl_iterator(node_type* n){current = n;}//fin du tour de magie

			node_type*	base(){return current;}
			node_type*	base() const {return current;}
	};

	template<class P, class cont>
	struct avl_const_iterator{//parce que c'est debile. Créé à partir d'alv_iterator
		// friend class avl_iterator<P, cont>;//friend class permet d'utiliser les attributs privates et protected
		
		public:
			typedef P													iterator_type;
			typedef typename std::bidirectional_iterator_tag			iterator_category;
			typedef typename ft::iterator_traits<P>::value_type			value_type;
			typedef typename ft::iterator_traits<P>::difference_type	difference_type;
			typedef typename ft::iterator_traits<P>::pointer			pointer;
			typedef typename ft::iterator_traits<P>::reference			reference;

		protected:
			typedef	ft::node<P>*						node;
			typedef	ft::node<typename cont::value_type>	node_type;
			typedef ft::node<value_type>				node_grr;
			typedef	avl_iterator<P, cont>				it_normal;
			node_type*									current;

		public:
			avl_const_iterator(const avl_const_iterator &src){*this = src;}
			virtual ~avl_const_iterator(){}
			avl_const_iterator & operator=(const avl_const_iterator &src){
				current = src.current;
				return (*this);
			}
			
			avl_const_iterator	&operator++(){
				if (current->rchild != NULL){
					current = current->rchild;
					while (current->lchild != NULL)
						current = current->lchild;
					return (*this);
				}
				node_type*	tmp = current;
				current = current->parent;
				while (current && current->rchild == tmp){//merci hébriel. Leçon du jour - rappel : ne pas oublié de vérifier l'existence avant utilisation
					tmp = current;
					current = current->parent;
				}
				return (*this);
			}
			avl_const_iterator	operator++(int){
				avl_const_iterator	tmp = *this;
				++(*this);
				return (tmp);
			}

			bool		operator==(const avl_const_iterator &other){
				return (current == other.current);
			};
			bool		operator!=(const avl_const_iterator &other){
				return (current != other.current);
			};

			value_type		&operator*(){return ((node_grr *)current)->data;}
			pointer			operator->(){return &(this->operator*());}
			
			avl_const_iterator(){}

			avl_const_iterator &	operator--(){
				if (current->lchild != NULL){
					current = current->lchild;
					while (current && current->lchild != NULL)
						current = current->rchild;
					return (*this);
				}
				node_type*	tmp = current;
				current = current->parent;
				while (current && current->lchild == tmp){
					tmp = current;
					current = current->parent;
				}
				return (*this);
			}
			avl_const_iterator	operator--(int){
				avl_const_iterator	tmp = *this;
				--(*this);
				return (tmp);
			}

			avl_const_iterator(node_type* n){current = n;}

			avl_const_iterator(it_normal const &it){
				current = it.base();
			}

			node_type*	base(){return current;}
	};

	template<class P, class cont>
	bool	operator==(avl_iterator<P, cont> &lhs, avl_const_iterator<P, cont> &rhs){
		return (lhs.base() == rhs.base());
	}
	template<class P, class cont>
	bool	operator!=(avl_iterator<P, cont> &lhs, avl_const_iterator<P, cont> &rhs){
		return (lhs.base() != rhs.base());
	}

	template <class Key, class T, class Compare, class Alloc = std::allocator<T> >
	class avl_tree
	{
		typedef typename Alloc::template rebind<node<pair<Key, T> > >::other	node_alloc;//pour avoir un allocator qui genere la place pour une node plutot que la place pour pair.-

		public:
		//attributs
			typedef Key														key_type;
			typedef T														mapped_type;
			typedef ft::pair<key_type, mapped_type>							value_type;
			typedef ft::pair<const key_type, mapped_type>					iter_value_type;//sert quand on cree les iterator pour pourvoir generer des version const
			typedef typename ft::node<value_type>							_node;
			typedef Alloc													allocator_type;
			typedef avl_iterator<iter_value_type *, avl_tree>				iterator;//* car tour de magie pour renvoyer le bon type pour begin et end
			typedef avl_const_iterator<iter_value_type *, avl_tree>			const_iterator;//* car tour de magie pour renvoyer le bon type pour begin et end
		 	typedef _node*													pointer;
			typedef const _node*											const_pointer;
			typedef _node&													reference;
			typedef const _node&											const_reference;
			typedef ft::reverse_iterator<iterator>							reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef size_t													size_type;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;

	
		public:
			Compare				comp;
			size_type			size;//nb d'elem
			_node*				root;//a remettre en private
		private:
			// _node*				begin;
			// _node*				end;
			allocator_type		alloc;//ajuste pour get_allocator
			node_alloc			nalloc;

		public:
		//member function
			avl_tree(value_type data){
				this->root = this->nalloc.allocate(1);
				this->nalloc.construct(this->root, data);
				this->root->depth = 1;
				this->root->parent = NULL;
				this->root->lchild = NULL;
				this->root->rchild = NULL;
				this->size = 1;
			}

			avl_tree(avl_tree const & src):comp(src.comp), size(src.size), root(NULL), alloc(src.alloc), nalloc(src.nalloc){
				if (src.root != NULL)
					this->root = copy_tree(src.root, NULL);
				else
					this->root = NULL;
			}

			avl_tree &	operator=(const avl_tree & src){
				if (this->root != NULL)
					this->clear();
				this->alloc = src.alloc;
				this->nalloc = src.nalloc;
				this->size = src.size;
				this->comp = src.comp;
				// std::cout << "in =\n";//
				if (src.root != NULL)
					this->root = copy_tree(src.root, NULL);
				else
					this->root = NULL;
				return (*this);
			}

			virtual ~avl_tree(){
				// std::cout << "in destructor\n";//
				// std::cout << "size = " << this->size << std::endl;//
				if (this->size != 0)
					this->clear();
			}

			bool	insert(const value_type & data){
				if (this->root == NULL){//cas particulier où meme root est vide
				// std::cout << "ds insert\n";//
					this->root = this->nalloc.allocate(1);
					this->nalloc.construct(this->root, data);
					this->root->depth = 1;
					this->root->parent = NULL;
					this->root->lchild = NULL;
					this->root->rchild = NULL;
					this->size = 1;
					return true;
				}
				_node*	tmp = root;
				bool	b = false;
				_node*	n = NULL;//will be new _node pointer
				int	rcd, lcd, max;
				while (b == false){
				// std::cout << "tmp.data.f = " << tmp->data.first <<std::endl;//
					if (comp(data, tmp->data)){//data < tmp.data
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
					else if (comp(tmp->data, data)){//tmp.data < data
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
						_node* t = this->nalloc.allocate(1);
						this->nalloc.construct(t, data);
						swap_nodes_data(t, tmp);
						this->nalloc.destroy(t);
						this->nalloc.deallocate(t, 1);
						b = true;
						return (false);
					}
				}
				// bool isBal = isBalanced();
				// std::cout << isBal
				// if (!isBal && this->root->depth)
				// 	makeBalancedFromRoot();
				// else if (n != NULL && !isBal)
				// 	makeBalanced(n);
				_node*	isBalN = isBalanced(n);
				// std::cout << "isBalN = " << isBalN << std::endl;//
				makeBalanced(isBalN);
				// std::cout << "sortie de insert\n";//
				return (true);
			}//?

			size_type	erase(key_type const & k){
				value_type	kvt = ft::make_pair(k, mapped_type());
				_node*		tmp = root;
				bool		b = false;
				_node*		x = NULL;//will be parent of deallocate node.
				int	rcd, lcd, max;
				while (b == false && tmp != NULL){
					if (comp(/*k, tmp->data.first*/kvt, tmp->data) && (tmp->lchild != NULL)){//k < tmp.data.first
						tmp = tmp->lchild;
					}
					else if (comp(/*tmp->data.first, k*/tmp->data, kvt) && (tmp->rchild != NULL)){//tmp.data.first < k
						tmp = tmp->rchild;
					}
					else{// k = tmp.data.first //tmp est la node a erase
						if (tmp == this->root && tmp->depth == 1){//cas particulier où on efface la derniere node existante : root
							clear(tmp);
							this->root = NULL;
						}
						else if (tmp->lchild != NULL && tmp->lchild->depth == 1){//tmp.lc existe et n'a pas d'enfant
							swap_nodes_data(tmp, tmp->lchild);
							this->nalloc.destroy(tmp->lchild);
							this->nalloc.deallocate(tmp->lchild, 1);
							tmp->lchild = NULL;
							x = tmp;
							while (tmp != NULL){//pour adapter la depth
								rcd = (tmp->rchild != NULL) ? tmp->rchild->depth : 0;
								lcd = (tmp->lchild != NULL) ? tmp->lchild->depth : 0;
								max = std::max(rcd, lcd);
								if (tmp->depth == max + 1)
									break ;
								tmp->depth = max + 1;
								tmp = tmp->parent;
							}
						}
						else if (tmp->depth == 1){//si tmp n'a pas d'enfants
							_node*	x = tmp->parent;
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
								if (tmp->depth == max + 1)
									break ;
								tmp->depth = max + 1;
								tmp = tmp->parent;
							}
						}
						else {//tmp n'a pas de lc ou il a un lc qui a lui meme une descendance
							_node*	t = tmp->lchild;
							while (t != NULL && t->rchild != NULL){
								t = t->rchild;
							}
							if (t != NULL){//petite secu avant les manip
								x = t;
								while (t != NULL){
									swap_nodes_data(t->parent, t);
									x = t;
									t = t->lchild;
								}
								x = x->parent;
								clear(x->lchild);
								tmp = x;
								while (tmp != NULL){//pour adapter la depth
									rcd = (tmp->rchild != NULL) ? tmp->rchild->depth : 0;
									lcd = (tmp->lchild != NULL) ? tmp->lchild->depth : 0;
									max = std::max(rcd, lcd);
									if (tmp->depth == max + 1)
										break ;
									tmp->depth = max + 1;
									tmp = tmp->parent;
								}
							}
						}
						b = true;
						this->size--;
					}
				}
				makeBalanced(isBalanced(x));
				if (b == true)
					return (1);
				return (0);
			}

			_node*	isBalanced(_node* n){//from (new node) or (nephew or cousin or brother of deallocate node)//en mettre en private ?
				int		rcd, lcd;

				// std::cout << "n = " << n << std::endl;//
				while (n != NULL){
				// std::cout << "n = " << n << " n.data.f = " << n->data.first << " n.depth = " << n->depth << std::endl;//
					rcd = (n->rchild != NULL) ? n->rchild->depth : 0;
					lcd = (n->lchild != NULL) ? n->lchild->depth : 0;
					// std::cout << "rcd = " << rcd << "\tlcd = " << lcd << std::endl;//
					if (rcd - lcd > 1 || rcd - lcd < -1)
						return (n);
					n = n->parent;
				}
				// std::cout << "in isBalanced(node *)\n";//
				return NULL;
			}

			void clear(){
				// std::cout << "in clear()\n";//
				this->clear(this->root);
				this->size = 0;
			}

		private:

			avl_tree(){};

			void clear(_node* n){
				// std::cout << "in clear(node *)\n";//
				// std::cout << "n = " << n << " n.lc = " << n->lchild << " n.rc = " << n->rchild << std::endl;//
				if (n == NULL)
					return ;
				if (n->lchild != NULL){//segfault la ??????
					clear(n->lchild);
					n->lchild = NULL;
				}
				if (n->rchild != NULL){
					clear(n->rchild);
					n->rchild = NULL;
				}
				_node*	p = n->parent;
				if (p != NULL){
					if (p->lchild == n)
						p->lchild = NULL;
					if (p->rchild == n)
						p->rchild = NULL;
				}
				// std::cout << "test n = " << n << " n.data = " << &(n->data) << " n.data = (" << n->data.first << ", " << n->data.second << ")" << std::endl;//
				this->nalloc.destroy(n);//segfault ici dans destroy ??????
				// std::cout << "destroy ok\n";//
				this->nalloc.deallocate(n, 1);
				n = NULL;
				// std::cout << "clear(node *) fini\n";//
			}

			void	rightRotate(_node* z){//see Left Left Case example in https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
				// std::cout << "z = " << z << std::endl;//
				_node*	y = z->lchild;
				// std::cout << "y = " << y << std::endl;//
				_node*	t3 = y->rchild;
				// std::cout << "t3 = " << t3 << std::endl;//
				_node*	p = z->parent;
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

			void	leftRotate(_node* z){//see Right Right Case example in https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
				_node*	y = z->rchild;
				_node*	t2 = y->lchild;
				_node*	p = z->parent;
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

			void	leftRightRotate(_node* z){//see Left Right Case example in https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
				_node*	y = z->lchild;
				leftRotate(y);
				rightRotate(z);
			}

			void	rightLeftRotate(_node* z){//see Right Left Case example in https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
				_node*	y = z->rchild;
				rightRotate(y);
				leftRotate(z);
			}

			void	makeBalanced(_node* z){
				if (z == NULL || this->size <= 2){
					return ;
				}
				_node*	y;
				int rcd, lcd;
				rcd = (z->rchild != NULL) ? z->rchild->depth : 0;
				lcd = (z->lchild != NULL) ? z->lchild->depth : 0;
				if (lcd - rcd < -1){//case c or d
				// std::cout << "in makeBalanced(node *)\n";//
					y = z->rchild;
					rcd = (y->rchild != NULL) ? y->rchild->depth : 0;
					lcd = (y->lchild != NULL) ? y->lchild->depth : 0;
					if (lcd - rcd <= 0){//case c
						// std::cout << "case c\n";//
						if (y->rchild != NULL)
							leftRotate(z);
					}
					// else if (y->rchild == NULL || y->rchild->depth == 1){//case d
					else {//case d
						// std::cout << "case d\n";//
						if (y->lchild != NULL)
							rightLeftRotate(z);
					}
				}
				// else if (z->rchild == NULL || z->rchild->depth == 1){//case a or b
				else if (lcd - rcd > 1){//case a or b
					y = z->lchild;
					rcd = (y->rchild != NULL) ? y->rchild->depth : 0;
					lcd = (y->lchild != NULL) ? y->lchild->depth : 0;
					// if (y->rchild == NULL || y->rchild->depth == 1){//case a
					if (lcd - rcd >= 0){//case a
						// std::cout << "case a\n";//
						if (y->lchild != NULL)
							rightRotate(z);
					}
					// else if (y->lchild == NULL || y->lchild->depth == 1){//case b
					else {//case b
						// std::cout << "case b\n";//
						if (y->rchild != NULL)
							leftRightRotate(z);
					}
				}
			}

			_node*	copy_tree(const _node * src, _node * p){
				// std::cout << "in copy_tree\n";//
				_node*	n;
				if (src == NULL)
					return (NULL);
				n = this->nalloc.allocate(1);
				this->nalloc.construct(n, src->data);
				n->depth = src->depth;
				n->parent = p;
				try{
					n->lchild = copy_tree(src->lchild, n);
				}
				catch (...){
					delete_node(n);
					throw ;//ceci est un rethrow : ca gere l'erreur (ici leak de memoire), puis ca redonne l'erreur au user
				}
				try{
					n->rchild = copy_tree(src->rchild, n);
				}
				catch (...){
					delete_node(n->lchild);
					n->lchild = NULL;
					n->rchild = NULL;
					delete_node(n);
					throw ;
				}
				return (n);
			}

			void	delete_node(_node* n){
				if (n == NULL)
					return ;
				delete_node(n->lchild);
				delete_node(n->lchild);
				this->nalloc.destroy(n);
				this->nalloc.deallocate(n, 1);
				n = NULL;
			}

		//fonctions crees pour map
		public:
			template <class InputIter>
			avl_tree(InputIter first, typename enable_if<!is_integral<InputIter>::value, InputIter>::type last, const Compare & Comp,
				const allocator_type & alloca = allocator_type()):alloc(alloca), nalloc(node_alloc()), comp(Comp){
				// this->alloc = alloc;
				// this->nalloc = node_alloc();
				// this->comp = comp;
				this->root = NULL;
				for (InputIter it = first; it != last; it++){
					std::cout << (*it).first << std::endl;//
					// insert(ft::make_pair<key_type, mapped_type>((*it).first, (*it).second));
					insert(*it);
					// std::cout << "coucou\n";//
					// std::cout << "it=" << (void*)((++it).base());//segfault
					// std::cout << "\nlast" << (void*)(last.base()) << "\n";//
					// it--;//
				}
				std::cout << "youpi\n";//
				// insert(*last);
			}

			avl_tree(const Compare & comp, const allocator_type & alloc = allocator_type()):comp(comp), size(0), root(NULL), alloc(alloc), nalloc(node_alloc()){}

			Compare getComp() const{//a mettre en private ?
				return (this->comp);
			}

			_node* getFirst() const{//a mettre en private ?
				if (this->size == 0)
					return NULL;
				_node*	tmp = root;
				while (tmp && tmp->lchild != NULL)
					tmp = tmp->lchild;
				return (tmp);
			}

			_node*	getLast() const{//a mettre en private ?
				if (this->size == 0)
					return NULL;
				_node*	tmp = root;
				while (tmp && tmp->rchild != NULL)
					tmp = tmp->rchild;
				return (tmp);
			}
			
			iterator		begin(){return (iterator(getFirst()));}
			const_iterator	begin() const{return (const_iterator(getFirst()));}
			iterator		end(){
				// _node*	e = getLast();
				// return iterator(e->parent);
				_node*	e = NULL;
				return (iterator(e));
			}
			const_iterator	end() const{
				// _node*	e = getLast();
				// return const_iterator(e->parent);
				_node*	e = NULL;
				return (const_iterator(e));
			}

			reverse_iterator		rbegin(){return (reverse_iterator(end()));}
			const_reverse_iterator	rbegin() const{return (const_reverse_iterator(end()));}
			reverse_iterator		rend(){
				// return (reverse_iterator(begin()));
				_node*	e = NULL;
				return (reverse_iterator(e));
			}
			const_reverse_iterator	rend() const{
				// return (const_reverse_iterator(begin()));
				_node*	e = NULL;
				return (const_reverse_iterator(e));
			}

			size_type	max_size() const{return this->nalloc.max_size();}

			void	swap(avl_tree &x){
				std::swap(this->comp, x.comp);
				std::swap(this->size, x.size);
				std::swap(this->root, x.root);
				std::swap(this->alloc, x.alloc);
				std::swap(this->nalloc, x.nalloc);
			}
			
			iterator		find(const key_type & k){
				value_type	kvt = ft::make_pair(k, mapped_type());
				_node*		tmp = root;
				bool		b = false;
				while (b == false && tmp != NULL){
					if (comp(/*k, tmp->data.first*/kvt, tmp->data) && (tmp->lchild != NULL)){//k < tmp.data.first
						tmp = tmp->lchild;
					}
					else if (comp(/*tmp->data.first, k*/tmp->data, kvt) && (tmp->rchild != NULL)){//tmp.data.first < k
						tmp = tmp->rchild;
					}
					else 
						b = true;
				}
				if (tmp == NULL)
					return (end());
				return (iterator(tmp));
			}
			const_iterator	find(const key_type & k) const{
				value_type	kvt = ft::make_pair(k, mapped_type());
				_node*		tmp = root;
				bool		b = false;
				while (b == false && tmp != NULL){
					if (comp(/*k, tmp->data.first*/kvt, tmp->data) && (tmp->lchild != NULL)){//k < tmp.data.first
						tmp = tmp->lchild;
					}
					else if (comp(/*tmp->data.first, k*/tmp->data, kvt) && (tmp->rchild != NULL)){//tmp.data.first < k
						tmp = tmp->rchild;
					}
					else 
						b = true;
				}
				if (tmp == NULL)
					return (end());
				return (const_iterator(tmp));
			}

			allocator_type	get_allocator() const{return this->alloc;}
	};

}

#endif
