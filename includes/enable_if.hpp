#ifndef ENABLE_IF_H
# define ENABLE_IF_H

namespace ft{
	template<bool Cond, class T = void>
	struct enable_if{};

	template<class T>
	struct enable_if<true, T>{
		typedef T type;
	};
	//version de Mhaman
	// template <bool B>
	// struct enable_if {};

	// template <>
	// struct enable_if<true> { typedef int type; };
}

#endif