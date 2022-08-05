#ifndef VECTOR_H
# define VECTOR_H

# include <iostream>
# include "reverse_iterator.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "equal.hpp"
# include <algorithm>

namespace ft{
	template <typename T, class Alloc = std::allocator<T> >
	class vector{
		#pragma region Member attibuts
		public:
			//member attributs // typedef everywhere to make reading-friendly
			typedef T														value_type;
			typedef Alloc													allocator_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef pointer													iterator;
			typedef const_pointer											const_iterator;
			typedef ft::reverse_iterator<iterator>							reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef	typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef std::size_t												size_type;
		private:
			allocator_type	_alloct;
			size_type		_capacity;//>= nb d'elem
			pointer			_data;//le tab
			size_type		_size;//nb d'elem
		#pragma endregion Member attibuts

		#pragma region Canonical Form
		private:
			// vector():_alloct(allocator_type()), _capacity(0), _data(pointer()), _size(0){}
		public:	
			vector(const vector & src){*this = src;}
			virtual ~vector(){this->clear();}

			vector &	operator=(const vector & src){
				this->_alloct = src._alloct;
				this->reserve(src._size);
				this->assign(src.begin(), src.end());
				return (*this);
			}
		#pragma endregion Canonical Form
		
		#pragma region Member functions : Other constructors
			explicit	vector(const allocator_type & alloc = allocator_type()):_alloct(alloc), _capacity(0), _data(pointer()), _size(0){}
			explicit	vector(size_type n, const value_type & val = value_type(), const allocator_type & alloc = allocator_type()): _alloct(alloc), _data(pointer()), _size(0), _capacity(0){
				this->assign(n, val);
			}
			template<class InputIterator>
			explicit vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
				: _alloct(alloc), _data(pointer()), _size(0), _capacity(0){
				this->assign(first, last);
			}
		#pragma endregion Member functions : Other constructors

		#pragma region Member functions : iterators
			iterator		begin(){return (this->_data);}//_data est un pointer et iterator est aussi un pointer
			const_iterator	begin() const {return (const_iterator)this->_data;}

			iterator		end(){return (this->_data + this->_size);}
			const_iterator	end() const {return (const_iterator)(this->_data + this->_size);}

			reverse_iterator		rbegin(){return reverse_iterator(this->end());}
			const_reverse_iterator	rbegin() const {return ((const_reverse_iterator)this->end());}

			reverse_iterator		rend(){return reverse_iterator(this->begin());}
			const_reverse_iterator	rend() const {return (const_reverse_iterator)this->begin();}
		#pragma endregion Member functions : iterators
		
		#pragma region Member functions : capacity
			size_type	size() const{return this->_size;}

			size_type	max_size() const{return (std::min(_alloct.max_size(), static_cast<size_type>(std::numeric_limits<difference_type>::max())));}//securité dans le cas ou le difference_type pointe sur un type particulierement petit comme un char

			void		resize(size_type n, value_type val = value_type()){//la capacité sera de taille différente
				if (n > this->_size)
					this->insert(this->end(), n - this->_size, val);
				else
					this->destroy_from(this->_data + n);
			}

			size_type	capacity() const{return this->_capacity;}

			bool		empty() const{
				if (this->_size == 0)
					return (true);
				return (false);
			}

			void		reserve(size_type n){
				if (n == 0 || this->_capacity >= n)
					return ;
				this->check_max_length(n);
				pointer	tmp = this->allocate(n);
				for (size_type i = 0; i < this->_size; i++){
					this->_alloct.construct(&tmp[i], this->_data[i]);
					this->_alloct.destroy(&(this->_data[i]));
				}
				this->deallocate(this->_data, this->_capacity);
				this->_data = tmp;
				this->_capacity = n;
			}
		#pragma endregion Member functions : capacity

		#pragma region Member functions : element access
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

			reference		back(){return (*(this.end() - 1));}
			const_reference	back() const{return (*(this.end() - 1));}

			value_type			*data(){return (this->_data);};
			value_type const	*data() const{return (this->_data);};
		#pragma endregion Member functions : element access

		#pragma region Member functions : modifiers
			template<class InputIterator>
			void	assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0){
				this->clear();//en premier pour que reserve ne copie rien
				for (; first != last; ++first){
					this->push_back(*first);
				}
			}
			void	assign(size_type n, const value_type & val){
				this->clear();
				this->reserve(n);
				for (size_type i = 0; i < n; i++)
					this->_alloct.construct(&this->_data[i], val);
				this->_size = n;
			}

