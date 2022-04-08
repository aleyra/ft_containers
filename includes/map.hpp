#ifndef MAP_H
# define MAP_H

# include <iostream>
# include "make_pair.hpp"
# include "reverse_iterator.hpp"

namespace ft{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map{
		//member attributs
		typedef Key										key_type;
		typedef T										mapped_type;
		typedef ft::pair<const key_type, mapped_type>	value_type;
		typedef Compare									key_compare;
		template <class Key, class T, class Comparem call Alloc>
		class map<Key, T, Comparem Alloc>::value_compare:public std::binary_function<value_type, value_type, bool>{
			friend class map;
			protected:
				Compare	comp;
				value_compare (Compare c) : comp(c) {}
			public:
  				typedef bool		result_type;
  				typedef value_type	first_argument_type;
  				typedef value_type	second_argument_type;
  				bool				operator()(const value_type& x, const value_type& y) const{return comp(x.first, y.first);}
		};
		// template <class Key, class T, class Comparem call Alloc>
		// typedef	map<Key, T, Comparem Alloc>::value_compare	value_compare;//?
		typedef Alloc											allocator_type;
		typedef allocator_type::reference						reference;
		typedef allocator_type::const_reference					const_reference;
		typedef allocator_type::pointer							pointer;
		typedef allocator_type::const_pointer					const_pointer;
		typedef value_type::bidirectional_iterator				iterator;//?
		typedef const value_type::bidirectional_iterator		const_iterator;//?
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef ft::iterator_traits<iterator>::difference_type	difference_type;
		typedef size_t											size_type;

		//member functions : canonical form
		map(){}//?
		map(const map & src){}//?
		virtual ~map(){}//?
		map & operator=(const map & src){}//?

		//member functions
		explicit map(const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type()){}//?
		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type()){}//? need enableif ?
		
		//member functions: iterators
		iterator		begin(){}//?
		const_iterator	begin() const{}//?

		iterator		end(){}//?
		const_iterator	end() const{}//?

		reverse_iterator		rbegin(){}//?
		const_reverse_iterator	rbegin() const{}//?

		reverse_iterator		rend(){}//?
		const_reverse_iterator	rend() const{}//?

		//member functions: capacity
		bool		empty() const{}//?

		size_type	size() const{}//?

		size_type	max_size() const{}//?

		//member functions: element access
		mapped_type &	operator[](const key_type & k){}//?

		//member functions: modifiers
		pair<iterator, bool>	insert(conost value_type & val){}//?
		iterator				insert(iterator positionm const value_type & val,){}//?
		template <class InputIterator>
		void					insert(InputIterator first, InputIterator last){}//? need enableif ?

		void		erase(iterator position){}//?
		size_type	erase(const key_type & k){}//?
		void		erase(iterator first, iterator last){}//?

		void	swap(map & x){}//?

		void	clear()//?

		//member functions: observers
		key_compare	key_comp() const{}//?

		value_compare	value_comp() const{}//?

		//member functions: operations
		iterator		find(const key_type & k){}//?
		const_iterator	find(const key_type & k) const{}//?

		size_type	count(const key_type & k) const{}//?

		iterator		lower_bound(const key_type & k){}//?
		const_iterator	lower_bound(const key_type & k) const{}//?

		iterator		upper_bound(const key_type & k){}//?
		const_iterator	upper_bound(const key_type & k) const{}//?

		pair<const_iterator, const_iterator>	equal_range(const key_type & k) const{}//?
		pair<iterator, iterator>				equal_range(const key_type & k){}//?

		//member functions: allocator
		allocator_type	get_allocator() const{}//?
	};
}

#endif