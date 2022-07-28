#ifndef MAP_H
# define MAP_H

# include <iostream>
# include "make_pair.hpp"
# include "reverse_iterator.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
// # include "birectional_iterator_tag.hpp"
# include "my_avl_tree.hpp"

namespace ft{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map{//c'est un genre d'arbre
		public:
		//member attributs
		typedef Key										key_type;
		typedef T										mapped_type;
		typedef ft::pair<const key_type, mapped_type>	value_type;
		typedef Compare									key_compare;
		typedef Alloc									allocator_type;

		class value_compare:public std::binary_function<value_type, value_type, bool>{
			friend class map;
			protected:
				value_compare(const key_compare& c) : comp (c) { }
    			key_compare comp;
			public:
  				typedef bool		result_type;
  				typedef value_type	first_argument_type;
  				typedef value_type	second_argument_type;
  				bool				operator()(const value_type& x, const value_type& y) const{return comp(x.first, y.first);}
		};
		typedef	map<Key, T, Compare, Alloc>::value_compare	value_compare;

		private:
		typedef typename Alloc::template rebind<value_type>::other				pair_alloc;
		typedef ft::avl_tree<key_type, mapped_type, value_compare, pair_alloc>	map_tree;

		key_compare	comp;
		map_tree	tree;

		public:
		typedef typename pair_alloc::pointer				pointer;
		typedef typename pair_alloc::const_pointer			const_pointer;
		typedef typename pair_alloc::reference				reference;
		typedef typename pair_alloc::const_reference		const_reference;
		typedef typename map_tree::iterator					iterator;
		typedef typename map_tree::const_iterator			const_iterator;
		typedef typename map_tree::reverse_iterator			reverse_iterator;
		typedef typename map_tree::const_reverse_iterator	const_reverse_iterator;
		typedef typename map_tree::difference_type			difference_type;
		typedef typename map_tree::size_type				size_type;

		//member functions : canonical form
		private:
		// map(){}//?
		public:
		map(const map & src):comp(src.comp), tree(src.tree){}//?
		virtual ~map(){/*this->clear()*/}//?
		map & operator=(const map & src){
			comp = src.comp;
			tree = src.tree;
			return (*this);
		}//?

		//member functions
		explicit map(const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type()):comp(comp), tree(value_compare(comp), alloc) {}//?
		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0):comp(comp), tree(first, last, value_compare(comp), alloc){}
		
		//member functions: iterators
		iterator		begin(){return this->tree.begin();}
		const_iterator	begin() const{return this->tree.begin();};

		iterator		end(){return (this->tree.end());}
		const_iterator	end() const{return (this->tree.end());}//?

		reverse_iterator		rbegin(){return this->tree.rbegin();}//?
		const_reverse_iterator	rbegin() const{return this->tree.rbegin();}//?

		reverse_iterator		rend(){return this->tree.rend();}//?
		const_reverse_iterator	rend() const{return this->tree.rend();}//?

		//member functions: capacity
		bool		empty() const{
			if (this->tree.size == 0)
				return (true);
			return (false);
		}

		size_type	size() const{return (this->tree.size);}

		size_type	max_size() const{return this->max_size();}

		//member functions: element access
		mapped_type &	operator[](const key_type & k){return this->tree[k];}

// 		//member functions: modifiers
// 		pair<iterator, bool>	insert(conost value_type & val){}//?
// 		iterator				insert(iterator positionm const value_type & val,){}//?
// 		template <class InputIterator>
// 		void					insert(InputIterator first, InputIterator last){}//? need enableif ?

// 		void		erase(iterator position){}//?
// 		size_type	erase(const key_type & k){}//?
// 		void		erase(iterator first, iterator last){}//?

// 		void	swap(map & x){}//?

		void	clear(){this->tree.clear();}

		//member functions: observers
// 		key_compare	key_comp() const{}//?

// 		value_compare	value_comp() const{}//?//????????????????

		//member functions: operations
// 		iterator		find(const key_type & k){}//?
// 		const_iterator	find(const key_type & k) const{}//?

// 		size_type	count(const key_type & k) const{}//?

// 		iterator		lower_bound(const key_type & k){}//?
// 		const_iterator	lower_bound(const key_type & k) const{}//?

// 		iterator		upper_bound(const key_type & k){}//?
// 		const_iterator	upper_bound(const key_type & k) const{}//?

// 		pair<const_iterator, const_iterator>	equal_range(const key_type & k) const{}//?
// 		pair<iterator, iterator>				equal_range(const key_type & k){}//?

		//member functions: allocator
// 		allocator_type	get_allocator() const{}//?

// 		protected:

// 		private:
	};
// 	//Non-members functions:
// 	template <class Key, class T, class Compare, class Alloc>
// 	bool operator==(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs){}//?

// 	template <class Key, class T, class Compare, class Alloc>
// 	bool operator!=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs){return (!(rhs == lhs));}

// 	template <class Key, class T, class Compare, class Alloc>
// 	bool operator<(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs){}//?

// 	template <class Key, class T, class Compare, class Alloc>
// 	bool operator<=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs){return ((rhs == lhs) || (rhs < lhs));}

// 	template <class Key, class T, class Compare, class Alloc>
// 	bool operator>(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs){return (!(rhs <= lhs));}

// 	template <class Key, class T, class Compare, class Alloc>
// 	bool operator>=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs){return (!(rhs < lhs));}

// 	template <class Key, class T, class Compare, class Alloc>
//   	void swap(map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y){}//?
}

#endif