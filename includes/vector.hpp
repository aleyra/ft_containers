#ifndef VECTOR_H
# define VECTOR_H

# include <iostream>
# include "reverse_iterator.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include <algorithm>

namespace ft{
	template <typename T, class Alloc = std::allocator<T> >
	class vector{
		public:
			//member attributs // typedef everywhere to make reading-friendly
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef pointer										iterator;
			typedef const_pointer								const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef	typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef std::size_t									size_type;
		private:
			allocator_type	_alloct;//?
			size_type		_capacity;//>= nb d'elem
			pointer			_data;//le tab
			size_type		_size;//nb d'elem

			//member functions : canonical form
		private:
			// vector():_alloct(), _capacity(0), _data(_alloct.allocate(_capacity)), _size(0){}
		public:	
			vector(const vector & src){*this = src;}
			virtual ~vector(){this->clear();}

			vector &	operator=(const vector & src){
				this->_alloct = src._alloct;
				this->_capacity =src._capacity;
				this->_data = this->_alloct.allocate(this->_capacity);
				this->_size = src._size;
				for(size_type i = 0; i < this->_size ; i++){
					this->_alloct.construct(&this->_data[i],src._data[i]);
				}
				return (*this);
			}

			//member functions
			explicit	vector(const allocator_type & alloc = allocator_type()):_alloct(alloc), _capacity(0), _data(_alloct.allocate(_capacity)), _size(0){}
			explicit	vector(size_type n, const value_type & val = value_type(), const allocator_type & alloc = allocator_type()):_alloct(alloc),
				_capacity(n), _data(_alloct.allocate(_capacity)), _size(n){
				for(size_type i = 0; i < this->_size ; i++){this->_alloct.construct(&this->_data[i], val);}
			}
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type & alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0):_alloct(alloc), _capacity((size_type)(last - first) + 10),
				_data(_alloct.allocate(_capacity)), _size((size_type)(last - first)){
				for (size_type i = 0; i < this->_size; i++){
					this->_alloct.construct(&this->_data[i], *first);
					first++;
				}
			}

			//member functions: iterators
			iterator		begin(){iterator it(this->_data); return (it);}
			const_iterator	begin() const {const_iterator	cit(this->_data); return (cit);}

			iterator		end(){iterator	it(this->_data); return (it + this->_size);}
			const_iterator	end() const {const_iterator	cit(end()); return (cit + this->_size);}

			reverse_iterator		rbegin(){reverse_iterator rit(end()); return (rit);}
			const_reverse_iterator	rbegin() const {const_reverse_iterator crit(end()); return (crit);}

			reverse_iterator		rend(){reverse_iterator rit(begin()); return (rit);}
			const_reverse_iterator	rend() const {const_reverse_iterator crit(begin()); return (crit);}

			//member functions: capacity
			size_type	size(){return this->_size;}

			size_type	max_size(){return this->_alloct.max_size();}

			void		resize(size_type n, value_type val = value_type()){//la capacité sera de taille différente
				if (n < this->capacity() * 2 && n > this->capacity())
					this->reserve(this->capacity() * 2);
				else if (n > this->capacity())
					this->reserve(n);
				while (this->_size > n){
					this->_alloct.destroy(&(this->_data[this->_size - 1]));
					this->_size--;
				}
				while (n > this->_size){
					this->_alloct.construct(&this->_data[this->_size], val);
					this->_size++;
				}
			}

			size_type	capacity() const{return this->_capacity;}

			bool		empty() const{
				if (this->_size == 0)
					return (true);
				return (false);
			}

			void		reserve(size_type n){
				if (this->_capacity >= n)
					return ;
				value_type	tmp[this->_size];
				for (size_type i = 0; i < this->_size; i++)
					tmp[i] = this->_data[i];
				if (this->_size != 0)
					for (size_type i = 0; i < this->_size; i++)
						this->_alloct.destroy(&(this->_data[i]));
				if (this->_data != NULL){
					this->_alloct.deallocate(this->_data, this->_size);
					this->_data = NULL;
				}
				this->_capacity = n;
				this->_data = this->_alloct.allocate(this->_capacity);
				for (size_type i = 0; i < this->_size; i++)
					this->_alloct.construct(&this->_data[i], tmp[i]);
			}

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

			reference		front(){return (*this->_data);}
			const_reference	front() const{return (*this->_data);}

			reference		back(){return (*(this->_data + this->_size - 1));}
			const_reference	back() const{return (*(this->_data + this->_size - 1));}

			value_type			*data(){return (this->_data);};
			value_type const	*data() const{return (this->_data);};

			

