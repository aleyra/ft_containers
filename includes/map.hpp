#ifndef MAP_H
# define MAP_H

# include <iostream>
# include "make_pair.hpp"
# include "reverse_iterator.hpp"
# include "enable_if.hpp"
# include "equal.hpp"
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
    			key_compare comp;
				value_compare(const key_compare& c) : comp (c) { }
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
		typedef ft::node<value_type>											node;

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
		map(const map & src):comp(src.comp), tree(src.tree){}
		virtual ~map(){this->clear();}
		map & operator=(const map & src){
			comp = src.comp;
			tree = src.tree;
			return (*this);
		}

		//member functions
		explicit map(const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type()):comp(comp), tree(value_compare(comp), alloc) {}//?
		template <class InputIterator>//a remettre avec hebriel
		map (InputIterator first, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last,
			const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type()):comp(comp), tree(first, last, value_compare(comp), alloc){}
		
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

		size_type	max_size() const{return this->tree.max_size();}

		//member functions: element access
		mapped_type &	operator[](const key_type & k){
			value_type				kvt = ft::make_pair(k, mapped_type());
			pair<iterator, bool>	res = insert(kvt);
			return ((res.first)->second);			
		}

// 		//member functions: modifiers
		pair<iterator, bool>	insert(const value_type & val){
			bool 		res = this->tree.insert(val);
			iterator	it = this->find(val.first);
			return (ft::make_pair(it, res));
		}
		iterator				insert(iterator position, const value_type & val){
			(void) position;
			this->insert(val);
			return (this->find(val.first));
		}
		template <class InputIterator>
		void		insert(InputIterator first, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last){
			for (InputIterator it = first; it != last; it++){
				this->tree.insert(*it);
			}
		}

		void		erase(iterator position){
			this->tree.erase(position->data.first);
		}
		size_type	erase(const key_type & k){return (this->tree.erase(k));}
		void		erase(iterator first, iterator last){
			iterator	it = first;
			iterator	next;
			while (it != last){
				next = ++it;
				erase(--it);
				it = iterator(next.base());
			}
		}

		void	swap(map & x){
			std::swap(this->comp, x.comp);
			this->tree.swap(x.tree);
		}

		void	clear(){this->tree.clear();}

		//member functions: observers
		key_compare	key_comp() const{return this->comp;}

		// value_compare	value_comp() const{}//?

		//member functions: operations
		iterator		find(const key_type & k){return this->tree.find(k);}
		const_iterator	find(const key_type & k) const{return this->tree.find(k);}

		size_type	count(const key_type & k) const{
			return ((find(k) != end()) ? 1 : 0);
		}

		iterator		lower_bound(const key_type & k){
			for (iterator it = begin(); it != end(); it++){
				if (it->first >= k)
					return (it);
			}
			return (end());
		}
		const_iterator	lower_bound(const key_type & k) const{
			for (iterator it = begin(); it != end(); it++){
				if (it->first >= k)
					return (const_iterator(it.base()));//le tour de magie sert ici aussi
			}
			return (end());
		}

		iterator		upper_bound(const key_type & k){
			for (iterator it = begin(); it != end(); it++){
				if (it->first > k)
					return (it);
			}
			return (end());
		}
		const_iterator	upper_bound(const key_type & k) const{
			for (iterator it = begin(); it != end(); it++){
				if (it->first >= k)
					return (const_iterator(it.base()));//le tour de magie sert ici aussi
			}
			return (end());
		}

		pair<const_iterator, const_iterator>	equal_range(const key_type & k) const{
			iterator	low = lower_bound(k);
			iterator	up = upper_bound(k);

			return (ft::make_pair(low, up));
		}
		pair<iterator, iterator>				equal_range(const key_type & k){
			const_iterator	low = lower_bound(k);
			const_iterator	up = upper_bound(k);

			return (ft::make_pair(low, up));
		}

		//member functions: allocator
		allocator_type	get_allocator() const{return this->get_allocator();}

// 		protected:

// 		private:
	};
	//Non-members functions:
	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs){
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs){return (!(rhs == lhs));}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs){
			return (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs){return ((rhs == lhs) || (rhs < lhs));}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs){return (!(rhs <= lhs));}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs){return (!(rhs < lhs));}

	template <class Key, class T, class Compare, class Alloc>
  	void swap(map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y){x.swap(y);}
}

#endif