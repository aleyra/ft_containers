#pragma once

#include "pair.hpp"
#include "reverse_iterator.hpp"
#include "equal.hpp"
#include "avl_tree.hpp"

namespace ft{

	template <typename Key, typename T, typename Compare = std::less<Key>,
		typename /*Alloc*/Allocator = std::allocator< ft::pair<const Key, T> > >
	class map{
	public:
		typedef Key																	key_type;
		typedef T																	mapped_type;
		typedef ft::pair<const Key, T>												value_type;
		typedef Compare																key_compare;
		typedef Allocator															allocator_type;
		typedef std::size_t															size_type;
		typedef ptrdiff_t															difference_type;
		typedef value_type&															reference;
		typedef const value_type&													const_reference;
		typedef value_type*															pointer;
		typedef const value_type*													const_pointer;
		typedef typename ft::avl_tree<Key, T, Compare, Allocator>::iterator			iterator;
		typedef typename ft::avl_tree<Key, T, Compare, Allocator>::const_iterator	const_iterator;
		typedef ft::reverse_iterator<iterator>										reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>								const_reverse_iterator;
		
		class value_compare{
			friend class map;
			protected:
				key_compare comp;
				value_compare(const key_compare& c) : comp (c) { }
			public:
				typedef bool		result_type;
				typedef value_type	first_argument_type;
				typedef value_type	second_argument_type;
				bool 				operator()(const value_type& x, const value_type& y) const{return comp(x.first, y.first);}
		};

	private:
		typedef	ft::avl_tree<Key, T, Compare, Allocator>	tree_type;

	private:
		tree_type	_tree;

	public:
	#pragma region canonical form
		map(): _tree(tree_type()){}
		
		map(const map& src): _tree(tree_type()){
			for (const_iterator it = src.begin(); it != src.end(); ++it){
				this->_tree.insert(*it);
			}
		}

		~map(){}

		map& operator=(const map& src){
			this->clear();
			for (const_iterator it = src.begin(); it != src.end(); ++it){
				this->_tree.insert(*it);
			}
			return *this;
		}

	#pragma endregion canonical form

	#pragma region other constructor
		explicit map(const /*key_compare*/Compare& comp/* = key_compare()*/, const allocator_type& alloc = allocator_type()): _tree(tree_type(alloc)){(void)comp;}
		template<class InputIterator>
		map(InputIterator first, InputIterator last, const /*key_compare*/Compare& comp = /*key_compare*/Compare(), const allocator_type& alloc = allocator_type()): _tree(tree_type(alloc)){
			(void)comp;
			while (first != last) {
				this->_tree.insert(*first++);
			}
		}

	#pragma endregion other constructor

	#pragma region iterators
		iterator begin(){return _tree.begin();}
		const_iterator begin() const{return _tree.begin();}

		iterator end(){return _tree.end();}
		const_iterator end() const{return _tree.end();}

		reverse_iterator rbegin(){return reverse_iterator(this->end());}
		// const_reverse_iterator rbegin(){return const_reverse_iterator(this->end());}

		reverse_iterator rend(){return reverse_iterator(this->begin());}
		// const_reverse_iterator rend(){return const_reverse_iterator(this->begin());}
	#pragma endregion iterators

	#pragma region capacity
		bool empty() const{return this->size() == 0;}

		size_type size() const{return this->_tree.size();}
		
		size_type max_size() const{return this->_tree.max_size();}
	#pragma endregion capacity

	#pragma region element access
		mapped_type& operator[](const key_type& key){
			this->_tree.insert(key, mapped_type()); // Will do nothing if key is already mapped
			return this->_tree.find(key).second;
		}

		mapped_type& at(const key_type& key){return this->_tree.find(key).second;}
		const mapped_type& at(const key_type& key) const{return this->_tree.find(key).second;}
	#pragma endregion element access