			//member functions: modifiers
			template<class InputIterator>
			void	assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0){
				size_type n = (size_type)(last - first);
				if (n > this->_capacity)
					this->reserve(n);
				this->erase(this->begin(), this->end());
				this->_size = (size_type)(last - first);
				for (size_type i = 0; i < this->_size; i++){
					this->_alloct.construct(&this->_data[i], *first);
					first++;
				}
			}
			void	assign(size_type n, const value_type & val){
				if (n > this->_capacity)
					this->reserve(n);
				this->erase(this->begin(), this->end());
				for (size_type i = 0; i < n; i++)
					this->_alloct.construct(&this->_data[i], val);
				this->_size = n;
			}

			void	push_back(const value_type & val){
				if (this->_size + 1 > this->_capacity){
					value_type	*tmp;

					tmp = this->_data;
					if (this->_size != 0)
						for (size_type i = 0 ; i > this->_size; i++)
							this->_alloct.destroy(&(this->_data[i]));
					if (this->_data != NULL){
						this->_alloct.deallocate(this->_data, this->_size);
						this->_data = NULL;
					}
					this->_capacity += 10;
					this->_data = this->_alloct.allocate(this->_capacity);
					for (size_type i = 0; i < this->_size; i++)
						this->_alloct.construct(&this->_data[i], tmp[i]);
				}
				this->_alloct.construct(&this->_data[this->_size], val);
				this->_size++;
			}

			void	pop_back(){
				if (this->_size < 1)
					return ;
				this->_alloct.destroy(&this->_data[this->_size - 1]);
				this->_size--;
			}

			iterator	insert(iterator position, const value_type & val){
				// std::cout << "in insert\n";//
				if (this->_size + 1 > this->_capacity){
					value_type	*tmp;

					tmp = this->_data;
					if (this->_size != 0)
						for (size_type i = 0; i < this->_size; i++)
							this->_alloct.destroy(&(this->_data[i]));
					if (this->_data != NULL){
						this->_alloct.deallocate(this->_data, this->_size);
						this->_data = NULL;
					}
					this->_capacity += 10;
					this->_data = this->_alloct.allocate(this->_capacity);
					for (size_type i = 0; i < this->_size; i++)
						this->_alloct.construct(&this->_data[i], tmp[i]);
				}
				// display();//
				this->_size++;
				size_type start = position - this->begin();
				this->_alloct.construct(&this->_data[this->_size - 1], val);
				if (start == 0){
					for (size_type i = this->_size - 1; i > start; i--)
						this->_data[i + 1] = this->_data[i];
					this->_data[1] = this->_data[0];
				}
				else
					for (size_type i = this->_size - 1; i > start - 1; i--)
						this->_data[i + 1] = this->_data[i];
				// display();//
				this->_data[start] = val;
				return (position);
			}
			void		insert(iterator position, size_type n, const value_type & val){
				for (size_type i = 0; i < n; i++)
					this->insert(position, val);
			}
			template <class InputIterator>
			void		insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0){
				size_type nb_elem = (size_type)(last - first);
				for (size_type i = 0; i < nb_elem; i++)
					this->insert(position, *(last--));
			}

			iterator	erase(iterator position){
				for (size_type i = position - this->begin(); i < this->_size - 1; i++)
					this->_data[i] = this->_data[i + 1];
				this->_size--;
				this->_alloct.destroy(&(this->_data[this->_size]));
				return (position);
			}
			iterator	erase(iterator first, iterator last){
				size_type max = (size_type)(last - first);
				for (size_type i = 0; i < max; i++){
					erase(first);
				}
				return (first);
			}

			void	swap(vector& x){
				std::swap(this->_alloct, x._alloct);
				std::swap(this->_size, x._size);
				std::swap(this->_capacity, x._capacity);
				std::swap(this->_data, x._data);
			}

			void	clear(){
				if (this->_size != 0)
					for (size_type i = 0 ; i > this->_size; i++)
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
			// void	display(){
			// 	for (size_type i = 0; i < this->_size; i++){
			// 		std::cout << this->_data[i];
			// 		if (i != this->_size - 1)
			// 		std::cout << " - ";
			// 	}
			// 	std::cout << std::endl;
			// }

	};
	//non-member functions overloads
	template <class T, class Alloc>
	bool	operator==(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs){
		if (lhs.size() != rhs.size())
			return (false);
		for (size_t i = 0; i < lhs.size(); i++)
			if (lhs[i] != rhs[i])
				return (false);
		return (true);
	}
	template <class T, class Alloc>
	bool	operator!=(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs){return (!(lhs == rhs));}
	template <class T, class Alloc>
	bool	operator<(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs){
		return (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	template <class T, class Alloc>
	bool	operator<=(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs){return ((lhs == rhs) || (lhs < rhs));}
	template <class T, class Alloc>
	bool	operator>(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs){return (!(lhs <= rhs));}
	template <class T, class Alloc>
	bool	operator>=(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs){return (!(lhs < rhs));}
	template <class T, class Alloc>
	void	swap(vector<T, Alloc> & x, vector<T, Alloc> & y){x.swap(y);}
}

#endif