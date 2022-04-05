#ifndef MAKE_PAIR_H
# define MAKE_PAIR_H

# include "pair.hpp"

namespace ft{
	template <class T1, class T2>
	pair<T1, T2>	make_pair(T1 x, T2 y){
		return (pair<T1, T2>(x, y));
	}
}
#endif