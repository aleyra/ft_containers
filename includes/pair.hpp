#ifndef PAIR_H
# define PAIR_H

# include <iostream>

namespace ft{
	template <class T1, class T2>
	struct pair{
		//Member typedef
		typedef T1	first_type;
		typedef T2	second_type;

		//Member attributs
		T1	first;
		T2	second;

		//Member functions
		pair(){}
		template <class U, class V>
		pair(const pair<U,V> & src):first(src.first), second(src.second){}
		pair(const first_type & a, const second_type & b):first(a), second(b){}

		pair & operator=(const pair & src){
			this->first = src.first;
			this->second = src.second;
			return *this;
		}
	};
	//Non-member functions
	template <class T1, class T2>
	bool	operator==(const pair<T1,T2> & lhs, const pair<T1,T2> & rhs){
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
	bool	operator!=(const pair<T1,T2> & lhs, const pair<T1,T2> & rhs){
		return (!(lhs == rhs));
	}

	template <class T1, class T2>
	bool	operator<(const pair<T1,T2> & lhs, const pair<T1,T2> & rhs){
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template <class T1, class T2>
	bool	operator<=(const pair<T1,T2> & lhs, const pair<T1,T2> & rhs){
		return (!(rhs < lhs));
	}

	template <class T1, class T2>
	bool	operator>(const pair<T1,T2> & lhs, const pair<T1,T2> & rhs){
		return (rhs < lhs);
	}

	template <class T1, class T2>
	bool	operator>=(const pair<T1,T2> & lhs, const pair<T1,T2> & rhs){
		return (!(lhs < rhs));
	}
}

#endif