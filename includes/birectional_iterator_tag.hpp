#ifndef BIDIRECTIONAL_ITERATOR_TAG_H
# define BIDIRECTIONAL_ITERATOR_TAG_H

# include "iterators_traits.hpp"
# include <iostream>
# include <iterator>

namespace ft{
	struct bidirectional_iterator_tag: public std::forward_iterator_tag {
	private:
		typedef	value_type;//?
		typedef	pointer;//?
		typedef	reference;//?
	
	protected:
		current;//?

	public:
		bidirectional_iterator_tag(){};
		bidirectional_iterator_tag(bidirectional_iterator_tag const & src){};//?
		virtual ~bidirectional_iterator_tag(){};
		bidirectional_iterator_tag & operator=(bidirectional_iterator_tag const & src){};//?

		bool		operator==(bidirectional_iterator_tag &other){};//?
		bool		operator!=(bidirectional_iterator_tag &other){};//?
		value_type	&operator*(){};//?
		pointer		&operator->(){return (&(this->operator*()));};//?

		bidirectional_iterator_tag &	operator++(){
			// ++current;
			return (*this);
		}//?
		bidirectional_iterator_tag	operator++(int){
			bidirectional_iterator_tag tmp = *this;
			++(*this);
			return (tmp);
		}//?

		bidirectional_iterator_tag &	operator--(){
			// --current;
			return (*this);
		}//?
		bidirectional_iterator_tag	operator--(int){
			bidirectional_iterator_tag tmp = *this;
			++(*this);
			return (tmp);
		}//?


	};
}

#endif