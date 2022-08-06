#pragma once

#include "avl_node.hpp"

namespace ft{

	template<class Key, class _Tp, class Compare = std::less<Key>,
		class Allocator = std::allocator< ft::pair<const Key, _Tp> > >
	struct avl_tree {
		public:
			typedef avl_node<Key, _Tp, Compare, Allocator>						node;
			typedef node*														node_ptr;
			typedef Key															key_type;
			typedef _Tp															value_type;
			typedef ft::pair<Key, _Tp>											pair_type;
			typedef ft::pair<const Key, _Tp>									const_pair_type;
			typedef std::size_t													size_type;
			typedef ptrdiff_t													difference_type;
			typedef Allocator													allocator_type;
			typedef ft::avl_tree_iterator<Key, _Tp, Compare, Allocator>			iterator;
			typedef ft::avl_tree_const_iterator<Key, _Tp, Compare, Allocator>	const_iterator;

		private:
			typedef typename allocator_type::template rebind<node>::other node_allocator;

		private:
			node_allocator	_allocator;
			node_ptr		_root;
			size_type		_size;

		public:
			avl_tree(allocator_type alloc = allocator_type()) : _allocator(alloc), _root(NULL), _size(0){}

			~avl_tree(){this->clear();}

		#pragma region iterators
			iterator begin(){
				if (this->_size == 0)
					return this->end();
				return iterator(this->_root, this->min());
			}
			const_iterator begin() const{
				if (this->_size == 0)
					return this->end();
				return const_iterator(this->_root, this->min());
			}
			
			iterator end(){return iterator(this->_root, NULL);}
			const_iterator end() const{
				return const_iterator(this->_root, NULL);
			}

		#pragma endregion iterators

		#pragma region capacity
			size_type size() const{return this->_size;}

			size_type max_size() const{//on gere les cas chelou ou on utilise des allocator de type dont le max est plus petit genre char
				return std::min(_allocator.max_size(), static_cast<size_type>(std::numeric_limits<difference_type>::max()));
			}

		#pragma endregion capacity

		#pragma region modifiers
			bool insert(pair_type data){
				if (node::find(this->_root, data.first) != NULL)
					return false;
				this->_root = node::insert(this->_root, data, _allocator);//node::insert fait aussi un makeBalanced
				this->_size++;
				return true;
			}
			bool insert(key_type key, value_type value){return insert(ft::make_pair(key, value));}

			void erase(const key_type& key){
				if (node::find(this->_root, key) == NULL)
					return ;
				this->_root = node::erase(this->_root, key, _allocator);////node::erase fait aussi un makeBalanced
				this->_size--;
			}

			void swap(avl_tree& other){
				std::swap(this->_allocator, other._allocator);
				std::swap(this->_root, other._root);
				std::swap(this->_size, other._size);
			}

			void clear(){//violent
				size_type size_before = _size;
				for (size_type i = 0; i < size_before; ++i) {
					erase(_root->key());
				}
			}

		#pragma endregion modifiers

		#pragma region operations
			const_pair_type& find(const key_type& key) const{
				node_ptr node = node::find(this->_root, key);
				if (node == NULL) {//propre
					throw std::out_of_range("Key not found in map");
				}
				return reinterpret_cast<const_pair_type&>(node->key_value_pair());//tour de magie
			}

		#pragma endregion operations
			
		#pragma region tools
			node_ptr root(){return _root;}

			node_ptr min() const{
				if (this->_root == NULL)//propre
					throw std::out_of_range("Map is empty");
				return node::min(this->_root);
			}

			node_ptr max() const{
				if (this->_root == NULL)//propre
					throw std::out_of_range("Map is empty");
				return node::max(this->_root);
			}

			node_ptr upper(const key_type& key) const{
				return node::upper(this->_root, key);
			}

			node_ptr find_node(const key_type& key) const{
				node_ptr node = node::find(this->_root, key);
				return node;
			}

			node_ptr next(node_ptr node){return node::next(node, _root);}

		#pragma endregion tools

			// std::string viz(){
			// 	std::string ret = "digraph bintree {\ngraph [ordering=\"out\"];\nnodesep=0.4;\nranksep=3;\n";
			// 	if (_root) {
			// 		ret += node::viz(_root, true);
			// 	}
			// 	ret += "}\n";
			// 	return ret;
			// }
	};

}
