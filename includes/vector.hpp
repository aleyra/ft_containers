#ifndef VECTOR_H
# define VECTOR_H

# include <iostream>
# include "reverse_iterator.hpp"
# include <algorithm>

namespace ft{
	template <typename T, class Alloc = std::allocator<T> >
	class vector{
		public:
			//member attributs // typedef everywhere to make reading-friendly
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef allocator_type::reference					reference;
			typedef allocator_type::const_reference				const_reference;
			typedef allocator_type::pointer						pointer;
			typedef allocator_type::const_pointer				const_pointer;
			typedef pointer										iterator;
			typedef const_pointer								const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef	ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef std::size_t									size_type;
		private:
			allocator_type	_alloct;//?
			size_type		_capacity;//>= nb d'elem
			pointer			_data;//le tab
			size_type		_size;//nb d'elem

			//member functions : canonical form
		private:
			vector():_alloct(), _capacity(0), _data(_alloct.allocate(_capacity)), _size(0){}
		public:	
			vector(const vector & src){*this = src}
			virtual ~vector(){this->clear()}

			vector &	operator=(const vector & src):_alloct(src._alloct),
				_capacity(src._capacity), _data(_alloct.allocate(_capacity), _size(src._size)){
				for(i = 0; i < this->_size ; i++){
					this->_alloct.construct(&this->_data[i],src._data[i]);
				}
				return (*this);
			}

			//member functions
			explicit	vector(const allocator_type & alloc = allocator_type()):_alloct(alloc), _capacity(0), _data(_alloct.allocate(_capacity)), _size(0){}
			explicit	vector(size_type n, const value_type & val = value_type(), const allocator_type & alloc = allocator_type()):_alloct(alloc),
				_capacity(n), _data(_alloct.allocate(_capacity), _size(n)){
				for(i = 0; i < this->_size ; i++){this->_alloct.construct(&this->_data[i], val);}
			}
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type & alloc = allocator_type()):_alloct(alloc), _size(0){
				//en attente
			}//? need enableif

			//member functions: iterators
			iterator		begin(){iterator	it(begin()); return (it);}//?
			const_iterator	begin(){const_iterator	cit(begin()); return (cit);}//?

			iterator		end(){iterator	it(end()); return (it);}//?
			const_iterator	end(){const_iterator	cit(end()); return (cit);}//?

			reverse_iterator		rbegin(){reverse_iterator rit(begin()); return (++rit);}
			const_reverse_iterator	rbegin(){const_reverse_iterator crit(begin()); return (++crit);}

			reverse_iterator		rend(){reverse_iterator rit(end()); return (++rit);}
			const_reverse_iterator	rend(){const_reverse_iterator crit(end()); return (++crit);}

			//member functions: capacity
			size_type	size(){return this->_size;}

			size_type	max_size(){return this->_alloct.max_size();}

			void		resize(size_type n, value_type val = value_type()){}//?

			size_type	capacity() const{return this->_capacity;}

			bool		empty() const{
				if (this->_size == 0)
					return (1);
				return (0);
			}

			void		reserve(size_type n){}//?

			//member functions: element access
			reference		operator[](size_type n){return (this->_data[n]);}
			const_reference	operator[](size_type n) const{{return (this->_data[n]);}}

			reference		at(size_type n){
				if (n >= this->_size)
					throw std::out_of_range("vector");
				return (this->_data[n]);
			}
			const_reference	at(size_type n) const{
				if (n >= this->_size)
					throw std::out_of_range("vector");
				return (&(this->_data[n]));
			}

			reference		front(){}//?comme begin mais en ref
			const_reference	front() const{}//?comme begin mais en ref

			reference		back(){}//?comme end mais en ref
			const_reference	back() const{}//?comme end mais en ref

			//member functions: modifiers
			template<class InputIterator>
			void	assign(InputIterator first, InputIterator last){}//?need enableif
			void	assign(size_type n, const value_type & val){}//?

			void	push_back(const value_type & val){}//?

			void	pop_back(){}//?

			iterator	insert(iterator position, const value_type & val){
				if (this->_size + 1 > this->_capacity)
					//augmenter la capacite
				this->_size++;
				//bouger les data[i] vers la fin
				//data[i] = val
			}//?
			void		insert(iterator position, size_type n, const value_type & val){
				for (size_type i = 0; i < n; i++)
					this->insert(position, val);
			}
			template <class InputIterator>
			void		insert(iterator position, InputIterator first, InputIterator last){
				for (size_type i = 0; i < (size_type)(last - first); i++)
					this->insert(position, *(last--));
			}//?need enableif

			iterator	erase(iterator position){
				for (size_type i = position - this->begin(); i < this->_size - 1; i++)
					this->_data[i] = this->_data[i + 1];
				this->_size--;
				this->_alloct.destroy(&(this->_data[this->_size]));
				return (position);
			}
			iterator	erase(iterator first, iterator last){
				for (iterator it = first; it < last; it++)
					erase(it);
			}

			void	swap(vector& x){
				std::swap(this->_alloct, x._alloct);
				std::swap(this->_size, x._size);
				std::swap(this->_capacity, x._capacity);
				std::swap(this->_data, x._data);
			}

			void	clear(){
				if (this->_size != 0)
					for (size_type i = this->_size - 1 ; i >= 0; i--)
						this->_alloct.destroy(&(this->_data[i]));
				if (this->_data != NULL){
					this->_alloct.deallocate(this->_data, this->_size);
					this->_data = NULL;
				}
				this->_capacity = 0;
				this->_size = 0;
			}

			//member functions: allocator
			allocator_type get_allocator() const{return (this->_alloct);}
			
		protected:

		private:

	};
	//non-member functions overloads
	template <class T, class Alloc>
	bool	operator==(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs){}//?
	template <class T, class Alloc>
	bool	operator!=(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs){return (!(lhs == rhs));}
	template <class T, class Alloc>
	bool	operator<(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs){}//?
	template <class T, class Alloc>
	bool	operator<=(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs){return ((lhs == rhs) || (lhs < rhs));}
	template <class T, class Alloc>
	bool	operator>(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs){return (!(lhs <= rhs));}
	template <class T, class Alloc>
	bool	operator>=(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs){return (!(lhs < rhs));}
	template <class T, class Alloc>
	void	swap(vector<T, Alloc> & x, vector<T, Alloc> & y){
		x.swap(y);
	}
}

#endif