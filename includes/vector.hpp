#ifndef VECTOR_H
# define VECTOR_H

# include <iostream>
# include "reverse_iterator.hpp"

namespace ft{
	template <typename T, class Alloc = std::allocator<T> >
	class vector{
		public:
			//member attributs // typedef everywhere to make reading-friendly
			typedef T										value_type;
			typedef Alloc									allocator_type;
			typedef allocator_type::reference				reference;
			typedef allocator_type::const_reference			const_reference;
			typedef allocator_type::pointer					pointer;
			typedef allocator_type::const_pointer			const_pointer;
			typedef pointer									iterator;
			typedef const_pointer							const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

			//member functions : canonical form
			vector(){}
			vector(const vector & src){}
			virtual ~vector(){}

			vector &	operator=(const vector & src){
				return (*this);
			}

			//member functions: others
			
		protected:

		private:

	};
}

#endif