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
			typedef Iter	iterator_type;
			typedef ft::iterator_traits<Iter>::iterator_category	iterator_category;
			typedef ft::iterator_traits<Iter>::value_type			value_type;
			typedef ft::iterator_traits<Iter>::difference_type		difference_type;
			typedef ft::iterator_traits<Iter>::pointer				pointer;
			typedef ft::iterator_traits<Iter>::reference			reference;

			//member functions : canonical form
			reverse_iterator(){}
			template <class Iter2>
			reverse_iterator(const reverse_iterator<Iter2> & src){*this = src;}//a ameliorer
			virtual ~reverse_iterator(){}

			template <class Iter2>
			reverse_iterator &	operator=(reverse_iterator<Iter2> const & src){
				//incomplet
				return (*this);
			}

			//member functions: others
			/* explicit */ reverse_iterator(iterator_type it){}
			iterator_type		base() const{}//return reverse de reverse_iterator donc juste Iter ?
			reference			operator*() const{return (this->reference);}
			reverse_iterator	operator+(difference_type n) const{}//?
			reverse_iterator &	operator++(){}//?
			reverse_iterator	operator++(int){}//?
			

		protected:

		private:

	};
}

#endif