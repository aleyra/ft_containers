#ifndef VECTOR_H
# define VECTOR_H

# include <iostream>
# include "reverse_iterator.hpp"

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
			typedef	iterator_traits<iterator>::difference_type	difference_type;
			typedef std::size_t									size_type;
		private:
			allocator_type	_alloct;//?
			size_type		_capacity;//poids
			pointer			_data;//le tab ?
			size_type		_size;//nb d'elem

			//member functions : canonical form
		private:
			vector(){}
		public:	
			vector(const vector & src){}
			virtual ~vector(){}

			vector &	operator=(const vector & src){return (*this);}

			//member functions
			explicit	vector(const allocator_type & alloc = allocator_type()){}
			explicit	vector(size_type n, const value_type & val = value_type(),
								const allocator_type & alloc = allocator_type()){}//?
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type & alloc = allocator_type()){}//? need enableif

			//member functions: iterators
			iterator		begin(){return iterator(this, 0);}
			const_iterator	begin(){return const_iterator(this, 0);}

			iterator		end(){}//?
			const_iterator	end(){}//?

			reverse_iterator		rbegin(){}//?
			const_reverse_iterator	rbegin(){}//?

			reverse_iterator		rend(){}//?
			const_reverse_iterator	rend(){}//?

			//member functions: capacity
			size_type	size(){}//?

			size_type	max_size(){}//?

			void		resize(size_type n, value_type val = value_type()){}//?

			size_type	capacity() const{}//?

			bool		empty() const{}//?

			void		reserve(size_type n){}//?

			//member functions: element access
			reference		operator[](size_type n){}//?
			const_reference	operator[](size_type n) const{}//?

			reference		at(size_type n){}//?
			const_reference	at(size_type n) const{}//?

			reference		front(){}//?
			const_reference	front() const{}//?

			reference		back(){}//?
			const_reference	back() const{}//?

			//member functions: modifiers
			template<class InputIterator>
			void	assign(InputIterator first, InputIterator last){}//?need enableif
			void	assign(size_type n, const value_type & val){}//?

			void	push_back(const value_type & val){}//?

			void	pop_back(){}//?

			iterator	insert(iterator position, const value_type & val){}//?
			void		insert(iterator position, size_type n, const value_type & val){}//?
			template <class InputIterator>
			void		insert(iterator position, InputIterator firstm InputIterator last){}//?need enableif

			iterator	erase(iterator position){}//?
			iterator	erase(iterator first, iterator last){}//?

			void	swap(vector& x){}//?

			void	clear(){}//?

			//member functions: allocator
			allocator_type get_allocator() const{}//?
			
		protected:

		private:

	};
	//non-member functions overloads
	template <class T, class Alloc>
	bool	operator==(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs){}//?
	template <class T, class Alloc>
	bool	operator!=(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs){}//?
	template <class T, class Alloc>
	bool	operator<(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs){}//?
	template <class T, class Alloc>
	bool	operator<=(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs){}//?
	template <class T, class Alloc>
	bool	operator>(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs){}//?
	template <class T, class Alloc>
	bool	operator>=(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs){}//?
	template <class T, class Alloc>
	void	swap(vector<T, Alloc> & x, vector<T, Alloc> & y){}//?
}

#endif