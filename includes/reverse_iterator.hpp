#ifndef REVERSE_ITERATOR_H
# define REVERSE_ITERATOR_H

# include <iostream>
# include <iterator>
# include "iterators_traits.hpp"

namespace ft{
	template <class Iter>
	class reverse_iterator{
		public:
			//member attributs
			typedef Iter													iterator_type;
			typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iter>::value_type			value_type;
			typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iter>::pointer				pointer;
			typedef typename ft::iterator_traits<Iter>::reference			reference;

		protected:
			iterator_type	current;
		
		public:
			//member functions : canonical form
			explicit reverse_iterator(iterator_type it):current(it){}
			//explicit so it can't be used for implicit conversion or copy-initialization
			template <class Iter2>
			reverse_iterator(const reverse_iterator<Iter2> & src) :current(src.base()){}
			virtual ~reverse_iterator(){}

			template <class Iter2>
			reverse_iterator &	operator=(reverse_iterator<Iter2> const & src){
				this->current = src.current;
				return (*this);
			}

			//member functions: others
			iterator_type		base() const{return (current);}
			
			reference			operator*() const{
				iterator_type	tmp = current;
				--tmp;
				return(*tmp);
			}
			
			reverse_iterator	operator+(difference_type n){
				iterator_type	tmp = this->base();
				tmp = tmp - n;
				return (tmp);
			}
			
			reverse_iterator &	operator++(){
				--current;
				return (*this);
			}
			reverse_iterator	operator++(int){
				reverse_iterator tmp = *this;
				++(*this);
				return (tmp);
			}
			
			reverse_iterator &	operator+=(difference_type n){
				current = current - n;
				return (*this);
			}

			reverse_iterator	operator-(difference_type n){
				// iterator_type	tmp = this->base();
				// tmp = tmp + n;
				return ((reverse_iterator)(this->base() - n));
			}

			reverse_iterator &	operator--(){
				++current;
				return (*this);
			}
			reverse_iterator	operator--(int){
				reverse_iterator tmp = *this;
				--(*this);
				return (tmp);
			}

			reverse_iterator &	operator-=(difference_type n){
				current = current + n;
				return (*this);
			}

			pointer				operator->() const{
				return (&(this->operator*()));
			}

			reference			operator[](difference_type n) const{
				return (current[-n - 1]);
			}


		private:

	};

	//non-member functions overloads
	template <class Iter>
	bool	operator==(const reverse_iterator<Iter>& lhs,
						const reverse_iterator<Iter>& rhs){
		return (lhs.base() == rhs.base());
	}
	
	template <class Iter>
	bool	operator!=(const reverse_iterator<Iter>& lhs,
						const reverse_iterator<Iter>& rhs){
		return (lhs.base() != rhs.base());
	}

	template <class Iter>
	bool	operator<(const reverse_iterator<Iter>& lhs,
						const reverse_iterator<Iter>& rhs){
		return (lhs.base() > rhs.base());
	}

	template <class Iter>
	bool	operator<=(const reverse_iterator<Iter>& lhs,
						const reverse_iterator<Iter>& rhs){
		return (lhs.base() >= rhs.base());
	}

	template <class Iter>
	bool	operator>(const reverse_iterator<Iter>& lhs,
						const reverse_iterator<Iter>& rhs){
		return (lhs.base() < rhs.base());
	}

	template <class Iter>
	bool	operator>=(const reverse_iterator<Iter>& lhs,
						const reverse_iterator<Iter>& rhs){
		return (lhs.base() <= rhs.base());
	}

	template <class Iter>
	reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n,
             							const reverse_iterator<Iter> & rev_it){
		return (rev_it + n);
	}

	template <class Iter>
	typename reverse_iterator<Iter>::difference_type operator-(const reverse_iterator<Iter> & lhs,
    															const reverse_iterator<Iter> & rhs){
		return (rhs.base() - lhs.base());
	}
}

#endif