	#pragma region modifiers
		ft::pair<iterator, bool> insert(const value_type& value){
			bool result = this->_tree.insert(value);
			iterator it = iterator(_tree.root(), this->_tree.find_node(value.first));
			return ft::make_pair(it, result);
		}
		iterator insert(iterator position, const value_type& value){//position est un indice
			(void)position;
			this->_tree.insert(value);
			return iterator(_tree.root(), this->_tree.find_node(value.first));
		}
		template<class InputIterator>
		void insert(InputIterator first, InputIterator last){
			while (first != last){
				this->_tree.insert(*first++);
			}
		}

		void erase(iterator position){
			this->_tree.erase(position->first);
		}
		size_type erase(const key_type& key){
			size_type ret = (_tree.find_node(key) != NULL);
			this->_tree.erase(key);
			return ret;
		}
		void erase(iterator first, iterator last){
			while (first != iterator(this->_tree.root(), last.base())){
				iterator next = first + 1;
				this->erase(first);
				first = iterator(this->_tree.root(), next.base());
			}
		}

		void swap(map& x){this->_tree.swap(x._tree);}

		void clear(){this->_tree.clear();}
	#pragma endregion modifiers

	#pragma region observers
		key_compare key_comp() const{return key_compare();}
		
		value_compare value_comp() const{return value_compare();}
	#pragma endregion observers

	#pragma region operations
		iterator find(const Key& key){return iterator(this->_tree.root(), this->_tree.find_node(key));}
		const_iterator find(const Key& key) const{return const_iterator(this->_tree.root(), this->_tree.find_node(key));}

		size_type count(const Key& key) const{return this->_tree.find_node(key) ? 1 : 0;}

		iterator lower_bound(const Key& key){
			iterator v = this->find(key);
			if (v == this->end())
				return iterator(this->_tree.root(), this->_tree.upper(key));
			return v;
		}
		const_iterator lower_bound(const Key& key) const{
			const_iterator v = this->find(key);
			if (v == this->end())
				return const_iterator(this->_tree.root(), this->_tree.upper(key));
			return v;
		}

		iterator upper_bound(const Key& key){return iterator(this->_tree.root(), this->_tree.upper(key));}
		const_iterator upper_bound(const Key& key) const{return const_iterator(this->_tree.root(), this->_tree.upper(key));}

		ft::pair<iterator,iterator> equal_range(const Key& key){return ft::make_pair(lower_bound(key), upper_bound(key));}
		ft::pair<const_iterator,const_iterator> equal_range(const Key& key) const{return ft::make_pair(lower_bound(key), upper_bound(key));}
	#pragma endregion operations

		allocator_type get_allocator() const{return allocator_type();}
	};

	template<class K, class V, class C, class A>
	bool operator==(const ft::map<K, V, C, A>& lhs, const ft::map<K, V, C, A>& rhs){
		if (lhs.size() != rhs.size())
			return false;
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}
	template<class K, class V, class C, class A>
	bool operator!=(const ft::map<K, V, C, A>& lhs, const ft::map<K, V, C, A>& rhs){return !(lhs == rhs);}

	template<class K, class V, class C, class A>
	bool operator<(const ft::map<K, V, C, A>& lhs, const ft::map<K, V, C, A>& rhs){
		return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	template<class K, class V, class C, class A>
	bool operator<=(const ft::map<K, V, C, A>& lhs, const ft::map<K, V, C, A>& rhs){return !(lhs > rhs);}

	template<class K, class V, class C, class A>
	bool operator>(const ft::map<K, V, C, A>& lhs, const ft::map<K, V, C, A>& rhs){return (rhs < lhs);}

	template<class K, class V, class C, class A>
	bool operator>=(const ft::map<K, V, C, A>& lhs, const ft::map<K, V, C, A>& rhs){return !(lhs < rhs);}

	template<class K, class V, class C, class A>
	void swap( ft::map<K, V, C, A>& lhs, ft::map<K, V, C, A>& rhs ){lhs.swap(rhs);}
}