			void	push_back(const value_type & val){
				if (this->_size == this->_capacity){
					this->extend();
				}
				this->unchecked_push_back(val);//appel de cette fct pour plus de lisibilité
			}

			void	pop_back(){
				this->_size--;
				this->_alloct.destroy(&this->_data[this->_size]);
			}

			iterator	insert(iterator position, const value_type & val){
				size_type	i = position - this->_data;
				if (position == this->end())
					this->push_back(val);
				else
					this->insert(position, 1, val);
				return (iterator(&(this->_data[i])));
			}
			void		insert(iterator position, size_type n, const value_type & val){
				size_type	i = position - this->_data;

				this->reserve(this->_size + n);
				iterator	src = this->end() - 1;
				iterator	dest = src + n;
				for (; src >= &(this->_data[i]); src--, dest--){//for avec 2 compteurs !!!
					this->_alloct.construct(dest, *src);
					this->_alloct.destroy(src);
				}
				src++;
				for (size_type i = 0; i < n; i++, src++){
					this->_alloct.construct(src, val);
				}
				this->_size += n;
			}
			template <class InputIterator>
			void		insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0){
				size_type	i = position - this->_data;
				size_type	d = std::distance(first, last);

				this->reserve(this->_size + d);
				for (size_type j = 0; j < d; j++){//d'abord on prevoit la place pour les elem de la range
					this->_alloct.construct(&(this->_data[this->_size + j]), *first);
				}
				for (difference_type j = this->_size - 1; i >= 0 && i >= (difference_type)i; --j){//on decale
					this->_data[j + d] = this->_data[i];
				}
				for (size_type j = i; j < i + d; j++, first++){//on assigne les bonnes valeurs de la range au bon endroit
					this->_data[j] = *first;
				}
				this->_size = d;
			}

			iterator	erase(iterator position){
				if (position + 1 != this->end()){//on decale
					std::copy(position + 1, this.end(), position);
				}
				this->_size--;
				this->_alloct.destroy(&(this->_data[this->_size]));
				return (position);
			}
			iterator	erase(iterator first, iterator last){
				if (first != last){
					if (last != this.end()){
						std::copy(last, this.end(), first);
					}
					this->destroy_from(first + (this.end() - last));
				}
				return first;
			}

			void	swap(vector& x){
				std::swap(this->_alloct, x._alloct);
				std::swap(this->_size, x._size);
				std::swap(this->_capacity, x._capacity);
				std::swap(this->_data, x._data);
			}

			void	clear(){
				if (this->_size == 0)
					return ;
				for (size_type i = 0; i < this->_size; i++){
					this->_alloct.destroy(&(this->_data[i]));
				}
				this->_size = 0;
			}
		#pragma endregion Member functions : modifiers
			//member functions: allocator
			allocator_type get_alloct() const{return (this->_alloct);}
			
		protected:

		#pragma region Tools
		private:
		void check_max_length(size_type n) const{
			if (n > this->max_size())
				throw std::length_error("attempt to create ft::vector with a size exceeding max_size()");
		}

		pointer allocate(size_type n){
			if (n == 0) {
				return pointer();
			}
			pointer tmp = this->_alloct.allocate(n);
			return tmp;
		}

		void deallocate(pointer p, size_type n){
			if (p != NULL) {
				_alloct.deallocate(p, n);
			}
		}

		void destroy_from(iterator it){
			iterator tmp = it;
			while (it != this->end()) {
				_alloct.destroy(it++);
			}
			this->_size = tmp - this->_data;
		}

		void extend(){
			if (this->_capacity == 0){
				this->reserve(1);
				return;
			}
			if (this->_capacity * 2 > this->max_size() && this->_capacity + 1 <= this->max_size()){
				this->reserve(this->max_size());
				return ;
			}
			else if (this->_capacity == this->max_size())
				throw std::length_error("Cannot extend past max_size()");
			this->reserve(_capacity * 2);
		}

		void unchecked_push_back(const_reference value){//suppose que la capacity a deja été check !!!
			_alloct.construct(_data + _size++, value);
		}

		#pragma endregion Tools
	};
	//non-member functions overloads
	template <class T, class Alloc>
	bool	operator==(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs){
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
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